# Yggdrasil Saga

## Save Data Structure

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document defines the complete save format used throughout **Yggdrasil Saga**.

It serves as the primary reference for:

- Save Data
- Save Compatibility
- New Game Plus
- Event Flags
- Story Progress
- Character Progression
- Technical Implementation

The save format is designed for Nintendo DS hardware while remaining forward-compatible with future versions.

---

# Save Slots

Number of Slots

```text
3
```

Each save slot occupies:

```text
64 KB
```

---

# Save File Layout

```text
Header
Party Data
Story Progress
Rune Covenant
Inventory
Equipment
Quest Data
World State
Arena Data
Bestiary
Codex
Achievements
System Settings
Checksum
```

---

# Header Block

Stores:

- Save Version
- Save Slot
- Timestamp
- Play Time
- Player Name
- Checksum

---

## Save Identifier

```text
YGGS
```

---

## Version

Current

```text
5.0
```

---

# Story Progress

Stores:

- Current Chapter
- Current Realm
- Current Dungeon
- Story Flags
- Ending Route
- Ending Completion

---

# Party Data

For every playable character:

Stores

- Level
- Current Class
- Experience
- HP
- MP
- Base Stats
- Learned Skills
- Equipment

---

## Party Members

- Hero
- Astrid
- Eirik
- Thora Ironhand
- Thrym

Ratatoskr is **not** stored as a party member.

Instead:

```text
RatatoskrUnlocked = TRUE/FALSE
```

---

# Rune Covenant

Stores:

- Craft
- Radiance
- Light
- Growth
- Giants
- Ice
- Fire
- Wisdom
- Death
- Thunder

Each Rune stores:

```text
Obtained
Activated
StoryComplete
```

---

# Event Flags

Stores every permanent flag.

Examples

```text
FLAG_PROLOGUE_STARTED

FLAG_ASTRID_JOINED

FLAG_RUNE_CRAFT_OBTAINED

FLAG_THREE_PHILOSOPHIES

FLAG_ENDING_RENEWAL
```

---

# Inventory

Stores

- Consumables
- Materials
- Key Items
- Quest Items

Maximum Stack

```text
99
```

---

# Equipment

Stores

Weapons

Armour

Accessories

Upgrade Level

Rune Resonance

---

# Quest Data

Stores

- Main Quests
- Side Quests
- Companion Quests
- Postgame Quests

Each quest stores

```text
Not Started

Active

Completed
```

---

# World State

Stores

- Realm Progress
- Dungeon Completion
- Treasure Chests
- NPC States
- Fast Travel

---

# Fast Travel

Managed by Ratatoskr.

Stores:

```text
Midgard

Alfheim

Svartalfheim

Vanaheim

Jötunheim

Niflheim

Muspelheim

Asgard

Helheim
```

Unlocked individually.

---

# Arena Data

Stores

- Arena Rank
- Tokens
- Records
- Boss Rush
- Endless Arena

---

# Bestiary

Stores

- Defeated Enemies
- Defeat Count
- Boss Records
- Completion %

---

# Codex

Stores

Unlocked

- Lore Entries
- Character Entries
- Realm Entries
- Rune Entries
- History Entries

---

# Achievements

Stores

Unlocked Achievements

Achievement Points

Completion %

---

# Settings

Stores

- Music Volume
- SFX Volume
- Text Speed
- Battle Speed
- Control Mode
- Language

---

# New Game Plus

Carries Forward

- Character Levels
- Classes
- Skills
- Equipment
- Inventory
- Recipes
- Arena Progress
- Achievements
- Bestiary
- Codex

Resets

- Story Progress
- Quest Progress
- Event Flags
- Covenant Runes
- Dungeon Progress
- Fast Travel

Ending Completion remains permanently recorded.

---

# Save Validation

Every save contains:

Checksum

Version Number

Backup Copy

Corrupted saves automatically restore from backup when possible.

---

# Save Migration

Future versions migrate incrementally.

Example

```text
5.0

↓

5.1

↓

5.2
```

Versions are never skipped.

---

# Debug Data

Development builds additionally store

- Debug Flags
- Developer Position
- Script State

These fields are stripped from release builds.

---

# Canon Rules

- Ratatoskr is stored as a permanent companion, not a party member.
- The Ten Rune Covenant is stored independently of inventory.
- Ending routes are permanently recorded.
- New Game Plus preserves player progression while resetting story progression.
- Save compatibility must always be maintained across future versions.

---

# Save Philosophy

A save file should preserve the player's journey without locking future content.

The player's choices should remain meaningful across multiple playthroughs while allowing new experiences through New
Game Plus.

---

**End of File**