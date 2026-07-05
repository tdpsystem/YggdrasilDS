# Yggdrasil Saga

## Combat System

### Version 4.0 — Current Canon

---

# Purpose

This document defines the complete turn-based combat system used in Yggdrasil Saga.

It serves as the primary reference for:

* Core battle flow
* Stats
* Turn order
* Damage formulas
* Critical hits
* Rune mechanics
* Status effects
* Enemy interactions
* Boss encounters
* Endgame balance

This document replaces all previous combat documentation.

---

# Combat Philosophy

Combat is designed around:

1. Tactical decision making
2. Class synergy
3. Rune management
4. Boss mechanics
5. Party composition

Victory should come from strategy rather than grinding alone.

---

# Party Structure

## Active Party

Maximum Active Members:

4

---

## Reserve Members

Story companions not currently active remain in reserve.

---

# Core Statistics

Every character and enemy uses eight core statistics.

| Stat         | Abbreviation | Function                     |
|--------------|--------------|------------------------------|
| Hit Points   | HP           | Health                       |
| Magic Points | MP           | Skill resource               |
| Attack       | ATK          | Physical damage              |
| Defense      | DEF          | Physical mitigation          |
| Magic        | MAG          | Spell damage                 |
| Resistance   | RES          | Magic mitigation             |
| Speed        | SPD          | Turn order                   |
| Luck         | LUK          | Criticals, drops, resistance |

---

# Battle Flow

Each combat round follows:

1. Turn Order Calculation
2. Player Commands
3. Enemy Actions
4. End-of-Turn Effects
5. Status Resolution
6. Next Round

---

# Turn Order System

Combat uses a Speed-based initiative system.

---

## Initiative Formula

```text
Initiative =
SPD + (LUK ÷ 4) + Random(0–10)
```

---

## Turn Priority

Highest Initiative acts first.

---

## Tie Resolution

1. Higher LUK
2. Player character
3. Random selection

---

# Actions

During a turn a character may:

* Attack
* Use Skill
* Use Item
* Defend
* Escape

---

# Standard Attack

A basic weapon attack.

Costs:

0 MP

---

# Defend

Reduces incoming damage.

Effect:

-50% damage taken

Until next action.

---

# Escape

Attempt to flee battle.

---

## Escape Formula

```text
Party SPD ÷ Enemy SPD
```

Modified by encounter type.

Boss battles cannot be escaped.

---

# Damage Formula

---

## Physical Damage

```text
Base Damage =
(ATK × 2) − DEF
```

Variance:

```text
±10%
```

---

## Final Formula

```text
Final Damage =
MAX(1, Result)
```

---

# Magical Damage

```text
Base Damage =
(MAG × 2.5) − RES
```

Variance:

```text
±10%
```

---

# Rune Damage

Rune attacks use:

```text
(MAG × 2.75) − RES
```

Rune abilities are intentionally stronger than normal magic.

---

# Multi-Hit Skills

Each hit calculates independently.

Variance applies to every strike.

---

# Critical Hits

---

## Critical Chance

```text
5% + (LUK ÷ 2)
```

---

## Critical Damage

```text
Final Damage × 1.5
```

---

## Boss Protection

Bosses receive:

```text
Critical Multiplier = 1.25
```

Instead of 1.5.

---

# Accuracy

Base Accuracy:

95%

---

## Accuracy Modifiers

Affected by:

* Skills
* Status effects
* Equipment
* Buffs

---

# Evasion

Based on:

```text
SPD
```

And equipment bonuses.

---

# Weakness System

Enemies possess elemental traits.

---

# Elements

| Element  | Description      |
|----------|------------------|
| Physical | Weapons          |
| Rune     | Covenant power   |
| Light    | Radiance         |
| Fire     | Flame            |
| Ice      | Memory and frost |
| Thunder  | Divine lightning |
| Nature   | Growth           |
| Death    | Decay            |
| Healing  | Restoration      |

---

# Elemental Weakness

```text
Damage × 1.5
```

---

# Elemental Resistance

```text
Damage × 0.5
```

---

# Immunity

