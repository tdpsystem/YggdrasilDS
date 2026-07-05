# File_Format_Spec

## Yggdrasil Saga

Version: 1.0

Purpose:
Define all game data formats used by Yggdrasil Saga.

This document serves as the technical reference for save data, game databases, assets, and runtime structures.

---

# General Standards

Encoding:
UTF-8

Line Endings:
LF

Naming Convention:
snake_case

Examples:

```text id="dl2yyl"
player_data.dat
enemy_database.dat
midgard_map.bin
```

File Extensions:

| Type          | Extension |
|---------------|-----------|
| Source Code   | .cpp / .h |
| Maps          | .map      |
| Events        | .evt      |
| Save Files    | .sav      |
| Sprites       | .png      |
| Audio         | .wav      |
| Music         | .mod      |
| Configuration | .cfg      |
| Databases     | .dat      |

---

# Save File Format

File:

```text id="z0kxtq"
save_slot_01.sav
```

Structure:

```text id="jlwmq7"
SaveData
{
    Header
    PlayerData
    PartyData
    InventoryData
    QuestData
    WorldData
    EventFlags
}
```

Maximum Save Slots:
3

Maximum Save Size:
64 KB

---

# Header Format

```text id="h9gwg8"
Header
{
    Version
    PlayTime
    Timestamp
}
```

Fields:

| Field     | Type   |
|-----------|--------|
| Version   | uint16 |
| PlayTime  | uint32 |
| Timestamp | uint64 |

---

# Player Data Format

```text id="7v9miy"
PlayerData
{
    Name
    Class
    Level
    Experience
    Gold
}
```

Fields:

| Field      | Type       |
|------------|------------|
| Name       | string[16] |
| Class      | uint8      |
| Level      | uint8      |
| Experience | uint32     |
| Gold       | uint32     |

---

# Party Data Format

Maximum Party Members:

```text id="vjkvx8"
4 active
```

Structure:

```text id="azvmbw"
PartyMember
{
    CharacterID
    Level
    HP
    MP
    Equipment
}
```

---

# Inventory Format

Maximum Items:

```text id="08vqhl"
999
```

Structure:

```text id="zv1rw6"
InventoryEntry
{
    ItemID
    Quantity
}
```

Fields:

| Field    | Type   |
|----------|--------|
| ItemID   | uint16 |
| Quantity | uint16 |

---

# Equipment Format

Structure:

```text id="7v7t7x"
Equipment
{
    Weapon
    Armor
    Accessory
}
```

Fields:

| Field     | Type   |
|-----------|--------|
| Weapon    | uint16 |
| Armor     | uint16 |
| Accessory | uint16 |

---

# Quest Format

Structure:

```text id="zgf4dd"
QuestEntry
{
    QuestID
    Status
}
```

Status Values:

| Value | Meaning  |
|-------|----------|
| 0     | Locked   |
| 1     | Active   |
| 2     | Complete |

---

# Event Flag Format

Structure:

```text id="9m2fkn"
EventFlags[2048]
```

Type:

```text id="ly31rx"
bool
```

Examples:

```text id="t30jff"
FLAG_ASTRID_JOINED
FLAG_RUNE_LIGHT_OBTAINED
FLAG_MIDGARD_COMPLETE
FLAG_LOKI_REVEALED
```

---

# Character Database Format

File:

```text id="w0m7q8"
character_database.dat
```

Structure:

```text id="gn79e4"
Character
{
    ID
    Name
    Class
    BaseStats
    GrowthRates
}
```

---

# Enemy Database Format

File:

```text id="t2hl4n"
enemy_database.dat
```

Structure:

```text id="f51h5z"
Enemy
{
    ID
    Name
    Level
    Stats
    Skills
    Drops
}
```

Fields:

| Field   | Type   |
|---------|--------|
| ID      | uint16 |
| Name    | string |
| Level   | uint8  |
| HP      | uint16 |
| MP      | uint16 |
| Attack  | uint16 |
| Defense | uint16 |

---

# Item Database Format

File:

```text id="w7kly6"
item_database.dat
```

Structure:

```text id="32qbxn"
Item
{
    ID
    Name
    Type
    Value
    Description
}
```

Item Types:

| Value | Type       |
|-------|------------|
| 0     | Consumable |
| 1     | Key Item   |
| 2     | Material   |
| 3     | Quest Item |

---

# Equipment Database Format

File:

```text id="v7snv0"
equipment_database.dat
```

Structure:

```text id="06zxfk"
Equipment
{
    ID
    Name
    Slot
    Stats
}
```

Slots:

| Value | Slot      |
|-------|-----------|
| 0     | Weapon    |
| 1     | Armor     |
| 2     | Accessory |

---

# Map Format

File:

```text id="5m5wki"
midgard_map.map
```

Structure:

```text id="yysjlwm"
Map
{
    Header
    Tiles
    Collision
    Events
    NPCs
}
```

Components:

* Tile Layer
* Collision Layer
* Event Layer
* NPC Layer

---

# Event Script Format

File:

```text id="5stewi"
midgard_events.evt
```

Example:

```text id="j9y5a8"
SHOW_DIALOGUE 100
MOVE_NPC 3 NORTH
PLAY_MUSIC 5
SET_FLAG FLAG_ASTRID_JOINED
```

Supported Commands:

```text id="ydvf2w"
SHOW_DIALOGUE
PLAY_MUSIC
PLAY_SFX
MOVE_NPC
SPAWN_NPC
SET_FLAG
CLEAR_FLAG
START_BATTLE
START_CUTSCENE
CHANGE_MAP
GIVE_ITEM
```

---

# Audio Format

Sound Effects:

```text id="5zlfci"
.wav
```

Music:

```text id="wvhbvh"
.mod
```

Target Sample Rate:

```text id="4o8zry"
22050 Hz
```

---

# Sprite Format

File Type:

```text id="tdq51q"
.png
```

Player Sprite:

```text id="vtx73n"
32x32
```

NPC Sprite:

```text id="14x5b2"
32x32
```

Enemy Sprite:

```text id="b3i7hq"
64x64
```

Boss Sprite:

```text id="f4y5wo"
128x128
```

---

# Version Compatibility

Save files contain:

```text id="56g7wh"
Version Number
```

When loading:

1. Check version.
2. Validate structure.
3. Load compatible data.
4. Reject unsupported versions.

---

# Future Expansion Rules

New systems must:

* Maintain backward save compatibility.
* Use unique IDs.
* Avoid changing existing data structures.
* Increment version number when format changes.

---

# Technical Limits

| System                | Limit       |
|-----------------------|-------------|
| Save Slots            | 3           |
| Party Members         | 4 Active    |
| Inventory Size        | 999 Entries |
| Event Flags           | 2048        |
| Quests                | 512         |
| NPCs Per Map          | 64          |
| Enemies Per Encounter | 8           |
| Character Levels      | 99          |

---

End of File
