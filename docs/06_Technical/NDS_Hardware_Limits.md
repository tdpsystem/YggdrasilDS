# NDS_Hardware_Limits

## Yggdrasil Saga

Version: 1.0

Purpose:

Define the Nintendo DS hardware limitations that must be respected throughout development of Yggdrasil Saga.

This document serves as the technical boundary reference for all systems, assets, rendering, audio, maps, and gameplay
features.

---

# Target Hardware

Primary Platform:

```text
Nintendo DS
```

Supported Systems:

```text
Nintendo DS
Nintendo DS Lite
Nintendo DSi (Compatibility Mode)
Nintendo 3DS (DS Mode)
Emulators
```

Development Target:

```text
Original Nintendo DS
```

All systems must perform correctly on original DS hardware.

---

# CPU Limits

## ARM9 Processor

Primary Game CPU

Clock Speed:

```text
67 MHz
```

Responsibilities:

```text
Gameplay
Rendering
Battle Logic
AI
Events
Input
```

---

## ARM7 Processor

Secondary Processor

Clock Speed:

```text
33 MHz
```

Responsibilities:

```text
Audio
Wireless
System Functions
```

---

# Memory Limits

Main RAM:

```text
4 MB
```

Available To Game:

```text
Approximately 3.4 MB
```

Target Usage:

```text
Maximum 85%
```

Reference:

```text
Memory_Budget.md
```

---

# VRAM Limits

Total VRAM:

```text
656 KB
```

Allocation Target:

| Area             | Budget |
|------------------|--------|
| Main Backgrounds | 256 KB |
| Sub Backgrounds  | 128 KB |
| Sprites          | 128 KB |
| Effects          | 64 KB  |
| UI               | 32 KB  |
| Reserve          | 48 KB  |

---

# Display Limits

Screen Resolution:

```text
256 x 192
```

Screen Count:

```text
2
```

Color Depth:

```text
15-bit RGB
```

Maximum Colors:

```text
32768
```

Preferred Usage:

```text
16-color palettes
256-color palettes
```

---

# Sprite Limits

Maximum Hardware Sprites:

```text
128 per screen
```

Recommended Visible Sprites:

```text
64
```

Maximum Sprite Size:

```text
64 x 64
```

Large bosses must be constructed from:

```text
Multiple Sprites
```

Example:

```text
128x128 Boss

=
4 x 64x64 sprites
```

---

# Background Limits

Background Layers Per Screen:

```text
4
```

Recommended Usage:

```text
BG3 = Far Background
BG2 = Main Environment
BG1 = Overlay
BG0 = Reserved/UI
```

Maximum Tile Size:

```text
8x8
```

---

# OAM Limits

Object Attribute Memory:

```text
128 sprite entries
```

Per Screen.

Avoid:

```text
Sprite Overflow
```

Overflow may cause:

* Flickering
* Missing sprites
* Incorrect rendering

---

# Palette Limits

Sprite Palette Memory:

```text
16 KB
```

Background Palette Memory:

```text
16 KB
```

Recommended:

* Reuse palettes
* Shared NPC palettes
* Shared enemy palettes

---

# Tile Limits

Tile Size:

```text
8x8
```

Map Construction:

```text
Tile Based
```

Recommended Maximum Map:

```text
256x256 tiles
```

Larger maps should be split into:

```text
Multiple Areas
```

---

# Audio Limits

Audio Channels:

```text
16
```

Recommended Simultaneous Usage:

```text
8–12
```

to preserve performance.

---

## Sound Effects

Format:

```text
22050 Hz
16-bit Mono
```

Preferred.

Maximum Size:

```text
100 KB
```

per effect.

---

## Music

Preferred Format:

```text
MOD
```

Alternative:

```text
Streamed Audio
```

Loop points required.

---

# Save Limits

Maximum Save Slots:

```text
3
```

Maximum Quick Saves:

```text
1
```

Maximum Save Size:

```text
64 KB
```

Reference:

```text
Save_System_Implementation.md
```

---

# Input Limits

Available Controls:

```text
D-Pad
A
B
X
Y
L
R
Start
Select
Touch Screen
```

Unsupported:

```text
Analog Input
Second Touch Point
```

---

# Battle Limits

Maximum Party Members:

```text
4 Active
```

Maximum Stored Members:

```text
5
```

Maximum Enemies:

```text
8
```

Maximum Simultaneous Effects:

```text
16
```

Maximum Active Status Effects:

```text
8 Per Unit
```

---

# Dialogue Limits

Maximum Dialogue Entry ID:

```text
99999
```

Maximum Choice Options:

```text
8
```

Maximum Loaded Portraits:

```text
8
```

Portrait Resolution:

```text
128x128
```

---

# Event System Limits

Maximum Event Flags:

```text
2048
```

Maximum Scripts Per Map:

```text
128
```

Maximum Commands Per Script:

```text
256
```

Maximum Conditional Depth:

```text
3
```

Reference:

```text
Event_Scripting_Reference.md
```

---

# Asset Limits

## Character Sprites

Runtime Size:

```text
32x32
```

---

## NPC Sprites

Runtime Size:

```text
32x32
```

---

## Enemy Sprites

Runtime Size:

```text
64x64
```

---

## Boss Sprites

Recommended:

```text
128x128
```

Absolute Maximum:

```text
256x192
```

using multiple hardware sprites.

---

# Cutscene Limits

Maximum Characters On Screen:

```text
16
```

Maximum Simultaneous Portraits:

```text
8
```

Maximum Illustration Size:

```text
256x192
```

Per screen.

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

Menus:

```text
60 FPS
```

Cutscenes:

```text
30–60 FPS
```

Loading Screens:

```text
< 3 Seconds
```

---

# Technical Restrictions

Required:

* Tile-based maps.
* Palette sharing.
* Asset streaming.
* VRAM budgeting.
* Memory reuse.

Avoid:

* Runtime decompression of large assets.
* Full-screen transparency.
* Excessive sprite scaling.
* Loading assets every frame.
* Oversized boss graphics.

Forbidden:

* Exceeding VRAM budget.
* Exceeding OAM limits.
* Exceeding save file size.
* Dynamic memory allocation every frame.

---

# Development Rule

Whenever a system design conflicts with Nintendo DS hardware limitations:

```text
Hardware Limitations Take Priority
```

Gameplay systems, art assets, and visual effects must be redesigned rather than exceeding platform constraints.

---

# Technical Goal

```text
Ensure Yggdrasil Saga remains fully playable on original Nintendo DS hardware while maintaining stable performance and consistent visual quality.
```

---

End of File
