# New_Game_Plus_Implementation.md

````markdown id="ngp6v2"
# New Game Plus Implementation
## Yggdrasil Saga
### Version 1.0

---

# Purpose

This document defines the technical implementation of New Game Plus (NG+).

It supplements:

- New_Game_Plus.md
- Save_Migration.md
- Achievement_Implementation.md
- Arena_Implementation.md
- Testing_Plan.md

This document focuses on:

- NG+ save creation
- Data carry-over
- Difficulty scaling
- Exclusive content
- Ending tracking
- True Ending unlocks

---

# Design Goals

New Game Plus must:

- Preserve player accomplishments
- Restart story progression
- Support multiple completions
- Remain save-safe
- Require minimal memory
- Support future expansion

---

# System Overview

NG+ consists of:

1. Game Completion
2. Ending Registration
3. NG+ Save Creation
4. Data Transfer
5. Story Reset
6. Mythic Content Unlocks

---

# Unlock Conditions

NG+ becomes available after:

```c
ENDING_PRESERVE
```

or

```c
ENDING_RENEW
```

has been completed.

---

# Completion Flags

Stored permanently.

```c
typedef enum
{
    ENDING_NONE,
    ENDING_PRESERVE,
    ENDING_RENEW,
    ENDING_BALANCE

} ending_type_t;
```

---

# Ending Progress Data

```c
typedef struct
{
    bool preserve_complete;

    bool renew_complete;

    bool balance_complete;

} ending_progress_t;
```

---

# New Game Plus Save Creation

Process:

```text
Complete Ending
↓
Create NG+ Save
↓
Copy Eligible Data
↓
Reset Story Data
↓
Initialize NG+ Flags
↓
Start Prologue
```

---

# NG+ Save Flag

```c
bool is_new_game_plus;
```

Stored per save file.

---

# NG+ Generation Count

Tracks completions.

```c
uint8_t ng_plus_count;
```

Example:

```text
NG+ 1
NG+ 2
NG+ 3
```

---

# Data Carry-Over

The following data transfers:

---

## Character Levels

```c
party.levels
```

Retained.

---

## Character Stats

```c
party.stats
```

Retained.

---

## Equipment

```c
inventory.equipment
```

Retained.

---

## Inventory

```c
inventory.items
```

Retained.

Excludes:

Story Key Items

---

## Gold

```c
player.gold
```

Retained.

---

## Arena Data

Reference:

Arena_Implementation.md

Retained.

---

## Achievement Data

Reference:

Achievement_Implementation.md

Retained.

---

## Codex Data

Retained.

---

## Crafting Data

Reference:

Crafting_Implementation.md

Retained.

---

# Data Reset

The following must reset:

---

## Story Progress

```c
story_flags
```

Reset.

---

## Quest Progress

```c
quest_states
```

Reset.

---

## Rune Collection

Reset.

All runes return to original locations.

---

## Fast Travel

Reset.

Locations rediscovered naturally.

---

## Cutscene Flags

Reset.

---

## Tutorial Flags

Reset.

Can be skipped if desired.

---

# Story Reset Function

```c
void ng_plus_reset_story(void);
```

Responsible for:

- Main quests
- Side quests
- World progression
- Realm completion

---

# Key Item Cleanup

Before transfer:

Remove all:

```c
ITEM_KEY
```

and

```c
ITEM_QUEST
```

categories.

---

# Mythic Difficulty

Exclusive to NG+.

---

# Difficulty Enum

```c
typedef enum
{
    DIFF_EXPLORER,
    DIFF_ADVENTURER,
    DIFF_HEROIC,
    DIFF_SAGA,
    DIFF_MYTHIC

} difficulty_t;
```

---

# Enemy Scaling

Applied during battle initialization.

---

## Standard Enemies

```c
HP × 1.5
ATK × 1.3
DEF × 1.3
```

---

## Elite Enemies

```c
HP × 1.8
ATK × 1.4
DEF × 1.4
```

---

## Bosses

