# Yggdrasil Saga

## Build Configuration

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document defines the build configurations used throughout the development of **Yggdrasil Saga**.

It serves as the primary reference for:

- Build Types
- Compiler Settings
- Platform Targets
- Debug Options
- Release Configuration
- Version Numbering

All builds should remain compatible with authentic Nintendo DS hardware.

---

# Build Targets

## Primary Target

Nintendo DS

---

## Supported Hardware

- Nintendo DS
- Nintendo DS Lite
- Nintendo DSi
- Nintendo 3DS (Backward Compatibility)

---

## Supported Emulators

- melonDS
- DeSmuME
- RetroArch

---

# Build Types

---

## Debug

Purpose

Internal development.

Enabled Features

- Debug Console
- Event Flag Viewer
- AI Viewer
- FPS Counter
- Collision Viewer
- Memory Statistics
- Logging

Optimisation

Disabled

Assertions

Enabled

---

## Development

Purpose

Daily development builds.

Enabled

- Logging
- Assertions
- Debug Commands

Disabled

- Cheat Menu
- Memory Viewer

Optimisation

Basic

---

## QA

Purpose

Internal testing.

Enabled

- Performance Logging
- Crash Reports
- Save Verification

Disabled

- Developer Tools

Optimisation

Release Equivalent

---

## Release Candidate

Purpose

Pre-release verification.

Enabled

- Save Validation
- Error Reporting

Disabled

- Debug Systems
- Console Output
- Developer Commands

Optimisation

Full

---

## Gold Master

Purpose

Final production ROM.

Enabled

- Save Recovery
- Error Handling

Disabled

Everything intended only for development.

Optimisation

Maximum

---

# Version Format

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

# Build Naming

Development

```text
YS_DEV_001
```

---

Vertical Slice

```text
YS_VS_001
```

---

Alpha

```text
YS_A_001
```

---

Beta

```text
YS_B_001
```

---

Release Candidate

```text
YS_RC1
```

---

Gold Master

```text
YS_GM
```

---

# Compiler Settings

Optimisation

Release

```text
-O2
```

---

Debug

```text
-O0
```

---

Warnings

Treat warnings as errors.

Unused variables prohibited.

---

Language Standard

C++17

(or project standard if targeting devkitPro constraints)

---

# Memory Configuration

Main RAM

4 MB

---

VRAM

656 KB

---

Maximum ROM

128 MB

---

Maximum Save

64 KB

---

# Asset Packaging

Assets packaged into:

```text
/data
```

Subdirectories

```text
gfx/

audio/

maps/

scripts/

text/

ui/

save/
```

---

# Debug Features

Available only in Debug builds.

- Teleport
- Event Flags
- Battle Skip
- Boss Selector
- FPS Counter
- Collision Overlay
- Memory Viewer

---

# Logging

Debug

Verbose

---

Development

Standard

---

QA

Errors

Warnings

---

Release

Critical Errors Only

---

# Save Validation

Every build verifies:

- Save Header
- Version Number
- Checksum

Invalid saves attempt automatic recovery.

---

# Performance Validation

Every Release Candidate must verify:

- Exploration
- Battle
- Menus
- Cutscenes

Target

```text
60 FPS
```

Minimum

```text
30 FPS
```

---

# Build Checklist

Before creating any Release Candidate:

✓ Compiles successfully

✓ No compiler warnings

✓ Unit tests pass

✓ Save compatibility verified

✓ Canon verified

✓ Documentation updated

---

# Release Checklist

Before Gold Master:

✓ QA Approved

✓ Localization Complete

✓ Performance Verified

✓ Save Migration Tested

✓ Asset Pipeline Complete

✓ Documentation Archived

---

# Build Archive

Every released build should archive:

- Source Revision
- Build Number
- Documentation Version
- Asset Version
- Localization Version

---

# Canon Principles

- Every build must remain consistent with **CANON_REFERENCE.md**.
- Debug tools must never appear in release builds.
- Save compatibility must be preserved across versions.
- Nintendo DS hardware remains the primary target platform.
- Gold Master represents the definitive release build.

---

**End of File**