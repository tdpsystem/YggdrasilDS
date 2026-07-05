# Yggdrasil Saga

## Release Plan

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document defines the development milestones and release strategy for **Yggdrasil Saga**.

It serves as the primary reference for:

- Production Planning
- Milestones
- Internal Builds
- Testing
- Release Candidates
- Gold Master

The objective is to move the project from concept to a complete Nintendo DS title while maintaining quality and
consistency.

---

# Development Philosophy

Development follows an iterative milestone structure.

Each milestone must be:

- Playable
- Stable
- Tested
- Canon Accurate

New features should never compromise existing systems.

---

# Development Stages

```text
Pre-Production
        ↓
Vertical Slice
        ↓
Alpha
        ↓
Content Alpha
        ↓
Beta
        ↓
Feature Complete
        ↓
Release Candidate
        ↓
Gold Master
```

---

# Phase 1

## Pre-Production

### Objectives

- Finalise Canon
- Complete Documentation
- Build Engine Foundation
- Prototype Core Systems

### Deliverables

- Canon Reference
- GDD
- Technical Specification
- Core Engine
- Basic Battle Prototype

### Completion Criteria

- Documentation Approved
- Core Systems Functional

---

# Phase 2

## Vertical Slice

### Scope

Midgard only.

### Playable Content

- Character Creation
- Ratatoskr Companion
- Mannheim Village
- Ironwood Forest
- Draugr Barrow
- Draugr Jarl
- Rune of Craft

### Systems Included

- Exploration
- Combat
- Equipment
- Inventory
- Save System
- Dialogue
- Quest System

### Completion Criteria

A polished demonstration representing final game quality.

---

# Phase 3

## Alpha

### Goal

Entire game playable from beginning to end.

### Required

- All Realms
- All Story Bosses
- All Classes
- All Equipment
- Main Story Complete

### Known Issues

- Balance
- Placeholder Art
- Temporary Audio

Acceptable at this stage.

---

# Phase 4

## Content Alpha

### Focus

Complete every remaining asset.

Includes

- Side Quests
- Arena
- Crafting
- Boss Rush
- Bestiary
- Codex
- Companion Quests

---

# Phase 5

## Beta

### Goal

Feature Complete.

No major gameplay systems may be added.

Development focuses on:

- Bug Fixing
- Balance
- Optimisation
- Polish

---

# Phase 6

## Feature Complete

Requirements

- All Assets Implemented
- All Dialogue Complete
- Localization Ready
- Save Compatibility Locked

Only bug fixes permitted beyond this point.

---

# Phase 7

## Release Candidate

Requirements

- No Critical Bugs
- Stable Performance
- QA Approved
- Canon Verified

Regression testing performed on every build.

---

# Phase 8

## Gold Master

Requirements

- Final ROM Built
- QA Approved
- Localization Complete
- Documentation Complete
- Performance Targets Achieved

Project enters archival status.

---

# Milestone Checklist

## Story

✓ Complete

---

## Gameplay

✓ Complete

---

## Combat

✓ Complete

---

## Classes

✓ Complete

---

## Equipment

✓ Complete

---

## Arena

✓ Complete

---

## Crafting

✓ Complete

---

## Bosses

✓ Complete

---

## Postgame

✓ Complete

---

## QA

✓ Complete

---

# Internal Build Naming

| Build | Description       |
|-------|-------------------|
| DEV   | Daily Development |
| VS    | Vertical Slice    |
| A     | Alpha             |
| CA    | Content Alpha     |
| B     | Beta              |
| FC    | Feature Complete  |
| RC    | Release Candidate |
| GM    | Gold Master       |

Example

```text
YS_VS_0.1

YS_A_0.5

YS_B_0.9

YS_RC1

YS_GM
```

---

# Versioning

Version Format

```text
Major.Minor.Revision
```

Examples

```text
0.1.0

0.5.0

0.9.0

1.0.0
```

---

# Quality Gates

Every milestone requires:

✓ Playable

✓ Stable

✓ QA Approved

✓ Canon Verified

✓ Performance Verified

---

# Release Targets

Target Platform

Nintendo DS

Supported Hardware

- DS
- DS Lite
- DSi
- 3DS (Backward Compatible)

Supported Emulators

- melonDS
- DeSmuME
- RetroArch

---

# Post-Release Goals

After Gold Master

Support:

- Bug Fixes
- Save Compatibility
- Documentation Updates

No major gameplay changes.

Canon remains fixed unless a future sequel requires expansion.

---

# Success Criteria

The project is considered complete when:

- Every realm is fully playable.
- All three ending routes are functional.
- Ratatoskr accompanies the Hero throughout the game.
- The Ten Rune Covenant functions correctly.
- All documentation matches the master canon.
- The game performs reliably on Nintendo DS hardware.

---

# Canon Principles

- Every milestone must remain consistent with CANON_REFERENCE.md.
- No milestone may introduce contradictory lore.
- Canon stability takes priority over adding new features.
- Every release candidate must pass full regression testing.
- Gold Master represents the definitive version of Yggdrasil Saga.

---

**End of File**