# Performance_Optimization_Guide.md

````markdown id="p9v3mk"
# Performance Optimization Guide
## Yggdrasil Saga
### Version 1.0

---

# Purpose

This document defines the performance standards and optimization strategies for Yggdrasil Saga.

It supplements:

- Coding_Standards.md
- Build_Configuration.md
- Animation_Bible.md
- Testing_Plan.md

This document focuses on:

- Nintendo DS hardware limitations
- Memory usage
- CPU optimization
- Rendering performance
- Asset management
- Runtime stability

---

# Core Principle

Hardware Limitations Take Priority.

If a feature threatens performance, the feature must be redesigned or removed.

Reference:

Coding_Standards.md

---

# Nintendo DS Hardware Targets

## Main CPU

ARM946E-S

67 MHz

---

## Secondary CPU

ARM7TDMI

33 MHz

---

## Main RAM

4 MB

---

## VRAM

656 KB

---

## Display Resolution

256 × 192

Dual Screens

---

# Performance Goals

## Frame Rate

Target:

30 FPS

---

## Minimum Acceptable

25 FPS

---

## Critical Threshold

Below 20 FPS

Must be investigated immediately.

---

# Frame Budget

At 30 FPS:

```text
33.33 ms per frame
```

Budget allocation:

| System | Budget |
|----------|----------|
| Rendering | 12 ms |
| Battle Logic | 6 ms |
| AI | 4 ms |
| UI | 3 ms |
| Audio | 2 ms |
| Save/Background Tasks | 2 ms |
| Safety Margin | 4 ms |

---

# Memory Budget

## Total RAM Budget

Available:

4 MB

Target Usage:

3.5 MB

Reserve:

500 KB

---

# Memory Allocation Policy

Allowed:

- Startup allocation
- Fixed memory pools

---

Forbidden:

- Runtime heap allocation during gameplay
- Continuous allocation/free cycles

---

# Memory Pools

Preferred structure:

```c
entity_pool
enemy_pool
effect_pool
ui_pool
```

Preallocated at startup.

---

# Object Limits

## Active Enemies

Maximum:

8

---

## Active Party Members

Maximum:

4

---

## Active Battle Effects

Maximum:

32

---

## Active Projectiles

Maximum:

16

---

# Rendering Guidelines

## Sprite Count

Target:

< 64 visible sprites

---

Maximum:

128 visible sprites

---

## Boss Battles

Bosses may exceed normal sprite counts only if:

- Frame rate remains stable
- Memory budget remains valid

---

# Animation Optimization

Reference:

Animation_Bible.md

---

## Character Animations

Maximum:

4-frame walk cycle

---

## Portrait Animations

Maximum:

4 frames

---

## Battle Effects

Maximum:

16 frames

---

## Looping Effects

Reuse existing frames whenever possible.

---

# Sprite Reuse

Reuse assets whenever possible.

Examples:

- Shared shadows
- Shared hit effects
- Shared status icons

Avoid duplicate sprite sheets.

---

# Tile Optimization

Prefer:

```text
Tile Reuse
```

over

```text
Unique Artwork
```

---

## Tile Set Budget

Recommended:

128–256 tiles per map region

---

# Background Optimization

Use:

- Tile maps
- Parallax only when necessary

Avoid:

- Full-screen animated backgrounds

---

# UI Performance

Reference:

UI_Style_Guide.md

---

UI should:

- Update only when data changes
- Avoid per-frame redraws

---

Example:

Incorrect:

```c
draw_hp_every_frame();
```

Correct:

```c
draw_hp_when_changed();
```

---

# Text Rendering

Cache frequently used text.

Examples:

- HP
- MP
- Gold

Avoid rebuilding strings every frame.

---

# Battle Performance

Highest priority gameplay system.

---

# Turn Processing

Combat calculations should complete within:

```text
1 ms
```

per action.

---

# Damage Calculations

Use:

- Integer arithmetic

Avoid:

- Floating point arithmetic

---

Example:

Preferred:

