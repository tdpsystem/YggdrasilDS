# Rendering_Pipeline

## Yggdrasil Saga

Version: 1.0

Purpose:

Define how graphics are rendered on Nintendo DS hardware during exploration, battles, menus, and cutscenes.

This document establishes rendering order, screen usage, VRAM allocation, update frequency, and optimization rules.

---

# Rendering Goals

The rendering system must:

* Maintain 60 FPS during gameplay.
* Support dual-screen Nintendo DS presentation.
* Minimize VRAM usage.
* Reduce sprite flicker.
* Support large boss encounters.
* Remain compatible with original DS hardware.

Primary Goal:

```text
Stable Performance Before Visual Complexity
```

---

# Nintendo DS Display Architecture

Display Resolution:

```text
256 x 192
```

Screens:

```text
Main Engine
Sub Engine
```

Usage:

```text
Main Engine (Top Screen)
Gameplay
Battles
Cutscenes
```

```text
Sub Engine (Bottom Screen)
Menus
Touch Interface
Party Information
Mini Map
```

---

# Frame Lifecycle

Every frame:

```text
Input
  │
  ▼
Game Logic
  │
  ▼
Event Processing
  │
  ▼
Animation Updates
  │
  ▼
Camera Updates
  │
  ▼
Render Preparation
  │
  ▼
Draw Frame
  │
  ▼
VBlank
```

Target:

```text
60 FPS
```

Frame Time Budget:

```text
16.67 ms
```

---

# Top Screen Rendering

Primary Gameplay Screen.

Render Order:

```text
BG3
  ▼
BG2
  ▼
BG1
  ▼
Sprites
  ▼
Effects
```

---

## BG3

Purpose:

```text
Far Background
Sky
Distant Environment
```

Examples:

* Alfheim sky
* Muspelheim lava horizon
* Yggdrasil canopy

---

## BG2

Purpose:

```text
Primary Environment
```

Examples:

* Forests
* Villages
* Dungeons

---

## BG1

Purpose:

```text
Overlay Layer
```

Examples:

* Fog
* Shadows
* Light beams
* Weather effects

---

## Sprite Layer

Contains:

```text
Player
NPCs
Enemies
Bosses
Interactive Objects
```

Maximum OAM Objects:

```text
128
```

Recommended Visible:

```text
64
```

---

## Effect Layer

Rendered after sprites.

Examples:

```text
Spell Effects
Hit Effects
Rune Effects
Weather Effects
```

---

# Bottom Screen Rendering

Dedicated to interface systems.

Render Order:

```text
UI Background
  ▼
Menus
  ▼
Portraits
  ▼
Cursor
```

---

## UI Background

Contains:

```text
Window Frames
Status Panels
Menu Layouts
```

Always loaded.

---

## Menu Layer

Contains:

```text
Inventory
Equipment
Party
Quests
Settings
```

---

## Portrait Layer

Used for:

```text
Dialogue
Party Status
Character Menus
```

Portrait Size:

```text
128 x 128
```

Maximum Loaded:

```text
8
```

---

## Cursor Layer

Contains:

```text
Touch Cursor
Menu Selector
Target Indicator
```

Always rendered last.

---

# Exploration Rendering

Active Systems:

```text
Map
Player
NPCs
Events
Weather
UI
```

Update Frequency:

```text
60 FPS
```

Visible Tile Radius:

```text
Screen Area Only
```

Off-screen objects:

```text
Do Not Render
```

---

# Battle Rendering

Battle scene replaces exploration scene.

Render Order:

```text
Battle Background
  ▼
Enemies
  ▼
Party
  ▼
Effects
  ▼
Battle UI
```

---

## Battle Background

Single background image.

Examples:

```text
Forest
Barrow
Forge
Frozen Citadel
Yggdrasil Core
```

---

## Enemy Layer

Maximum:

```text
8 Enemies
```

Render Order:

```text
Back Row
Front Row
```

Largest enemies render first.

---

## Party Layer

Maximum:

```text
4 Characters
```

Party always renders above enemies.

---

## Battle Effects

Examples:

```text
Fire
Ice
Lightning
Healing
Critical Hits
Rune Skills
```

Maximum Simultaneous Effects:

```text
16
```

---

# Cutscene Rendering

Cutscenes may use:

```text
Dialogue
Portraits
Camera Motion
Full-Screen Images
```

---

## Dialogue Cutscenes

Top Screen:

```text
World View
```

Bottom Screen:

```text
Dialogue Window
Portrait
Choices
```

---

## Illustration Cutscenes

Top Screen:

```text
Full Illustration
```

Bottom Screen:

```text
Dialogue Window
```

---

# Camera System

Camera follows:

```text
Player
```

Default Behavior:

```text
Centered
```

Special Events:

```text
Move Camera
Pan
Focus Target
Shake
```

Supported By:

```text
MOVE_CAMERA
SHAKE_CAMERA
```

event commands.

---

# Animation Pipeline

Animation Update:

```text
Every Frame
```

Animation Structure:

```text
Frame Index
Duration
Loop Flag
```

Example:

```text
Walk Animation

Frame 0
Frame 1
Frame 2
Frame 3
```

---

# Transparency Rules

Allowed:

```text
UI
Weather
Spell Effects
Light Effects
```

Avoid:

```text
Large Full-Screen Transparency
```

Reason:

```text
High Performance Cost
```

---

# VRAM Allocation

Reference:

Memory_Budget.md

Allocation:

| Area               | Budget |
|--------------------|--------|
| Top Backgrounds    | 256 KB |
| Bottom Backgrounds | 128 KB |
| Sprites            | 128 KB |
| Effects            | 64 KB  |
| UI                 | 32 KB  |
| Reserve            | 48 KB  |

Total:

```text
656 KB
```

---

# Asset Loading

Always Loaded:

```text
Fonts
UI
Cursor
System Effects
```

Loaded Per Map:

```text
Tilesets
NPC Sprites
Map Music
Map Events
```

Loaded Per Battle:

```text
Enemy Sprites
Battle Background
Battle Effects
Battle Music
```

Unload Immediately:

```text
Completed Cutscene Assets
Unused Battle Assets
Temporary Event Graphics
```

---

# Culling Rules

Do Not Render:

```text
Off-Screen NPCs
Hidden Objects
Disabled Events
Invisible Sprites
```

Render Only:

```text
Visible Objects
```

---

# Performance Rules

Target:

```text
60 FPS
```

Required:

* Use sprite sheets.
* Reuse palettes.
* Minimize VRAM swaps.
* Minimize full-screen redraws.
* Batch animation updates.

Forbidden:

* Loading assets every frame.
* Full-screen alpha effects during gameplay.
* Excessive sprite scaling.
* Runtime image conversion.

---

# Debug Rendering

Debug Builds May Display:

```text
FPS Counter
VRAM Usage
Active Sprites
Collision Layer
Event Triggers
```

Release Builds:

```text
Disabled
```

---

# Rendering Limits

| System                      | Limit |
|-----------------------------|-------|
| OAM Sprites                 | 128   |
| Recommended Visible Sprites | 64    |
| Active Enemies              | 8     |
| Active Party Members        | 4     |
| Simultaneous Effects        | 16    |
| Loaded Portraits            | 8     |
| Cutscene Characters         | 16    |

---

# Technical Goal

```text
Provide stable dual-screen Nintendo DS rendering with consistent 60 FPS performance across exploration, battles, menus, and cutscenes.
```

---

End of File