```text
0 Damage
```

---

# Absorption

Target heals instead.

---

# Ten Rune Covenant System

The Ten Rune Covenant is the central progression mechanic of Yggdrasil Saga.

Each Rune recovered grants:

* Story progression
* Passive bonuses
* New combat powers
* Covenant abilities

---

# Rune Progression

The Hero gradually acquires:

1. Rune of Light
2. Rune of Radiance
3. Rune of Craft
4. Rune of Growth
5. Rune of Giants
6. Rune of Ice
7. Rune of Fire
8. Rune of Thunder
9. Rune of Death
10. Rune of Wisdom

---

# Rune Energy

Many advanced abilities consume:

### Rune Energy

---

## Rune Energy Gain

Earned through:

* Attacking
* Taking damage
* Exploiting weaknesses
* Boss mechanics

---

## Maximum Rune Energy

100

---

# Rune Bursts

Powerful Rune abilities become available when Rune Energy is sufficiently high.

---

## Burst Threshold

50+

Rune Energy

---

## Ultimate Threshold

100

Rune Energy

---

# Status Effects

Status effects are divided into:

---

## Damage Effects

* Poison
* Burn

---

## Control Effects

* Freeze
* Stun
* Silence

---

## Debuffs

* Curse
* Shock
* Slow

---

## Buffs

* Barrier
* Ward
* Haste
* Focus
* Regeneration

---

# Status Resistance

Formula:

```text
(LUK ÷ 2)
+ Equipment Bonuses
+ Skill Bonuses
```

---

# Knockout State

When HP reaches 0:

* Character is KO'd
* Cannot act
* Cannot gain experience until revived

---

# Reviving

Methods:

* Revival Skills
* Phoenix Feather
* Inns
* Story Events

---

# Enemy Design Philosophy

Enemy encounters are designed to teach mechanics gradually.

Each realm introduces:

* New status effects
* New elemental threats
* New combat patterns

---

# Realm Combat Themes

| Realm        | Theme            |
|--------------|------------------|
| Midgard      | Fundamentals     |
| Alfheim      | Magic            |
| Svartalfheim | Defense          |
| Vanaheim     | Sustain          |
| Jötunheim    | Burst Damage     |
| Niflheim     | Control          |
| Muspelheim   | Aggression       |
| Asgard       | Elite Encounters |
| Helheim      | Attrition        |
| Yggdrasil    | Mastery          |

---

# Boss Design Framework

Bosses operate using phases.

---

## Phase 1

100%–75%

Introduction

---

## Phase 2

74%–50%

Additional mechanics

---

## Phase 3

49%–25%

Major escalation

---

## Phase 4

24%–0%

Desperation phase

---

# Canon Story Boss Order

1. Draugr Jarl
2. Shade Warden
3. Forgemind Construct
4. Season Keeper
5. Thrym
6. Primordial Wyrm
7. Surtr
8. Einherjar Commander
9. Memory of the Last Hero
10. Loki

---

# Final Route Bosses

## Preservation Route

Representative:

Odin

Final Boss:

Níðhöggr

---

## Renewal Route

Representative:

The Norns

Final Boss:

Loki True Form

---

## Liberation Route

Representative:

Loki

Final Boss:

Odin's Final Guardian

---

# Arena Compatibility

Combat formulas remain identical inside the Arena.

Arena modifiers affect:

* Enemy stats
* AI patterns
* Rewards

Only.

---

# New Game Plus Scaling

Mythic Difficulty applies:

* Increased enemy stats
* Additional boss mechanics
* Enhanced AI behavior

Core formulas remain unchanged.

---

# Victory Conditions

Battle ends when:

* All enemies are defeated
* Story objective is completed
* Special encounter conditions are met

---

# Defeat Conditions

Battle ends in defeat when:

* Entire party is KO'd
* Story-specific failure conditions occur

---

# Canon Notes

This document replaces all older Rune systems.

The following are no longer canon:

* Rune of Shadow
* Rune of Passage
* Rune of Strength
* Light/Dark Rune alignment systems

Only the Ten Rune Covenant system is canon.
