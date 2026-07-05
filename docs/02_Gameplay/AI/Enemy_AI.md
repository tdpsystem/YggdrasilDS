# Enemy AI

# Yggdrasil Saga

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document defines the artificial intelligence behaviour used by enemies and bosses throughout **Yggdrasil Saga**.

It serves as the primary reference for:

- Enemy Behaviour
- Boss Behaviour
- Difficulty Scaling
- Skill Selection
- Target Selection
- AI States
- Mythic AI

Enemy AI should create encounters that feel intelligent without appearing unfair.

---

# Design Philosophy

Enemy AI should:

- Reward tactical play
- Punish predictable strategies
- Reinforce each realm's identity
- Showcase boss personalities
- Remain deterministic enough for players to learn

Enemies should never feel random.

Players should succeed by understanding behaviour patterns.

---

# AI Priority System

Every enemy follows this order.

```text
1. Survival
2. Special Mechanics
3. Offensive Action
4. Support Action
5. Basic Attack
```

---

# AI States

Every enemy uses one of the following states.

## Idle

Waiting.

Only used outside battle.

---

## Aggressive

Primary combat behaviour.

Uses strongest available attacks.

---

## Defensive

Prioritises:

- Guard
- Buffs
- Healing

Triggered by:

Low HP.

---

## Support

Prioritises:

- Buff allies
- Heal allies
- Apply status effects

---

## Desperation

Activated below:

```text
25% HP
```

Bosses often unlock additional attacks.

---

# Target Selection

Enemies score each player.

Priority:

1. Lowest HP
2. Lowest DEF
3. Highest Threat
4. Random Tie Break

Bosses may ignore this when scripted.

---

# Threat System

Threat increases when:

- Dealing damage
- Healing allies
- Using buffs
- Using Rune Skills
- Reviving allies

Guardians naturally generate additional Threat.

---

# Skill Selection

Enemy skills are selected using weighted priorities.

Example:

```text
Heavy Attack
40%

Status Skill
25%

Buff
15%

Heal
10%

Basic Attack
10%
```

Weights may change dynamically.

---

# Boss AI

Bosses are phase-based.

Every phase introduces:

- New attacks
- New priorities
- New arena mechanics

Bosses never repeat identical behaviour throughout an encounter.

---

# Phase Triggers

Default thresholds.

## Phase I

100%–75%

Tutorial phase.

---

## Phase II

74%–50%

Introduces mechanics.

---

## Phase III

49%–25%

Aggressive behaviour.

---

## Final Phase

24%–0%

Desperation mechanics.

Unique attacks.

---

# Realm Behaviour Themes

## Midgard

Simple.

Aggressive.

Few abilities.

---

## Alfheim

Magic.

Status effects.

Movement.

---

## Svartalfheim

Constructs.

Defensive.

Rune attacks.

---

## Vanaheim

Healing.

Buffing.

Regeneration.

---

## Jötunheim

Heavy physical damage.

Area attacks.

Knockback.

---

## Niflheim

Debuffs.

Freeze.

Silence.

Memory effects.

---

## Muspelheim

Fire.

Burst damage.

Relentless aggression.

---

## Asgard

Balanced.

Counterattacks.

Advanced tactics.

---

## Helheim

Attrition.

Spirit attacks.

Curse.

Revival denial.

---

## Yggdrasil

Rune abilities.

Reality manipulation.

Adaptive behaviour.

---

# Boss Personalities

---

## Draugr Jarl

Behaviour

Direct.

Slow.

Brutal.

Rarely uses abilities.

---

## Shade Warden

Behaviour

Mobile.

Uses darkness.

Teleports frequently.

---

## Forgemind Construct

Behaviour

Mechanical.

Predictable.

Changes attack pattern every cycle.

---

## Season Keeper

Behaviour

Rotates between four seasonal forms.

Each form has its own AI profile.

---

## Thrym

Behaviour

Honourable.

Never attacks weakened characters twice in succession.

Focuses on direct combat.

---

## Primordial Wyrm

Behaviour

Uses memory illusions.

Copies previously seen attacks.

---

## Surtr

Behaviour

Tests the player.

Stops attacking if the trial conditions are met.

Never fights to kill.

---

## Einherjar Commander

Behaviour

Highly disciplined.

Uses counters.

Targets careless positioning.

---

## Memory of the Last Hero

Behaviour

Mirrors the player's preferred tactics.

Uses similar skills to the Hero.

---

## Loki

Behaviour

Adaptive.

Responds to party composition.

Prioritises Rune Skills.

Attempts to counter repeated strategies.

---

# Ending Boss AI

---

## Níðhöggr

Theme

Decay.

Arena collapse.

Poison.

Root corruption.

Becomes stronger as the battle continues.

---

## Loki True Form

Theme

Rune mastery.

Cycles between every Rune affinity.

Frequently changes tactics.

---

## Odin's Final Guardian

Theme

Absolute defence.

Protects the Covenant Core.

Uses powerful defensive abilities before launching devastating counterattacks.

---

# Mythic AI

Available only in:

- Mythic Difficulty
- Endless Arena
- Hvergelmir
- Mythic Boss Rush

Additional behaviour includes:

- Smarter target selection
- Improved skill rotation
- Better healing decisions
- Increased cooperation
- Additional boss phases

Statistics alone should never define Mythic difficulty.

Behaviour should.

---

# AI Restrictions

Enemies must never:

- Cheat
- Ignore cooldowns
- Read player input
- Act outside their turn
- Target invisible information

All decisions must be based on available battle state.

---

# Debug Options

Development builds support:

- Display AI State
- Display Threat Values
- Display Skill Weights
- Force AI Phase
- Disable Random Variation

These tools are removed from release builds.

---

# Canon Principles

- Enemy AI reinforces each realm's identity.
- Bosses become more complex through multiple phases.
- Loki is the most adaptive AI encounter.
- Surtr is a story trial rather than a conventional fight.
- Mythic difficulty enhances decision-making, not just statistics.
- Fairness always takes priority over unpredictability.

---

**End of File**