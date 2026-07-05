# NDS_Architecture

## Yggdrasil Saga

Version: 1.0

Purpose:
Define the overall software architecture for the Nintendo DS implementation of Yggdrasil Saga.

This document describes system organization, runtime flow, memory usage, rendering structure, and subsystem
responsibilities.

---

# Target Platform

Platform:
Nintendo DS

Primary Hardware:

```text id="wcpbqf"
ARM9 CPU
ARM7 CPU
```

Screen Layout:

```text id="6jicgw"
Top Screen:
Gameplay

Bottom Screen:
Menus
Touch Controls
Party Information
Maps
```

Resolution:

```text id="x0i0b4"
256 x 192
```

Frame Rate Target:

```text id="orqlk8"
60 FPS
```

Minimum Acceptable:

```text id="1c6q7q"
30 FPS
```

---

# Engine Overview

```text id="3z1d3z"
Game
│
├── Core
├── Graphics
├── Audio
├── Input
├── World
├── Battle
├── UI
├── Save
├── Events
└── Resources
```

Architecture Style:

```text id="8i0ol8"
Manager-Based Architecture
```

Reason:

* Easy to understand
* Suitable for small team / solo development
* Common in DS-era RPGs

---

# Runtime Flow

```text id="f0o8ov"
Boot
  │
  ▼
Title Screen
  │
  ▼
Main Menu
  │
  ▼
Load/New Game
  │
  ▼
World Exploration
  │
  ├── Dialogue
  ├── Shops
  ├── Quests
  ├── Cutscenes
  └── Battles
  │
  ▼
Save
  │
  ▼
Shutdown
```

---

# Core Systems

## Game Manager

Responsibilities:

* Main loop
* Scene transitions
* Global state

Singleton:

```text id="vf11rx"
GameManager
```

---

## Scene Manager

Responsibilities:

* Load scenes
* Unload scenes
* Scene switching

Supported Scenes:

```text id="pzxdr7"
TitleScene
WorldScene
BattleScene
MenuScene
CutsceneScene
SaveScene
```

---

## Resource Manager

Responsibilities:

* Load assets
* Cache assets
* Free unused resources

Managed Resources:

* Sprites
* Maps
* Audio
* Scripts

---

# Graphics Architecture

## Screen Usage

Top Screen:

```text id="efqj5f"
World Exploration
Battle Graphics
Cutscenes
```

Bottom Screen:

```text id="4g7ahf"
Menus
Touch Interface
Mini Map
Party Information
```

---

## Rendering Layers

Top Screen:

```text id="0wljgx"
BG3
BG2
BG1
Sprites
```

Bottom Screen:

```text id="s9n5zn"
UI Background
Menu Layer
Cursor Layer
```

---

## Sprite Manager

Responsibilities:

* Sprite allocation
* Animation updates
* Visibility control

Supported Sprite Types:

```text id="q1dgya"
Player
NPC
Enemy
Boss
UI
```

---

# Input Architecture

Input Sources:

```text id="zjg6g3"
D-Pad
A Button
B Button
X Button
Y Button
L
R
Start
Select
Touch Screen
```

---

## Input Manager

Responsibilities:

* Poll hardware
* Process touch input
* Input buffering

Functions:

```text id="px9jlwm"
IsPressed()
IsHeld()
IsReleased()
GetTouchPosition()
```

---

# World System

## World Manager

Responsibilities:

* Current realm
* Current map
* World transitions

Supported Realms:

```text id="lh5n53"
Midgard
Alfheim
Svartalfheim
Vanaheim
Jötunheim
Niflheim
Muspelheim
Asgard
Helheim
Yggdrasil
```

---

## Map Manager

Responsibilities:

* Load maps
* Collision handling
* Event triggers
* NPC placement

Map Components:

```text id="5a0jeq"
Tiles
Collision
Events
NPCs
Warps
```

---

# Event System

## Event Manager

Responsibilities:

* Story progression
* Cutscenes
* Quest events

Uses:

```text id="pg1h8m"
Event Flags
Script Files
```

Event Sources:

```text id="m8l8i0"
NPC
Trigger Tile
Boss Defeat
Quest Completion
```

---

# Dialogue System

Structure:

```text id="c59ahz"
Dialogue
 ├─ Speaker
 ├─ Portrait
 ├─ Text
 └─ Choices
```

Features:

* Portrait support
* Branching choices
* Event flag integration

---

# Quest System

Quest States:

```text id="a1n5rj"
Locked
Active
Complete
```

Quest Manager Responsibilities:

* Track progress
* Reward completion
* Trigger events

---

# Battle Architecture

## Battle Manager

Responsibilities:

* Turn processing
* Skill execution
* Victory conditions

---

## Battle Flow

```text id="v7sd8e"
Battle Start
    │
    ▼
Determine Turn Order
    │
    ▼
Player Actions
    │
    ▼
Enemy Actions
    │
    ▼
Victory?
    │
    ├── No
    │      ▲
    │      │
    └──────┘
    │
    ▼
Rewards
    │
    ▼
Return To World
```

---

## Battle Components

```text id="zr0h9g"
Party
Enemies
Skills
Status Effects
Rewards
```

---

# Save System

## Save Manager

Responsibilities:

* Save game
* Load game
* Version validation

Slots:

```text id="ep4qq0"
3
```

Storage:

```text id="7odtdf"
SRAM / Save File
```

---

# Audio Architecture

## Audio Manager

Responsibilities:

* Music playback
* Sound effects
* Volume control

Audio Types:

```text id="44s0h7"
BGM
SFX
Voice Stingers
```

---

# Memory Management

Goals:

* Avoid fragmentation
* Minimize allocations
* Reuse buffers

Strategy:

```text id="m5d4zn"
Load Once
Reuse Often
Unload Rarely Used Assets
```

---

# Asset Loading

Loaded Permanently:

```text id="x1tihd"
UI
Fonts
Common Effects
```

Loaded Per Map:

```text id="m54txv"
Map Tiles
NPC Sprites
Map Music
Events
```

Loaded Per Battle:

```text id="kjm4an"
Enemy Sprites
Battle Background
Battle Music
```

---

# File Organization

```text id="f2yn4h"
/source
    core/
    graphics/
    audio/
    input/
    world/
    battle/
    ui/
    save/

/assets
    maps/
    sprites/
    audio/
    ui/

/data
    events/
    databases/
    saves/
```

---

# Performance Targets

World Exploration:

```text id="7v2v8j"
60 FPS
```

Battle:

```text id="i4lzw7"
60 FPS
```

Cutscenes:

```text id="52mjjlwm"
30-60 FPS
```

Loading Screens:

```text id="mymjlh"
< 3 seconds
```

---

# Error Handling

Required Checks:

* Missing asset
* Invalid save file
* Missing event script
* Invalid database entry

Fallback Strategy:

```text id="wqmbiq"
Log Error
Display Message
Continue Safely
```

---

# Future Expansion

Architecture must support:

* Additional quests
* Additional equipment
* Additional enemies
* Additional cutscenes
* Additional postgame content

Without changing save format.

---

# Technical Goals

Primary Goal:

```text id="0gfym7"
Stable Nintendo DS JRPG
```

Secondary Goal:

```text id="a6gts7"
Maintainable Codebase
```

Final Goal:

```text id="g6hpf5"
Complete Playable Experience
```

---

End of File
