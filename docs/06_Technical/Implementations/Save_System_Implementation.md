# Save_System_Implementation

## Yggdrasil Saga

Version: 1.1

Purpose:

Define how save files are created, validated, loaded, protected, and upgraded for the Nintendo DS implementation of
Yggdrasil Saga.

This system uses traditional permanent save points and a single-use quick save system. There is no autosave.

---

# Save Overview

Permanent Save Slots:

```text
3
```

Quick Save Slots:

```text
1
```

Maximum Save Size Per Slot:

```text
64 KB
```

Save Location:

```text
Cartridge SRAM / Emulator Save File
```

---

# Save Types

## Manual Save

Manual save is the main permanent save method.

The player may save at:

* Yggdrasil Sanctuary
* Town inns
* Norn Shrines
* World hub save points
* Pre-boss save points

Narrative framing:

```text
Commune with the Norns
```

Design reference:

```text
Dragon Quest IX confession-style saving
```

Manual saves are permanent and remain available after loading.

---

## Quick Save

Quick save is a temporary suspend save.

Purpose:

```text
Allow the player to stop playing and resume later.
```

Only one quick save may exist at a time.

When the player creates a quick save:

```text
Create Quick Save
  │
  ▼
Return To Title Screen
```

When the player loads a quick save:

```text
Load Quick Save
  │
  ▼
Delete Quick Save
  │
  ▼
Resume Game
```

Quick saves are not permanent save slots.

---

# Save File Naming

Permanent Saves:

```text
save_slot_01.sav
save_slot_02.sav
save_slot_03.sav
```

Quick Save:

```text
quicksave.sav
```

Backup Files:

```text
save_slot_01.bak
save_slot_02.bak
save_slot_03.bak
quicksave.bak
```

---

# Save Data Layout

```text
SaveData
│
├── Header
├── PlayerData
├── PartyData
├── InventoryData
├── EquipmentData
├── QuestData
├── WorldData
├── EventFlags
├── SystemData
└── Checksum
```

---

# Header

```text
Header
{
    magic
    version
    save_type
    slot_id
    play_time
    timestamp
}
```

Fields:

| Field     | Type    | Notes                       |
|-----------|---------|-----------------------------|
| magic     | char[4] | YGSV                        |
| version   | uint16  | Save format version         |
| save_type | uint8   | 0 = manual, 1 = quick       |
| slot_id   | uint8   | 1–3 for manual, 0 for quick |
| play_time | uint32  | Seconds played              |
| timestamp | uint64  | Last saved time             |

---

# Player Data

```text
PlayerData
{
    name
    class_id
    level
    experience
    gold
    current_hp
    current_mp
}
```

Limits:

| Field      | Limit         |
|------------|---------------|
| Name       | 16 characters |
| Level      | 99            |
| Gold       | 999999        |
| Experience | uint32 max    |

---

# Party Data

Maximum Party Members Stored:

```text
5
```

Maximum Active Party Members:

```text
4
```

Stored Members:

```text
Hero
Astrid
Eirik
Thora Ironhand
Thrym
```

Each Party Member:

```text
PartyMember
{
    character_id
    unlocked
    active
    class_id
    level
    experience
    current_hp
    current_mp
    equipment
    learned_skills
}
```

---

# Inventory Data

Maximum Inventory Entries:

```text
999
```

Each Entry:

```text
InventoryEntry
{
    item_id
    quantity
}
```

Maximum Quantity Per Item:

```text
99
```

Key items must always use:

```text
quantity = 1
```

---

# Equipment Data

```text
Equipment
{
    weapon_id
    armor_id
    accessory_id
}
```

Invalid equipment IDs must be replaced with:

```text
0
```

Where:

```text
0 = None
```

---

# Quest Data

Quest States:

| Value | State    |
|-------|----------|
| 0     | Locked   |
| 1     | Active   |
| 2     | Complete |
| 3     | Failed   |

Each Quest:

```text
QuestEntry
{
    quest_id
    state
    progress_value
}
```

---

# World Data

```text
WorldData
{
    current_realm
    current_map
    player_x
    player_y
    facing_direction
    yggdrasil_stability
}
```

Realm IDs:

| ID | Realm        |
|----|--------------|
| 1  | Midgard      |
| 2  | Alfheim      |
| 3  | Svartalfheim |
| 4  | Vanaheim     |
| 5  | Jötunheim    |
| 6  | Niflheim     |
| 7  | Muspelheim   |
| 8  | Asgard       |
| 9  | Helheim      |
| 10 | Yggdrasil    |

