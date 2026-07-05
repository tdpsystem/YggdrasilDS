# Save_Migration

## Yggdrasil Saga

Version: 1.0

Purpose:

This document defines how save data is migrated between game versions while preserving player progress, preventing
corruption, and maintaining compatibility throughout development.

Related Documents:

* Save_System_Implementation.md
* Save_Data_Structure.md
* Build_Process.md
* Coding_Standards.md

---

# Core Rule

```text
Player Progress Must Never Be Lost
```

If migration is possible, the game must migrate.

If migration is impossible, the save must be safely rejected.

Never silently destroy save data.

---

# Save Versioning

Every save file contains:

```c
typedef struct SaveHeader {
    u32 magic_number;
    u16 save_version;
    u16 checksum;
} SaveHeader;
```

Example:

| Version | Description              |
|---------|--------------------------|
| 100     | Initial Development Save |
| 110     | Inventory Expansion      |
| 120     | Skill System Revision    |
| 130     | Rune Tracking Update     |
| 140     | Release Candidate        |
| 150     | Gold Master              |

---

# Save Compatibility Levels

Three compatibility states exist.

## Fully Compatible

Save loads normally.

```text
Version = Current Version
```

No migration required.

---

## Migratable

Save loads after migration.

```text
Save Version < Current Version
```

Migration routine executes.

---

## Unsupported

Save cannot be safely converted.

Example:

```text
Version 100 → Version 150
```

when required data is missing.

User receives warning.

Save remains untouched.

---

# Save Header Validation

Before migration:

Validate:

* Magic number
* Version
* Checksum
* Slot ID
* File size

Failure:

```text
Migration Aborted
```

Save remains unchanged.

---

# Migration Pipeline

Migration always follows:

```text
Read Save
Validate Save
Backup Save
Run Migration
Validate Migrated Save
Write New Save
Validate New Save
Replace Original Save
```

Never overwrite original data until migration succeeds.

---

# Migration Strategy

All migrations must be incremental.

Example:

```text
Version 110 → 150
```

Becomes:

```text
110 → 120
120 → 130
130 → 140
140 → 150
```

Never skip migration steps.

This ensures predictable behavior.

---

# Migration Function Structure

Example:

```c
ResultCode migrate_110_to_120(SaveData* save);
ResultCode migrate_120_to_130(SaveData* save);
ResultCode migrate_130_to_140(SaveData* save);
```

Master migration:

```c
ResultCode migrate_save(SaveData* save);
```

---

# Migration Requirements

Migration functions must:

* Be deterministic
* Never allocate memory
* Never modify unrelated systems
* Be fully testable
* Produce identical results every run

Migration code must not:

* Start gameplay
* Trigger events
* Run scripts
* Load maps
* Modify RNG

---

# Common Migration Types

## Adding Variables

Old save:

```c
u16 player_level;
```

New save:

```c
u16 player_level;
u16 skill_points;
```

Migration:

```c
save->skill_points = 0;
```

---

## Expanding Arrays

Old:

```c
inventory[128];
```

New:

```c
inventory[256];
```

Migration:

```c
Copy existing entries
Initialize new entries
```

Never read beyond old limits.

---

## New Flags

Old:

```c
flag_count = 400;
```

New:

```c
flag_count = 512;
```

Migration:

```c
New flags = false
```

---

## New Party Member Data

Old save lacks member fields.

Migration assigns defaults:

```c
level = 1
equipment = NONE
joined = false
```

---

## New Quest Data

New quests must default to:

```text
Not Started
```

unless explicitly unlocked by story progression.

---

# Removed Data

If data is removed:

Example:

```c
legacy_stat
```

Migration:

```text
Ignore field
```

Do not reuse removed memory locations for unrelated purposes.

Reserve them until the next major version.

---

# Deprecated Fields

Mark deprecated fields:

```c
u16 unused_legacy_value;
```

Comment:

```c
// Reserved for migration compatibility.
```

Maintain until next major save revision.

---

# Major Version Breaks

Major save revisions occur when:

* Save layout changes completely
* Class system redesigns
* Inventory redesigns
* Story structure changes
* Rune system redesigns

Example:

```text
Version 199 → Version 200
```

May require full conversion routine.

---

# Unsupported Save Handling

Display:

```text
This save was created with an incompatible version and cannot be loaded.
```

Options:

```text
Return to Title
Delete Save
Export Save Information
```

Never auto-delete.

---

# Backup Saves

Before migration:

Create:

```text
SAVE01.BAK
SAVE02.BAK
SAVE03.BAK
```

Backup contains:

* Original save
* Original checksum
* Original version

Backup persists until successful validation.

---

# Recovery Process

If migration fails:

```text
Restore Backup
```

Steps:

1. Delete failed save
2. Restore backup
3. Notify player
4. Log migration error

---

# Save Validation After Migration

Verify:

* Version updated
* Checksum valid
* Party data valid
* Inventory valid
* Quest data valid
* Flags within range
* Story progression valid
* Rune collection state valid

Migration succeeds only if all checks pass.

---

# Story Validation Rules

Migration must prevent impossible states.

Examples:

Invalid:

```text
Rune of Fire acquired
Muspelheim locked
```

Invalid:

```text
Astrid not recruited
Midgard complete
```

Invalid:

```text
Renew Route active
Helheim incomplete
```

Migration validator should repair where possible.

Otherwise:

```text
Migration Failed
```

---

# Inventory Validation Rules

Verify:

* Item IDs exist
* Quantities valid
* Key items unique
* Equipment IDs valid
* No overflow

Repair:

```text
Invalid item → removed
Invalid quantity → clamped
```

Log repairs.

---

# Class Validation Rules

Verify:

* Valid class ID
* Valid skill allocation
* Valid equipment compatibility

Repair:

```text
Invalid class → Minstrel
```

Log repair.

---

# Rune Validation Rules

Verify:

* Rune count
* Rune ownership
* Story consistency

Current canonical runes:

1. Rune of Light
2. Rune of Radiance
3. Rune of Craft
4. Rune of Growth
5. Rune of Giants
6. Rune of Ice
7. Rune of Fire
8. Rune of Thunder
9. Rune of Death
10. Rune of Wisdom

---

# Development Build Policy

Development builds may:

* Auto-migrate
* Display migration logs
* Generate migration reports

Release builds:

* Hide technical details
* Preserve backups
* Show user-friendly messages

---

# Automated Migration Tests

Required tests:

```text
100 → 110
110 → 120
120 → 130
130 → 140
140 → 150
100 → 150
```

For each test verify:

* Save loads
* Save validates
* Story progresses correctly
* Inventory preserved
* Party preserved
* Flags preserved

---

# Migration Report Format

Debug output:

```text
Save Migration Report

Original Version: 120
Target Version: 150

Applied:
120 → 130
130 → 140
140 → 150

Added:
112 New Flags
3 New Inventory Slots
1 Rune Tracking Field

Status:
SUCCESS
```

---

# Release Policy

Before every milestone:

Run migration tests on:

* Oldest supported save
* Previous milestone save
* Current save

No release may ship if migration tests fail.

---

# Canon Principle

A player's journey is part of the world.

```text
Versions may change.
The story they lived must remain.
```

---

End of File
