# Yggdrasil Saga

## Asset Pipeline

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document defines the production pipeline for every asset created for **Yggdrasil Saga**.

It standardises how assets move from concept to implementation.

It serves as the primary reference for:

- Artists
- Animators
- Programmers
- Audio Designers
- QA
- Production

---

# Pipeline Philosophy

Every asset should pass through the same production stages.

```text
Concept
    ↓
Production
    ↓
Review
    ↓
Implementation
    ↓
Testing
    ↓
Approved
```

No asset should bypass review.

---

# Asset Categories

Assets are grouped into:

- Characters
- Portraits
- Enemies
- Bosses
- Environments
- Tilesets
- UI
- Animation
- Audio
- Effects
- Scripts

---

# Character Pipeline

## Stage 1

Concept Art

Deliverables

- Front View
- Side View
- Colour Palette
- Expression Sheet

---

## Stage 2

Sprite Production

Deliverables

- Idle
- Walk
- Attack
- Damage
- KO
- Victory

---

## Stage 3

Portraits

Required

- Neutral
- Happy
- Determined
- Angry
- Sad
- Thinking
- Surprised
- Serious

Ratatoskr additionally requires

- Excited
- Curious
- Laughing
- Worried

---

## Stage 4

Animation

Animations created according to:

Animation_Bible.md

---

## Stage 5

Implementation

Imported into engine.

Animation hooks connected.

---

## Stage 6

QA

Verify

- Alignment
- Palette
- Animation timing
- Performance

---

# Environment Pipeline

Stages

Concept

↓

Tileset

↓

Collision

↓

Lighting

↓

Objects

↓

NPC Placement

↓

Testing

---

# Dungeon Pipeline

Stages

Concept

↓

Layout

↓

Puzzle Design

↓

Enemy Placement

↓

Treasure Placement

↓

Boss Placement

↓

Playtesting

---

# Enemy Pipeline

Stages

Concept

↓

Sprite

↓

Animation

↓

Statistics

↓

AI

↓

Drops

↓

Testing

---

# Boss Pipeline

Stages

Concept

↓

Narrative Review

↓

Sprite

↓

Animation

↓

Arena Design

↓

Combat Design

↓

Balance

↓

QA

Bosses require approval from:

- Narrative
- Combat
- Art

before implementation.

---

# UI Pipeline

Stages

Wireframe

↓

Artwork

↓

Programming

↓

Implementation

↓

Accessibility Review

↓

QA

---

# Audio Pipeline

Stages

Composition

↓

Review

↓

Implementation

↓

Mixing

↓

Testing

Music categories

- Realm Themes
- Character Themes
- Boss Themes
- Battle Themes
- Ambient
- UI

---

# Script Pipeline

Stages

Outline

↓

Dialogue

↓

Review

↓

Localization

↓

Implementation

↓

Playtesting

---

# Naming Convention

Characters

```text
chr_hero.png
chr_astrid.png
```

---

Portraits

```text
por_ratatoskr_happy.png
```

---

Enemies

```text
enm_wild_boar.png
```

---

Bosses

```text
bos_draugr_jarl.png
```

---

Maps

```text
map_midgard_forest.map
```

---

UI

```text
ui_inventory.png
```

---

Music

```text
bgm_midgard.sseq
```

---

Sound Effects

```text
sfx_rune_fire.swar
```

---

# Folder Structure

```text
/assets
    /characters
    /portraits
    /enemies
    /bosses
    /tilesets
    /maps
    /ui
    /effects
    /audio
        /bgm
        /sfx
    /scripts
```

---

# Review Checklist

Every asset must satisfy:

✓ Canon accurate

✓ Naming correct

✓ Nintendo DS compatible

✓ Performance verified

✓ Approved by department lead

---

# Performance Standards

All assets must remain within:

- Nintendo DS VRAM budget
- Sprite limits
- Palette limits
- Animation budget
- Audio memory budget

---

# Asset Ownership

| Asset Type | Owner              |
|------------|--------------------|
| Story      | Narrative          |
| Characters | Character Artist   |
| Portraits  | Character Artist   |
| Enemies    | Creature Artist    |
| Bosses     | Lead Artist        |
| Maps       | Environment Artist |
| UI         | UI Artist          |
| Audio      | Composer           |
| Effects    | Technical Artist   |

---

# QA Verification

Every implemented asset must be checked for:

- Missing frames
- Incorrect palettes
- Animation glitches
- Wrong dialogue portrait
- Incorrect sound effects
- Memory usage
- Performance impact

---

# Canon Principles

- Every asset must match CANON_REFERENCE.md.
- Ratatoskr is treated as a primary character asset.
- Every Covenant Rune has dedicated visual and audio assets.
- No deprecated classes, bosses, NPCs, or Rune names may appear.
- Assets are approved only after passing production review and QA.

---

**End of File**