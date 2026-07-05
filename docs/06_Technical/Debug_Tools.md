# Debug_Tools

## Yggdrasil Saga

Version: 1.0

Purpose:

This document defines internal debug tools for testing, balancing, QA, and milestone validation.

Related Documents:

* Coding_Standards.md
* Build_Process.md
* Event_Flags.md
* Save_System_Implementation.md

---

# Core Rule

```text
Debug Tools Must Never Ship
```

All debug features must be wrapped in:

```c
#ifdef DEBUG
```

Release builds must remove access to debug menus, cheats, test maps, and developer shortcuts.

---

# Debug Menu

Accessible only in debug builds.

Suggested shortcut:

```text
L + R + START
```

Main categories:

```text
Warp
Party
Inventory
Battle
Flags
Story
System
Performance
```

---

# Warp Tools

Allows instant travel to:

* Any realm
* Any town
* Any dungeon
* Any boss room
* Yggdrasil Sanctuary
* Mímir's Well
* Norn Shrine save points

Warp entries must include:

* Map ID
* Spawn point
* Required story state
* Safety flag check

Example:

```c
debug_warp_to(MAP_MANNHEIM, SPAWN_TOWN_ENTRANCE);
```

---

# Party Tools

Allows testers to edit:

* Party members
* Levels
* Class
* HP / MP
* Equipment
* Skills
* Status effects

Final party members:

* Hero
* Astrid
* Eirik
* Thora Ironhand
* Thrym

Restrictions:

* Do not allow invalid empty party states.
* Hero cannot be removed.
* Class changes must use valid unlocked classes unless override mode is enabled.

---

# Inventory Tools

Allows testers to:

* Add items
* Remove items
* Add gold
* Fill consumables
* Add key items
* Add all equipment
* Clear inventory

Key item edits must warn before changing story progression.

Example options:

```text
Add Healing Potion x10
Add 10,000 Gold
Add Current Realm Equipment
Add All Rune Fragments
Clear Inventory
```

---

# Battle Tools

Used for combat testing and balance.

Options:

* Start test battle
* Start current realm boss
* Set enemy group
* Set player level
* Toggle enemy AI
* Force victory
* Force defeat
* Force escape
* Show damage rolls
* Show turn order
* Show status resistance

Boss test list:

```text
Draugr Jarl
Shade Warden
Forgemind Construct
Season Keeper
Thrym
Primordial Wyrm
Surtr
Einherjar Commander
Memory of the Last Hero
Loki
Níðhöggr
```

---

# Flag Editor

Allows viewing and editing event flags.

Flags should be grouped by:

* Story
* Realm
* Party
* Quest
* Dungeon
* Treasure
* System

Rules:

* Show flag name, ID, and value.
* Warn before editing major story flags.
* Allow search by flag name.
* Log all changed flags.

Example:

```text
STORY_MIDGARD_COMPLETE = true
PARTY_ASTRID_JOINED = true
QUEST_BOAR_HUNT_COMPLETE = false
```

---

# Story State Tools

Allows testers to jump to major game states.

Story presets:

* New Game
* Midgard Complete
* Alfheim Complete
* Svartalfheim Complete
* Vanaheim Revelation
* Jötunheim Complete
* Niflheim Complete
* Muspelheim Complete
* Asgard Complete
* Helheim Complete
* Final Dungeon Open
* Preserve Route
* Renew Route
* Renew A Ending
* Renew B Ending

Each preset must:

* Set required flags
* Add required party members
* Add required runes
* Unlock required maps
* Set Tree Stability correctly

---

# Save Tools

Options:

* Validate current save
* Export save data
* Import save data
* Corrupt save test
* Check checksum
* Reset quick save
* Fill all save slots

Save tests must verify:

* Magic number
* Version
* Checksum
* Slot index
* Playtime
* Story flags
* Party data
* Inventory data

---

# Performance Overlay

Displays:

* FPS
* Frame time
* Memory usage
* VRAM usage
* Sprite/OAM count
* Active entities
* Encounter step counter
* Current map ID
* Current script ID

Overlay must be toggleable.

Suggested shortcut:

```text
SELECT + R
```

---

# Collision Viewer

Displays collision and navigation data.

Modes:

* Walkable tiles
* Blocked tiles
* Encounter zones
* Trigger zones
* NPC paths
* Warp zones

Used for:

* Map testing
* Dungeon validation
* Softlock prevention
* NPC path debugging

