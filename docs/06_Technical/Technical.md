# Yggdrasil Saga

## Technical Specification

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document defines the technical implementation standards for **Yggdrasil Saga**.

It serves as the primary reference for:

- Engine Architecture
- Nintendo DS Hardware
- Performance
- Rendering
- Memory Management
- Save Data
- Input
- Technical Constraints

All technical systems should support the narrative and gameplay defined in the canon documentation.

---

# Target Platform

Nintendo DS

Compatible with:

- Nintendo DS
- Nintendo DS Lite
- Nintendo DSi
- Nintendo 3DS (Backwards Compatibility)

Supported Emulators

- melonDS
- DeSmuME
- RetroArch

---

# Engine Philosophy

The engine should prioritise:

- Stability
- Predictable performance
- Fast loading
- Low memory usage
- Hardware accuracy

---

# Hardware Limits

## Main RAM

4 MB

---

## VRAM

656 KB

---

## Maximum ROM Size

128 MB

---

## Save Size

64 KB

Three Save Slots

---

# Performance Targets

| System             | Target |
|--------------------|--------|
| Exploration        | 60 FPS |
| Battle             | 60 FPS |
| Menus              | 60 FPS |
| Cutscenes          | 60 FPS |
| Minimum Acceptable | 30 FPS |

---

# Screen Layout

## Exploration

### Top Screen

- World Rendering
- Characters
- Environment
- Effects

---

### Bottom Screen

- Mini Map
- Quick Menu
- Touch Controls

---

## Battle

### Top Screen

- Enemies
- Battle Effects
- Animations

---

### Bottom Screen

- Party Status
- Commands
- Skills
- Rune Energy

---

## Menus

### Top Screen

- Character Portrait
- Equipment Preview
- Statistics

### Bottom Screen

- Inventory
- Navigation
- Touch Interface

---

# Input

Supports:

Buttons

- D-Pad
- A
- B
- X
- Y
- L
- R
- Start
- Select

Touch Screen

Stylus support throughout the game.

---

# Touch Functions

- Menu Navigation
- Skill Selection
- Item Selection
- Inventory Management
- World Map
- Fast Travel

Touch is optional.

Entire game remains playable using buttons only.

---

# Rendering

Render Order

1. Background
2. Tilemap
3. Environment
4. NPCs
5. Player
6. Effects
7. UI

---

# Sprite Standards

Player

32×32

---

NPC

32×32

---

Enemies

32×32

48×48

64×64

---

Bosses

64×64

96×96

Multi-sprite

---

Portraits

64×64

Dialogue Portraits

128×128

---

# Animation Standards

Walk

4 Frames

---

Idle

2 Frames

---

Attack

4–6 Frames

---

Magic

4 Frames

---

Damage

2 Frames

---

Death

4 Frames

---

# Memory Allocation

| System   | Budget           |
|----------|------------------|
| Graphics | 1024 KB          |
| Audio    | 512 KB           |
| Maps     | 768 KB           |
| Battle   | 384 KB           |
| UI       | 256 KB           |
| Save     | 64 KB            |
| Reserve  | Remaining Memory |

---

# Audio

Formats

- SSEQ
- SWAR
- STRM

Audio Categories

- BGM
- Ambient
- SFX
- UI
- Voice Effects

---

# Save System

Stored Data

- Story Progress
- Party
- Equipment
- Inventory
- Quest Flags
- Event Flags
- Arena Data
- Bestiary
- Codex
- Achievements

---

# New Game Plus

Carries Forward

- Levels
- Classes
- Equipment
- Inventory
- Crafting Recipes
- Arena Progress
- Achievements

Resets

- Story
- Quests
- Covenant Runes
- Realm Progress

---

# Fast Travel

Managed exclusively by:

Ratatoskr

Unlocks after completing each realm.

Unavailable during:

- Story Events
- Final Dungeon
- Certain Boss Battles

---

# Class Change

Performed only at:

Mímir's Well

No other location may perform class changes.

---

# Combat Systems

Supports

- Turn-Based Combat
- Rune Energy
- Status Effects
- Multi-Phase Bosses
- Companion AI

---

# World Systems

Supports

- Dynamic Story Flags
- Realm Progression
- Dungeon Events
- Side Quests
- Arena
- Hvergelmir
- Boss Rush

---

# Event System

Driven entirely through Event Flags.

All story progression is deterministic.

No random story triggers.

---

# File Structure

```text
/data
    /gfx
    /bgm
    /sfx
    /map
    /events
    /scripts
    /ui
    /portraits
    /text
    /save
```

---

# Canon Technical Rules

- Ratatoskr controls Fast Travel.
- Mímir's Well is the only class change location.
- The Ten Rune Covenant drives story progression.
- Every realm unlocks sequentially.
- No deprecated classes or systems may be referenced.
- All gameplay systems derive from CANON_REFERENCE.md.

---

# Development Priorities

1. Stability
2. Performance
3. Gameplay
4. Visual Polish
5. Content Expansion

---

# Vision Statement

> Technical implementation should never distract from the player's journey through the Ten Realms.

Every system exists to support exploration, storytelling, and meaningful player choice.

---

**End of File**