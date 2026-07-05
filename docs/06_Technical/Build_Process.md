# Build_Process

## Yggdrasil Saga

Version: 1.0

Purpose:

Define the complete workflow used to build, test, package, and release Yggdrasil Saga.

This document serves as the reference for daily development builds, milestone builds, testing builds, release
candidates, and final ROM generation.

---

# Build Philosophy

Goals:

* Repeatable builds
* Consistent output
* Easy debugging
* Reliable testing
* Reproducible releases

Primary Principle:

```text
Every Build Must Be Reproducible
```

A build created from the same source revision must always produce identical results.

---

# Build Types

## Development Build

Purpose:

```text
Daily development
```

Includes:

* Debug logging
* Debug menus
* FPS counter
* Event viewer
* Collision viewer
* Memory statistics

Filename:

```text
yggdrasil_dev.nds
```

---

## Test Build

Purpose:

```text
QA testing
```

Includes:

* Logging
* Error reporting
* Crash information

Excludes:

* Debug cheats
* Developer tools

Filename:

```text
yggdrasil_test.nds
```

---

## Milestone Build

Purpose:

```text
Major project review
```

Examples:

```text
v0.1.0
v0.5.0
v1.0.0
```

Used for:

* Playtesting
* Progress evaluation
* Documentation validation

Filename:

```text
yggdrasil_v0_1_0.nds
```

---

## Release Candidate

Purpose:

```text
Final testing
```

Naming:

```text
RC1
RC2
RC3
```

Example:

```text
yggdrasil_rc1.nds
```

---

## Gold Master

Purpose:

```text
Final release build
```

Filename:

```text
yggdrasil_v1_3_0.nds
```

Reference:

```text
Build_Changelog.md
Release_Plan.md
```

---

# Build Pipeline Overview

```text
Source Code
      │
      ▼
Compile
      │
      ▼
Convert Assets
      │
      ▼
Package Data
      │
      ▼
Link Executable
      │
      ▼
Build ROM
      │
      ▼
Validate
      │
      ▼
Test
      │
      ▼
Release
```

---

# Source Structure

```text
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
/data
/docs
```

Reference:

```text
NDS_Architecture.md
```

---

# Build Environment

Target Platform:

```text
Nintendo DS
```

Compiler:

```text
devkitARM
```

SDK:

```text
libnds
```

Build System:

```text
Makefile
```

Recommended IDEs:

```text
CLion
VS Code
Code::Blocks
```

---

# Compilation Stage

Compile Order:

```text
Core
Graphics
Audio
Input
World
Battle
UI
Save
Events
```

Output:

```text
.elf
```

Example:

```text
yggdrasil.elf
```

---

# Asset Conversion Stage

Input:

```text
PNG
WAV
MOD
MAP
EVT
```

Output:

```text
Converted Runtime Assets
```

Tasks:

* Palette conversion
* Compression
* Tile generation
* Sprite sheet generation
* Audio conversion

Reference:

```text
Asset_Pipeline.md
```

---

# Asset Validation Stage

Validate:

* Dimensions
* Palette size
* Compression
* Naming convention
* Memory usage

Reject:

* Invalid filenames
* Oversized assets
* Missing references
* Unsupported formats

---

# Data Packaging Stage

Package:

```text
Maps
Events
Databases
Dialogue
Assets
```

Into:

```text
ROM filesystem
```

Structure:

```text
/data
/assets
```

All file references must resolve successfully.

---

# ROM Generation

Input:

```text
yggdrasil.elf
assets
data
```

Output:

```text
yggdrasil.nds
```

Build Metadata:

```text
Version
Build Number
Build Date
Git Revision
```

Embedded into ROM header.

---

# Validation Stage

Required Checks:

* ROM boots successfully
* Title screen loads
* Save system initializes
* Asset loading succeeds
* No missing file references
* No fatal startup errors

Automated Validation:

```text
PASS
FAIL
```

Only.

---

# Debug Build Features

Enabled:

```text
FPS Counter
Memory Viewer
VRAM Viewer
Collision Viewer
Event Viewer
Warp Viewer
```

Developer Commands:

```text
Unlock Realms
Add Rune
Spawn Item
Toggle Flags
Force Battle
```

Reference:

```text
Save_System_Implementation.md
```

Debug saves must never ship in release builds.

---

# Testing Stage

Minimum Test Flow:

```text
Boot
New Game
Midgard
Draugr Barrow
Draugr Jarl
Rune of Light
Save
Load
Return to Title
```

Build fails certification if this flow breaks.

---

# Automated Checks

Every build must verify:

```text
No Missing Assets
No Missing Maps
No Missing Events
No Missing Dialogue
No Broken Save Files
```

Warnings allowed.

Errors not allowed.

---

# Performance Verification

Check:

```text
FPS
Memory Usage
VRAM Usage
Loading Times
```

Targets:

| System      | Target      |
|-------------|-------------|
| Exploration | 60 FPS      |
| Battle      | 60 FPS      |
| Menus       | 60 FPS      |
| Cutscenes   | 30–60 FPS   |
| Loading     | < 3 Seconds |

Reference:

```text
Rendering_Pipeline.md
Memory_Budget.md
```

---

# Build Numbering

Format:

```text
Major.Minor.Patch
```

Examples:

```text
0.1.0
0.5.0
1.0.0
1.3.0
```

Meaning:

| Value | Purpose           |
|-------|-------------------|
| Major | Major milestone   |
| Minor | Feature additions |
| Patch | Bug fixes         |

---

# Milestone Build Requirements

## v0.1.0

Vertical Slice

Required:

* Midgard complete
* Astrid joins
* Draugr Jarl battle
* Rune of Light
* Save system

---

## v0.5.0

Midgame

Required:

* Through Jötunheim
* All current classes
* Core battle system complete

---

## v1.0.0

Content Complete

Required:

* All realms complete
* All bosses complete
* All endings playable

---

## v1.3.0

Gold Master

Required:

* No known critical bugs
* Performance targets met
* Final balancing complete

---

# Release Packaging

Release Bundle:

```text
ROM
Documentation
Changelog
License
```

Example:

```text
YggdrasilSaga_v1_3_0.zip
```

Contents:

```text
yggdrasil_v1_3_0.nds
manual.pdf
changelog.txt
```

---

# Failure Conditions

Build must fail if:

* Compilation fails
* Asset conversion fails
* Missing required asset
* Missing event script
* Save system fails validation
* Memory budget exceeded

Reference:

```text
Memory_Budget.md
NDS_Hardware_Limits.md
```

---

# Build Archiving

Archive:

* Every milestone build
* Every release candidate
* Every gold master build

Location:

```text
/builds/archive
```

Naming:

```text
YYYY_MM_DD_version
```

Example:

```text
2026_07_15_v0_1_0
```

---

# Development Rule

Before merging any feature:

```text
Feature
  │
  ▼
Build
  │
  ▼
Validate
  │
  ▼
Test
  │
  ▼
Merge
```

Never merge untested content.

---

# Technical Goal

```text
Produce stable, repeatable Nintendo DS ROM builds throughout development while ensuring every milestone remains playable and verifiable.
```

---

End of File