---

# Event Script Debugger

Features:

* Show current script ID
* Show current command
* Step command
* Pause script
* Resume script
* Skip current cutscene
* Inspect variables
* Inspect flags
* Show blocking command

Rules:

* Script stepping must not corrupt game state.
* Cutscene skip must land in a valid post-cutscene state.
* Blocking commands must timeout in debug builds.

---

# Dialogue Debugger

Options:

* Jump to dialogue ID
* Preview portraits
* Preview text boxes
* Check line length
* Check missing speaker names
* Check missing localization strings

Dialogue validation must flag:

* Overflowing lines
* Missing portraits
* Invalid speaker IDs
* Unclosed control tags
* Missing end markers

---

# Encounter Tools

Options:

* Toggle random encounters
* Force next encounter
* Set encounter table
* Show encounter table
* Show rare spawn chance
* Show elite spawn chance
* Reset step counter

Encounter display example:

```text
Current Table: MIDGARD_IRONWOOD
Step Counter: 17 / 24
Rare Chance: 1%
Elite Chance: 5%
```

---

# Item and Equipment Inspector

Displays:

* Item ID
* Name
* Type
* Price
* Effect
* Equip restrictions
* Stat changes
* Shop availability
* Treasure availability

Used to catch:

* Duplicate IDs
* Invalid prices
* Missing descriptions
* Broken equipment references

---

# Map Inspector

Displays:

* Map ID
* Tileset ID
* Music ID
* Encounter table
* NPC list
* Trigger list
* Warp list
* Treasure list

Validation warnings:

* Missing music
* Missing tileset
* Broken warp
* Unreachable treasure
* Invalid spawn point

---

# Audio Test Menu

Allows testing:

* Music tracks
* Sound effects
* Fanfare
* Ambient loops
* Battle intro
* Victory theme
* Game over theme

Rules:

* Only one music track active at a time.
* Stop all audio before switching banks.
* Log missing audio IDs.

---

# Graphics Test Menu

Allows viewing:

* Tilesets
* Sprites
* Portraits
* Battle backgrounds
* UI windows
* Icons
* Animation frames

Validation should catch:

* Missing frames
* Palette errors
* Oversized sprites
* VRAM overflow risk
* Incorrect transparency

---

# Log System

Debug logs should support categories:

```text
LOG_SYSTEM
LOG_SAVE
LOG_BATTLE
LOG_EVENT
LOG_MAP
LOG_AUDIO
LOG_GRAPHICS
LOG_MEMORY
```

Example:

```c
debug_log(LOG_SAVE, "Save slot %d validated", slot_id);
```

Release builds must remove or disable debug logging.

---

# Crash Screen

Debug builds should show:

* Error type
* File
* Line
* Current map
* Current game state
* Current script
* Last event command
* Stack marker if available

Release builds should show a safe error message or return to title where possible.

---

# Automated Test Hooks

Debug builds should include hooks for:

* Boot test
* Save/load test
* Battle formula test
* Story flag test
* Dialogue overflow test
* Map warp validation
* Treasure reachability test
* Boss start/end test

These hooks support milestone builds.

---

# QA Test Presets

Recommended presets:

```text
MIDGARD_VERTICAL_SLICE
FULL_PARTY_LEVEL_30
FINAL_DUNGEON_READY
ALL_CLASSES_UNLOCKED
ALL_ITEMS_UNLOCKED
BAD_SAVE_TEST
LOW_MEMORY_TEST
```

Each preset should be documented and reproducible.

---

# Forbidden in Release Builds

Release builds must not include:

* Warp menu
* Flag editor
* Item spawner
* Gold editor
* Battle tester
* Story state jumps
* Debug overlays
* Collision viewer
* Script stepper
* Unlocked test maps
* Crash data with sensitive internals

---

# Milestone Validation

Every milestone build should run:

* Boot test
* Title screen test
* Save/load test
* New game test
* Current realm completion test
* Battle smoke test
* Memory check
* Asset missing check

Vertical slice must validate:

* Character creation
* Mannheim Village
* Ironwood route
* Draugr Barrow
* Astrid recruitment
* Draugr Jarl battle
* Rune of Light acquisition
* Return to Yggdrasil
* Manual save/load

---

# Canon Principle

Debug tools are invisible scaffolding.

```text
They exist so the world can feel inevitable.
```

---

End of File
