# Yggdrasil Saga

## Testing Plan

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document defines the Quality Assurance process for **Yggdrasil Saga**.

It serves as the primary reference for:

- Functional Testing
- Gameplay Testing
- Regression Testing
- Performance Testing
- Balance Testing
- Certification Readiness

Every feature must pass QA before being considered complete.

---

# Testing Philosophy

Testing should verify:

- Stability
- Consistency
- Canon accuracy
- Performance
- Player experience

Testing is performed continuously throughout development.

---

# Testing Stages

```text
Unit Testing
      ↓
Feature Testing
      ↓
Integration Testing
      ↓
Playtesting
      ↓
Regression Testing
      ↓
Release Candidate
```

---

# Unit Testing

Verifies individual systems.

Examples

- Combat
- Inventory
- Equipment
- Save System
- Event Flags
- AI

---

# Integration Testing

Verifies systems working together.

Examples

- Quest + Cutscene
- Equipment + Crafting
- Arena + Rewards
- Dialogue + Flags
- Story + Save Data

---

# Gameplay Testing

Tests:

- Exploration
- Combat
- Bosses
- Classes
- Rune Skills
- Arena
- Crafting

---

# Story Testing

Verify:

- Dialogue Order
- Cutscene Order
- Quest Progression
- Event Flags
- Ending Routes

Every story path must remain completable.

---

# Canon Testing

Verify:

- Character Names
- Rune Order
- Realm Order
- Boss Order
- Party Order
- Dialogue Consistency

No document or in-game content may contradict:

**CANON_REFERENCE.md**

---

# Performance Testing

Target Hardware

Nintendo DS

Performance Targets

| System      | Target |
|-------------|--------|
| Exploration | 60 FPS |
| Battle      | 60 FPS |
| Menus       | 60 FPS |
| Cutscenes   | 60 FPS |
| Minimum     | 30 FPS |

---

# Memory Testing

Verify:

- RAM Usage
- VRAM Usage
- Audio Buffers
- Save Data
- Asset Streaming

No memory leaks permitted.

---

# Save Testing

Verify:

- Save Creation
- Save Loading
- Save Migration
- New Game Plus
- Corruption Recovery

Every save slot tested independently.

---

# Combat Testing

Verify:

- Skills
- Rune Skills
- Status Effects
- Boss AI
- Damage Formulae
- Equipment Bonuses

---

# Quest Testing

Every quest must verify:

- Start
- Progress
- Completion
- Rewards
- Flags

Softlocks are unacceptable.

---

# Boss Testing

Every boss must verify:

- Intro Cutscene
- Phase Changes
- Rewards
- Rune Acquisition
- Story Progression

---

# Arena Testing

Verify:

- Tier Unlocks
- Boss Rush
- Endless Arena
- Arena Tokens
- Rewards

---

# Crafting Testing

Verify:

- Recipes
- Materials
- Upgrades
- Rune Resonance

---

# UI Testing

Verify:

- Menus
- Touch Controls
- Button Controls
- Portrait Display
- Dialogue Boxes
- HUD

---

# Audio Testing

Verify:

- Music Loops
- Sound Effects
- Volume Levels
- Ambient Audio
- Battle Music
- Boss Themes

---

# Localization Testing

Verify:

- Text Overflow
- Portrait Alignment
- Dialogue Timing
- Special Characters
- Line Breaks

---

# Regression Testing

Every milestone requires:

Complete replay of:

- Main Story
- Side Quests
- Arena
- Crafting
- Postgame

No previously fixed issue may reappear.

---

# Bug Severity

## Critical

Game cannot continue.

Crash.

Save corruption.

Immediate fix required.

---

## Major

Feature unusable.

Story progression blocked.

Fix before milestone.

---

## Minor

Gameplay issue.

Visual issue.

Incorrect dialogue.

Fix before release.

---

## Cosmetic

Typos.

Animation glitches.

Visual polish.

Fix when time permits.

---

# Release Checklist

Before Release Candidate:

✓ Story Complete

✓ All Three Endings Playable

✓ Arena Complete

✓ Crafting Complete

✓ No Critical Bugs

✓ Performance Targets Met

✓ Save Compatibility Verified

✓ Canon Verified

---

# Vertical Slice Checklist

The Midgard Vertical Slice must include:

- Hero
- Ratatoskr
- Astrid
- Mannheim Village
- Ironwood Forest
- Draugr Barrow
- Draugr Jarl
- Rune of Craft
- Save System
- Equipment
- Basic Combat

---

# QA Sign-Off

Every feature requires approval from:

- Design
- Programming
- Art
- Audio
- QA

before entering Release Candidate.

---

# Canon Principles

- Every test build must match CANON_REFERENCE.md.
- Ratatoskr must function as the permanent companion throughout testing.
- All three ending routes must be fully testable.
- The Ten Rune Covenant must function correctly in every playthrough.
- Stability takes priority over new features.

---

**End of File**