```c
damage =
(atk * 150) / 100;
```

Avoid:

```c
damage =
atk * 1.5f;
```

---

# Status Effect Processing

Update once per turn.

Never every frame.

---

# AI Optimization

Enemy AI must be lightweight.

---

## Decision Trees

Maximum Depth:

5

---

## AI Evaluation

Only evaluate:

- Available skills
- Current target

Avoid:

- Long predictive simulations

---

# Pathfinding

Used in overworld only.

---

Preferred:

```text
A*
```

with node limits.

---

Avoid:

- Full-map searches every frame

---

# Audio Optimization

## Simultaneous Sounds

Recommended:

8 channels

---

Maximum:

16 channels

---

## Music

Use compressed formats where possible.

Loop sections cleanly.

---

# Asset Loading

## Load Timing

Load assets:

- Map Entry
- Battle Start
- Menu Open

Never during active gameplay.

---

# Streaming

Not required.

Entire scene should fit in memory.

---

# Asset Compression

Use:

- LZ77
- Nintendo DS compatible compression

For:

- Sprites
- Backgrounds
- UI graphics

---

# Save System Performance

Reference:

Save_Migration.md

---

## Save Time Target

Maximum:

2 seconds

---

## Load Time Target

Maximum:

2 seconds

---

# File Size Targets

## Save File

Maximum:

128 KB

---

## Character Data

Maximum:

8 KB

---

## Arena Data

Maximum:

2 KB

---

## Achievement Data

Maximum:

16 KB

---

# Event System Optimization

Use:

```text
Event-Driven Systems
```

Prefer:

```c
on_enemy_defeated()
```

over

```c
check_enemy_defeated_every_frame()
```

---

# Achievement Optimization

Reference:

Achievement_Implementation.md

---

Achievements must:

- Trigger from events
- Avoid global scans

Never evaluate all achievements every frame.

---

# Arena Optimization

Reference:

Arena_Implementation.md

---

Generate waves:

- On round start
- Not continuously

Store only active wave data.

---

# Crafting Optimization

Reference:

Crafting_Implementation.md

---

Recipe validation should occur only when:

Player selects craft option.

No background checks.

---

# Localization Optimization

Reference:

Localization_Pipeline.md

---

Load:

Current language only.

Avoid storing multiple language databases in RAM.

---

# New Game Plus Optimization

Reference:

New_Game_Plus_Implementation.md

---

NG+ processing occurs:

Only during save creation.

No runtime performance impact.

---

# Profiling Requirements

Performance profiling required for:

- Battles
- Boss fights
- Arena
- Save operations
- Realm transitions

---

# Debug Performance Overlay

Reference:

Debug_Tools.md

---

Display:

- FPS
- Memory Usage
- Active Sprites
- Active Effects
- CPU Frame Time

---

# Performance Warning Levels

## Green

FPS ≥ 30

System healthy.

---

## Yellow

FPS 25–29

Monitor.

---

## Orange

FPS 20–24

Optimization required.

---

## Red

FPS < 20

Fix immediately.

---

# Optimization Checklist

Before milestone approval:

- Stable 30 FPS
- Memory within budget
- No leaks detected
- Load times acceptable
- Save times acceptable
- Arena stable
- Boss fights stable

---

# Gold Master Requirements

Required:

- Stable gameplay
- No memory leaks
- No critical frame drops
- Save/load targets met
- All realms playable at target performance

Reference:

Testing_Plan.md

---

# Common Performance Mistakes

Avoid:

- Dynamic allocation during gameplay
- Excessive sprite counts
- Full-screen transparency effects
- Floating point math
- Per-frame string creation
- Repeated file access
- Global scans every frame

---

# Core Performance Principle

"Performance is a feature. A game that runs smoothly on real hardware is more valuable than a game with features the hardware cannot support."
````

With this document complete, the only major empty document remaining from your original list should be:

```text
docs/06_Technical/Postgame_System_Implementation.md
```

After that, your documentation set is essentially complete and ready to support actual asset production and development.
