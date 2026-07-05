# Achievement_Implementation.md

````markdown id="r2k6xw"
# Achievement Implementation
## Yggdrasil Saga
### Version 1.0

---

# Purpose

This document defines the technical implementation of the Achievement System.

It supplements:

- Achievement_Database.md
- Save_Migration.md
- Coding_Standards.md

This document focuses on:

- Data structures
- Save storage
- Progress tracking
- Unlock logic
- Reward handling

---

# Design Goals

The Achievement System must:

- Be lightweight
- Be save-safe
- Require minimal memory
- Support future expansion
- Avoid duplicate unlocks
- Never lose player progress

---

# Achievement Architecture

Achievements consist of:

1. Definition Data
2. Progress Tracking
3. Unlock State
4. Reward State

---

# Achievement IDs

Every achievement receives a permanent ID.

Example:

```c
typedef enum
{
    ACH_FIRST_VICTORY,
    ACH_MONSTER_HUNTER,
    ACH_REALM_TRAVELER,
    ACH_MASTER_ARTISAN,
    ACH_ARENA_CHAMPION,
    ACH_SAGA_COMPLETE,

    ACH_COUNT

} achievement_id_t;
```

IDs must never be reordered after release.

New achievements are appended only.

---

# Achievement Definition Table

Stored in static data.

Example:

```c
typedef struct
{
    achievement_id_t id;

    const char* name;

    const char* description;

    uint16_t reward_points;

    bool hidden;

} achievement_definition_t;
```

---

# Example Entry

```c
{
    ACH_FIRST_VICTORY,
    "First Victory",
    "Win your first battle.",
    25,
    false
}
```

---

# Save Data Structure

Stored per save file.

```c
typedef struct
{
    bool unlocked;

    uint32_t progress;

} achievement_state_t;
```

---

# Achievement Save Block

```c
typedef struct
{
    achievement_state_t achievements[ACH_COUNT];

    uint32_t total_score;

    uint16_t unlocked_count;

} achievement_save_t;
```

---

# Save Requirements

Achievements must:

- Survive save/load
- Survive version migration
- Survive NG+

Reference:

Save_Migration.md

---

# Progress Tracking

Some achievements unlock instantly.

Examples:

- First Victory
- Realm Traveler
- End of an Age

Others require progress counters.

Examples:

- Defeat 100 enemies
- Craft 50 items
- Open 100 chests

---

# Progress Counters

Example:

```c
achievement_progress_increment(
    ACH_MONSTER_HUNTER,
    1);
```

---

# Unlock Conditions

Each achievement defines:

```c
typedef bool
(*achievement_condition_fn)(void);
```

---

Example:

```c
bool achievement_first_victory(void)
{
    return battle_stats.total_victories >= 1;
}
```

---

# Unlock Manager

Centralized system.

Runs:

- After battle
- After quest completion
- After crafting
- After arena completion
- After boss defeat

Never every frame.

---

# Achievement Evaluation

Process:

1. Event occurs
2. Progress updated
3. Relevant achievements checked
4. Unlock if condition met
5. Save updated
6. Notification displayed

---

# Unlock Function

Example:

```c
void achievement_unlock(
    achievement_id_t id)
{
    if(save.achievements[id].unlocked)
    {
        return;
    }

    save.achievements[id].unlocked = true;

    save.unlocked_count++;

    save.total_score +=
        achievement_defs[id].reward_points;

    ui_show_achievement(id);
}
```

---

# Duplicate Protection

Achievements may only unlock once.

Unlock attempts on completed achievements must be ignored.

---

# Hidden Achievements

Stored normally.

Until unlocked:

Display:

???
Hidden Achievement

---

After unlock:

Display actual data.

---

# Notification System

Triggered on unlock.

---

## Display Duration

5 seconds

---

## Top Screen

Achievement Banner

Example:

Achievement Unlocked!

First Victory

+25 Points

---

## Audio

Play:

SFX_ACHIEVEMENT_UNLOCK

Single playback only.

---

# Reward Handling

Achievements may grant:

- Points
- Titles
- Cosmetic rewards
- Arena rewards

---

# Title Unlocks

Example:

```c
player_unlock_title(
    TITLE_WORLDWALKER);
```

---

# Cosmetic Unlocks

Example:

```c
unlock_portrait_frame(
    FRAME_CHAMPION);
```

---

# Achievement Categories

Stored for UI filtering.

```c
typedef enum
{
    ACH_CAT_STORY,
    ACH_CAT_COMBAT,
    ACH_CAT_EXPLORATION,
    ACH_CAT_COLLECTION,
    ACH_CAT_CRAFTING,
    ACH_CAT_ARENA,
    ACH_CAT_POSTGAME

} achievement_category_t;
```

---

# Achievement Menu

Displays:

- Name
- Description
- Progress
- Reward Value
- Unlock Status

---

# Progress Examples

Combat:

75 / 100 Enemies Defeated

Crafting:

12 / 50 Items Crafted

Arena:

4 / 10 Wins

---

# Completion Tracking

Calculated dynamically.

```c
completion =
(
 unlocked_count * 100
)
/
ACH_COUNT;
```

---

# Completion Rewards

Milestones:

25%
50%
75%
100%

Reference:

Achievement_Database.md

---

# Event Sources

Achievements receive events from:

---

## Battle System

Events:

- Enemy Defeated
- Boss Defeated
- Victory

---

## Quest System

Events:

- Quest Completed

---

## Crafting System

Events:

- Item Crafted

---

## Arena System

Events:

- Arena Win
- Boss Rush Clear

---

## Exploration System

Events:

- Location Discovered
- Secret Found

---

## Story System

Events:

- Chapter Complete
- Ending Reached

---

# Memory Budget

Achievement data should remain under:

16 KB

Including:

- Progress
- Unlock states
- Statistics

Nintendo DS friendly.

---

# Performance Requirements

Achievement checks must:

- Execute instantly
- Avoid frame drops
- Avoid repeated scans

Use event-driven updates.

Never poll entire database every frame.

---

# Debug Support

Reference:

Debug_Tools.md

---

## Debug Commands

Unlock Achievement

```c
debug_unlock_achievement(id);
```

---

Reset Achievement

```c
debug_reset_achievement(id);
```

---

Unlock All

```c
debug_unlock_all_achievements();
```

---

# Testing Requirements

Reference:

Testing_Plan.md

---

Verify:

- Unlock conditions
- Save persistence
- NG+ carryover
- Hidden achievements
- Reward delivery

---

# Future Expansion

New achievements may be added by:

1. Appending IDs
2. Adding definitions
3. Adding conditions

Never alter existing IDs.

---

# Core Achievement Principle

"Achievement tracking should be invisible until success is earned, then immediately rewarding and permanently recorded."
````