```c
HP × 2.0
ATK × 1.5
DEF × 1.5
```

---

# Mythic Boss Abilities

Enabled through flags.

Example:

```c
boss.enable_mythic_phase = true;
```

---

# Mythic Enemy Variants

Additional enemy versions.

```c
enemy_variant_t
```

Examples:

- Mythic Draugr
- Mythic Wolf
- Mythic Giant
- Mythic Wyrm

---

# NG+ Exclusive Content Flags

```c
bool mythic_content_unlocked;
```

Set during NG+ creation.

---

# Mythic Crafting

Reference:

Crafting_Implementation.md

---

Unlock:

```c
mythic_recipes = true;
```

---

# Secret Boss Tracking

```c
typedef struct
{
    bool odin_trial;

    bool first_dragon;

    bool world_serpent;

} secret_boss_state_t;
```

---

# True Ending Requirements

Verify:

```text
Preserve Ending Complete
Renew Ending Complete
Odin Trial Defeated
First Dragon Defeated
World Serpent Defeated
Last Cycle Quest Complete
```

---

# True Ending Validation

```c
bool can_unlock_balance_ending(void);
```

Returns:

```c
true
```

only when all requirements met.

---

# Ending Registration

After completion:

```c
save.endings.balance_complete = true;
```

---

# Title Rewards

Reference:

Achievement_Database.md

---

Unlock:

```c
TITLE_MYTHIC_ADVENTURER
TITLE_FATEBREAKER
TITLE_WORLDSHAPER
```

---

# Arena Integration

Reference:

Arena_Implementation.md

---

Retained:

- Arena Rank
- Arena Tokens
- Arena Records

Not reset.

---

# Achievement Integration

Reference:

Achievement_Implementation.md

---

Retained:

- Progress
- Unlocks
- Rewards

---

# Codex Integration

Retained:

- Lore Entries
- Enemy Records
- Boss Records

---

# Save Data Structure

```c
typedef struct
{
    bool is_new_game_plus;

    uint8_t ng_plus_count;

    ending_progress_t endings;

    secret_boss_state_t bosses;

} ng_plus_save_t;
```

---

# Save Requirements

NG+ data must survive:

- Save
- Load
- Version migration
- Multiple NG+ cycles

Reference:

Save_Migration.md

---

# Multiple NG+ Runs

Supported indefinitely.

Maximum:

```c
255
```

NG+ cycles.

Stored using:

```c
uint8_t
```

---

# Display Format

Example:

```text
NG+ 3
Mythic Difficulty
```

Shown on:

- Save Screen
- File Select Screen

---

# Memory Budget

NG+ Save Data:

Maximum 2 KB

Runtime Data:

Maximum 2 KB

Total Budget:

Less than 8 KB

---

# Performance Requirements

NG+ initialization must:

- Complete during save creation
- Avoid runtime overhead
- Avoid duplicate calculations

No per-frame processing.

---

# Debug Support

Reference:

Debug_Tools.md

---

## Debug Commands

Enable NG+

```c
debug_enable_ng_plus();
```

---

Unlock Preserve Ending

```c
debug_unlock_preserve();
```

---

Unlock Renew Ending

```c
debug_unlock_renew();
```

---

Unlock Balance Ending

```c
debug_unlock_balance();
```

---

Set NG+ Count

```c
debug_set_ng_count();
```

---

Unlock Mythic Difficulty

```c
debug_unlock_mythic();
```

---

# Testing Requirements

Reference:

Testing_Plan.md

---

Verify:

- Data transfer
- Story reset
- Key item removal
- Mythic scaling
- Secret boss unlocks
- True Ending unlock
- Multiple NG+ cycles
- Save persistence

---

# Future Expansion

Additional NG+ features may include:

- New difficulty tiers
- Additional endings
- Exclusive bosses
- Bonus rewards

Existing ending IDs must never change.

---

# Core New Game Plus Principle

"New Game Plus should preserve player mastery while allowing the world to be experienced through new knowledge, greater challenges, and hidden truths."
````