---

# Event Flags

Total Flags:

```text
2048
```

Stored As:

```text
bitfield
```

Examples:

```text
FLAG_ASTRID_JOINED
FLAG_RUNE_LIGHT_OBTAINED
FLAG_MIDGARD_COMPLETE
FLAG_LOKI_REVEALED
FLAG_FINAL_CHOICE_MADE
```

---

# System Data

```text
SystemData
{
    text_speed
    battle_speed
    music_volume
    sfx_volume
    button_config
}
```

Settings may be copied between save files if needed.

---

# Checksum

Checksum Type:

```text
CRC32
```

Checksum covers:

```text
Header through SystemData
```

Checksum does not cover:

```text
Checksum field itself
```

---

# Manual Save Process

```text
Open Save Point
  │
  ▼
Choose Save Slot
  │
  ▼
Confirm Save
  │
  ▼
Build SaveData In Memory
  │
  ▼
Validate SaveData
  │
  ▼
Calculate CRC32
  │
  ▼
Write Backup
  │
  ▼
Write Main Save
  │
  ▼
Read Back Save
  │
  ▼
Verify Checksum
  │
  ▼
Confirm Save Complete
```

---

# Quick Save Process

```text
Open Menu
  │
  ▼
Choose Quick Save
  │
  ▼
Confirm Suspend Save
  │
  ▼
Build SaveData In Memory
  │
  ▼
Write quicksave.sav
  │
  ▼
Verify Checksum
  │
  ▼
Return To Title Screen
```

---

# Load Process

```text
Begin Load
  │
  ▼
Read Header
  │
  ▼
Check Magic
  │
  ▼
Check Version
  │
  ▼
Read SaveData
  │
  ▼
Validate Size
  │
  ▼
Verify CRC32
  │
  ▼
Load Into Runtime
  │
  ▼
Start Scene
```

For quick saves:

```text
After successful load:
Delete quicksave.sav
```

---

# Backup Recovery

If main save fails:

```text
Try backup save
```

If backup succeeds:

```text
Restore backup to main slot
```

If both fail:

```text
Mark slot as corrupted
```

Player-facing message:

```text
This save file could not be loaded.
```

---

# Manual Save Rules

Manual saving is allowed at:

* Yggdrasil Sanctuary
* Town inns
* Norn Shrines
* Pre-boss save points
* World hub

Manual saving is disabled during:

* Battles
* Cutscenes
* Dialogue
* Forced movement
* Ending sequences

---

# Quick Save Rules

Quick saving is allowed in:

* Towns
* Dungeons
* Realm field maps
* Yggdrasil hub

Quick saving is disabled during:

* Battles
* Boss rooms
* Cutscenes
* Dialogue
* Scripted movement
* Shops
* Ending sequences
* Final route choice

Quick save must always:

* Use slot_id 0
* Use save_type 1
* Replace any existing quick save
* Return the player to the title screen
* Delete itself after loading

---

# Version Compatibility

Current Version:

```text
1
```

On load:

1. Read save version.
2. Compare against current version.
3. Upgrade older compatible saves.
4. Reject unsupported saves.

Unsupported message:

```text
This save file was created with an unsupported version.
```

---

# Save Upgrade Rules

Allowed:

* Add optional fields.
* Add unused reserved bytes.
* Expand quest list if within size limit.
* Add new flags to unused flag range.

Forbidden:

* Reordering existing fields.
* Changing existing ID meanings.
* Removing required fields.
* Reusing deleted flag IDs.

---

# Validation Rules

Reject save if:

* Magic does not equal YGSV.
* Save type is invalid.
* Manual slot ID is outside 1–3.
* Quick save slot ID is not 0.
* Level is above 99.
* Current realm is invalid.
* Checksum fails.
* File size exceeds 64 KB.

Repair if possible:

* Invalid equipment becomes 0.
* Invalid current HP clamps to max HP.
* Invalid item quantity clamps to 99.
* Invalid volume clamps to valid range.

---

# Developer Debug Saves

Debug builds may support:

```text
debug_save_01.sav
```

Debug save features:

* Start from any realm
* Set party members
* Set runes obtained
* Set current quest
* Toggle event flags

Debug saves must never be enabled in release builds.

---

# Technical Goal

```text
Provide reliable permanent saving and single-use quick saving without autosave.
```

---

End of File
