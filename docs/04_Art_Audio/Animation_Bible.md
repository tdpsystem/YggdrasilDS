# Yggdrasil Saga

## Animation Bible

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document defines every animation standard used throughout **Yggdrasil Saga**.

It serves as the primary reference for:

- Character Animation
- Enemy Animation
- Boss Animation
- UI Animation
- Environmental Animation
- Cutscene Animation
- Effects

Every animation should reinforce readability first and visual appeal second.

---

# Animation Philosophy

Animations should be:

- Clear
- Responsive
- Expressive
- Efficient
- Optimised for Nintendo DS hardware

Silhouettes and movement should always communicate gameplay information.

---

# Technical Standards

## Frame Rate

Target

```text
60 FPS
```

Minimum

```text
30 FPS
```

---

## Sprite Base Size

Characters

```text
32×32
```

---

Enemies

```text
32×32

48×48

64×64
```

---

Bosses

```text
64×64

96×96

Multi-sprite
```

---

# Character Animations

---

## Idle

Frames

2

Purpose

Subtle breathing.

Hair and clothing movement.

---

## Walking

Frames

4

Directions

- North
- South
- East
- West

Total

16 Frames

---

## Running

Frames

4

Optional acceleration frames.

---

## Attack

Frames

4–6

Weapon-specific timing.

---

## Rune Skill

Frames

6

Includes:

- Charge
- Release
- Recovery

---

## Item Use

Frames

4

---

## Damage

Frames

2

Quick reaction.

---

## Knockback

Frames

3

---

## KO

Frames

4

Character collapses naturally.

---

## Victory

Frames

4

Unique pose per character.

---

# Companion Personality

Animations should reflect personality.

---

## Hero

Confident.

Balanced.

---

## Astrid

Strong.

Grounded.

Minimal flourish.

---

## Eirik

Light-footed.

Precise.

---

## Thora

Heavy.

Mechanical.

Powerful.

---

## Thrym

Deliberate.

Massive.

Controlled.

---

## Ratatoskr

Fast.

Energetic.

Expressive.

Almost constantly moving.

Tail should animate frequently.

---

# NPC Animations

Standard NPCs

- Idle
- Walk
- Talk

Important NPCs additionally receive:

- Gesture
- Surprise
- Bow
- Laugh
- Think

---

# Enemy Animations

Minimum

- Idle
- Attack
- Damage
- Death

---

Advanced enemies additionally receive:

- Cast
- Charge
- Special Attack

---

# Boss Animations

Every boss requires:

Idle

Walk (if applicable)

Attack A

Attack B

Special Attack

Damage

Phase Transition

Defeat

---

# Story Boss Personality

---

## Draugr Jarl

Heavy.

Deliberate.

Undead.

---

## Shade Warden

Elegant.

Floating.

Unpredictable.

---

## Forgemind Construct

Mechanical.

Rigid.

Clockwork precision.

---

## Season Keeper

Smooth.

Natural.

Changes stance every phase.

---

## Thrym

Powerful.

Minimal wasted movement.

---

## Primordial Wyrm

Serpentine.

Fluid.

Ancient.

---

## Surtr

Slow.

Deliberate.

Fire trails.

Never frantic.

---

## Einherjar Commander

Disciplined.

Military.

Perfect posture.

---

## Memory of the Last Hero

Mirrors Hero animations.

Slightly slower.

Melancholic.

---

## Loki

Early phases:

Relaxed.

Confident.

Late phases:

Determined.

Controlled.

Never rage-driven.

---

## Níðhöggr

Ancient.

Massive.

Root-like movement.

---

# Environmental Animation

Examples

Trees

2 Frames

---

Water

4 Frames

---

Fire

4 Frames

---

Lava

4 Frames

---

Rune Crystals

4 Frames

---

Snow

Particle Animation

---

Leaves

Particle Animation

---

# UI Animation

Buttons

2 Frames

---

Cursor

4 Frames

---

Menu Open

8 Frames

---

Dialogue Portrait

Fade

2 Frames

---

# Cutscene Animation

Camera movement should remain simple.

Primary tools

- Fade
- Pan
- Zoom
- Shake

Avoid cinematic complexity beyond DS capabilities.

---

# Visual Effects

## Light

Soft glow.

---

## Fire

Expanding flame.

---

## Ice

Crystalline growth.

---

## Thunder

Instant flash.

---

## Growth

Vines.

Leaves.

---

## Death

Spirit particles.

---

## Wisdom

Floating runes.

---

## Covenant Resonance

Every Covenant Rune has a unique visual pulse.

These effects should remain visually consistent across:

- Combat
- Cutscenes
- UI
- Dungeons

---

# Animation Budget

Maximum simultaneously animated sprites

```text
96
```

Maximum practical particle systems

```text
16
```

Boss effects should remain within Nintendo DS performance limits.

---

# Canon Principles

- Animation prioritises gameplay readability.
- Ratatoskr is the most expressive character in the game.
- Loki's animations become more restrained as the story progresses.
- Boss movement reflects personality rather than spectacle.
- Covenant Rune effects remain visually consistent throughout the game.
- All animation standards target authentic Nintendo DS hardware.

---

**End of File**