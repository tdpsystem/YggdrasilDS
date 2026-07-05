# Memory_Budget

## Yggdrasil Saga

Version: 1.0

Purpose:

Define memory allocation targets and hardware usage limits for the Nintendo DS implementation of Yggdrasil Saga.

This document ensures all game systems remain within Nintendo DS hardware constraints while maintaining stable
performance.

---

# Nintendo DS Memory Overview

Main RAM:

```text
4 MB
```

ARM9 ITCM:

```text
32 KB
```

ARM9 DTCM:

```text
16 KB
```

VRAM:

```text
656 KB
```

Palette Memory:

```text
2 KB per engine
```

OAM Memory:

```text
2 KB per engine
```

Save Memory:

```text
512 KB Cartridge SRAM
```

Target Usage:

```text
Maximum Runtime Usage:
85% of available RAM
```

Reserved Safety Margin:

```text
15%
```

---

# RAM Budget

| System         | Budget   |
|----------------|----------|
| Core Engine    | 256 KB   |
| Graphics       | 1,024 KB |
| Audio          | 512 KB   |
| Maps           | 768 KB   |
| Events         | 128 KB   |
| Battle System  | 384 KB   |
| Save System    | 64 KB    |
| UI             | 256 KB   |
| Resource Cache | 512 KB   |
| Free Reserve   | 192 KB   |

Total:

```text
4 MB
```

---

# VRAM Budget

Total VRAM:

```text
656 KB
```

Allocation:

| Purpose                   | Budget |
|---------------------------|--------|
| Top Screen Backgrounds    | 256 KB |
| Bottom Screen Backgrounds | 128 KB |
| Sprites                   | 128 KB |
| Battle Effects            | 64 KB  |
| UI Graphics               | 32 KB  |
| Reserve                   | 48 KB  |

---

# Sprite Memory Budget

Player Sprites:

```text
32 KB
```

NPC Sprites:

```text
32 KB
```

Enemy Sprites:

```text
48 KB
```

Boss Sprites:

```text
64 KB
```

UI Sprites:

```text
16 KB
```

Maximum Active Sprites:

```text
128
```

Recommended Visible Sprites:

```text
64
```

---

# Map Memory Budget

Maximum Loaded Map:

```text
256 x 256 tiles
```

Map Allocation:

| Component       | Budget |
|-----------------|--------|
| Tile Data       | 256 KB |
| Collision       | 64 KB  |
| Event Data      | 64 KB  |
| NPC Data        | 64 KB  |
| Runtime Objects | 128 KB |

Total:

```text
576 KB
```

---

# Audio Budget

Music Buffer:

```text
256 KB
```

Sound Effects:

```text
128 KB
```

Voice Stingers:

```text
64 KB
```

Streaming Buffer:

```text
64 KB
```

Total:

```text
512 KB
```

---

# Battle Memory Budget

Allocated During Battle:

| Component         | Budget |
|-------------------|--------|
| Enemy Data        | 64 KB  |
| Battle Background | 128 KB |
| Effects           | 64 KB  |
| Battle UI         | 64 KB  |
| Turn Data         | 32 KB  |
| Animation Data    | 32 KB  |

Total:

```text
384 KB
```

---

# Save System Memory

Maximum Save File:

```text
64 KB
```

Working Buffer:

```text
64 KB
```

Maximum Save Slots:

```text
3
```

Total Reserved:

```text
192 KB
```

---

# Event System Memory

Event Scripts:

```text
64 KB
```

Event Flags:

```text
4 KB
```

Quest Data:

```text
32 KB
```

Dialogue Buffers:

```text
28 KB
```

Total:

```text
128 KB
```

---

# UI Memory Budget

Fonts:

```text
64 KB
```

Menus:

```text
96 KB
```

Portrait Graphics:

```text
64 KB
```

Touch Interface:

```text
32 KB
```

Total:

```text
256 KB
```

---

# Realm Asset Targets

Per Realm Loaded Assets:

| Asset Type      | Limit |
|-----------------|-------|
| NPC Sprites     | 32    |
| Enemy Types     | 24    |
| Unique Tilesets | 4     |
| Music Tracks    | 3     |
| Event Scripts   | 128   |
| Active Quests   | 32    |

---

# Battle Limits

Maximum Party Size:

```text
4
```

Maximum Enemies:

```text
8
```

Maximum Status Effects Per Unit:

```text
8
```

Maximum Active Animations:

```text
16
```

---

# Cutscene Limits

Maximum Characters On Screen:

```text
16
```

Maximum Portraits Loaded:

```text
8
```

Maximum Dialogue Choices:

```text
8
```

Maximum Script Length:

```text
64 KB
```

---

# Asset Streaming Rules

Always Loaded:

```text
UI Assets
Fonts
Common Effects
System Sounds
```

Load Per Map:

```text
Map Tiles
NPC Sprites
Map Events
Map Music
```

Load Per Battle:

```text
Enemy Sprites
Battle Background
Battle Effects
Battle Music
```

Unload Immediately:

```text
Unused Battle Assets
Completed Cutscene Assets
Temporary Event Resources
```

---

# Memory Safety Rules

Required:

* Check allocation success.
* Validate asset size before loading.
* Free unused resources immediately.
* Reuse buffers whenever possible.
* Avoid runtime heap fragmentation.

Forbidden:

* Loading entire realm asset sets simultaneously.
* Keeping battle assets loaded during exploration.
* Duplicate sprite allocations.
* Dynamic allocation every frame.

---

# Performance Targets

Exploration:

```text
60 FPS
```

Battle:

```text
60 FPS
```

Menu Navigation:

```text
60 FPS
```

Cutscenes:

```text
30–60 FPS
```

Memory Fragmentation Target:

```text
< 5%
```

Loading Time Target:

```text
< 3 seconds
```

---

# Development Rule

If a new feature exceeds its assigned memory budget:

1. Optimize existing assets.
2. Reduce asset count.
3. Compress data.
4. Stream resources.
5. Increase allocation only if sufficient reserve memory remains.

Memory stability takes priority over visual fidelity.

---

# Technical Goal

```text
Maintain stable 60 FPS gameplay on real Nintendo DS hardware while supporting the full content scope of Yggdrasil Saga.
```

---

End of File
