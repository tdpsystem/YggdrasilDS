# Yggdrasil Saga

## Coding Standards

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document establishes the programming standards used throughout **Yggdrasil Saga**.

It serves as the primary reference for:

- Gameplay Programming
- Engine Programming
- UI Programming
- Battle Systems
- Save Systems
- Event Scripting

Every system should be:

- Readable
- Maintainable
- Efficient
- Deterministic
- Compatible with Nintendo DS hardware

---

# Core Principles

Code should prioritise:

- Simplicity
- Performance
- Consistency
- Reusability

Readable code is preferred over clever code.

---

# Naming Conventions

## Files

Use:

```text
snake_case
```

Examples

```text
battle_system.cpp

enemy_ai.cpp

save_manager.cpp

event_flags.cpp
```

---

## Classes

Use:

```text
PascalCase
```

Examples

```cpp
BattleSystem

EnemyAI

SaveManager
```

---

## Functions

Use:

```text
camelCase
```

Examples

```cpp
loadGame()

calculateDamage()

updateAnimation()
```

---

## Variables

Use:

```text
camelCase
```

Examples

```cpp
playerLevel

enemyCount

currentRune
```

---

## Constants

Use:

```text
UPPER_CASE
```

Examples

```cpp
MAX_LEVEL

MAX_PARTY_SIZE

MAX_SAVE_SLOTS
```

---

## Enumerations

Use:

```cpp
enum class
```

Example

```cpp
enum class RuneType
{
    Craft,
    Radiance,
    Light,
    Growth,
    Giants,
    Ice,
    Fire,
    Wisdom,
    Death,
    Thunder
};
```

---

# File Structure

Every source file should follow:

```cpp
Includes

Constants

Enums

Structures

Class Definition

Implementation
```

---

# Function Design

Functions should:

- Perform one task
- Be short
- Return predictable results

Avoid:

- Hidden side effects
- Deep nesting
- Duplicate logic

---

# Comments

Comment **why**, not **what**.

Good

```cpp
// Prevent overflow on DS hardware.
```

Avoid

```cpp
// Increase HP.
hp++;
```

---

# Formatting

Indentation

```text
4 Spaces
```

Never use tabs.

---

Maximum line length

```text
100 characters
```

---

Opening braces

```cpp
if (condition)
{
}
```

---

# Memory Rules

Nintendo DS RAM is limited.

Avoid:

- Large stack allocations
- Frequent heap allocations
- Memory fragmentation

Prefer:

- Static allocation
- Object pools
- Fixed-size containers

---

# Performance Rules

Never:

- Allocate memory every frame
- Load assets during battle
- Perform unnecessary string operations

Cache expensive calculations whenever possible.

---

# Error Handling

Every public function should validate:

- Null pointers
- Array bounds
- Resource availability

Release builds should fail gracefully.

Debug builds should assert.

---

# Event Flags

All story progression must use:

```cpp
EventFlags
```

Never hardcode story progression.

Example

```cpp
if (eventFlags.has(FLAG_RUNE_FIRE_OBTAINED))
{
    unlockMuspelheim();
}
```

---

# Save Data

Never modify save structures directly.

Use:

```cpp
SaveManager
```

All save changes must pass checksum validation.

---

# Battle Code

Battle logic should be separated into:

- BattleSystem
- BattleFormula
- BattleAI
- StatusSystem

Avoid mixing UI with gameplay logic.

---

# UI Code

UI should never contain gameplay logic.

Menus display information.

Gameplay systems own the data.

---

# Asset Loading

Load assets through:

```cpp
AssetManager
```

Never reference raw asset paths directly inside gameplay code.

---

# Debug Builds

Include:

- Assertions
- Logging
- Performance Metrics
- Event Flag Viewer

Exclude from release builds.

---

# Version Control

Every commit should:

- Compile
- Pass unit tests
- Preserve save compatibility

Commit messages should follow:

```text
System: Short Description
```

Example

```text
Battle: Fix Rune Energy calculation
```

---

# Code Review Checklist

Before merging:

✓ Compiles

✓ Passes tests

✓ Follows naming conventions

✓ Meets performance requirements

✓ Canon compliant

✓ No duplicated code

---

# Canon Rules

Gameplay code must never hardcode lore.

Instead it should reference:

- Event Flags
- Quest Data
- Rune Data
- Realm Data

All narrative information originates from the game's data files, not source code.

---

# Canon Principles

- Maintain Nintendo DS compatibility.
- Prioritise readability over cleverness.
- Gameplay systems remain data-driven.
- Story progression is entirely event-flag based.
- Every gameplay system must remain consistent with **CANON_REFERENCE.md**.

---

**End of File**