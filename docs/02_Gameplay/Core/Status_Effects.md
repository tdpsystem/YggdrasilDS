# Status_Effects.md

# Yggdrasil Saga

## Status Effects Database

### Version 2.0 — Current Canon

---

# Purpose

This document defines every status effect used in Yggdrasil Saga.

It includes:

* Damage-over-time effects
* Control effects
* Debuffs
* Buffs
* Immunities
* Boss interactions
* Resistance calculations

This document is the authoritative status-effect reference.

---

# Status Categories

Status effects are divided into four major groups:

1. Damage Effects
2. Control Effects
3. Debuffs
4. Buffs

---

# Status Application

Statuses may be inflicted through:

* Skills
* Enemy attacks
* Boss mechanics
* Equipment effects
* Environmental hazards

---

# Status Resistance Formula

Base resistance is determined by:

```text id="st001"
Status Resistance =
(LUK ÷ 2)
+ Equipment Bonuses
+ Passive Skills
```

---

# Status Duration

Most effects last:

2–5 turns

Boss-specific effects may override standard durations.

---

# Damage Effects

---

## Poison

### Description

Gradually damages the target.

### Effect

```text id="st002"
5% Max HP per turn
```

### Duration

4 Turns

### Removed By

* Purify
* Recovery Items
* Inns

---

## Burn

### Description

Fire damage continues after attack.

### Effect

```text id="st003"
7% Max HP per turn
```

### Additional Effect

-10% ATK

### Duration

3 Turns

---

## Frostbite

### Description

Extreme cold weakens movement and combat ability.

### Effect

-15% SPD
-10% ATK

### Duration

4 Turns

---

## Bleed

### Description

Open wounds continue to inflict damage.

### Effect

```text id="st004"
4% Max HP per turn
```

### Additional Effect

Healing reduced by 25%.

### Duration

4 Turns

---

# Control Effects

---

## Stun

### Description

Target loses action.

### Effect

Cannot Act

### Duration

1 Turn

### Notes

Bosses are normally immune.

---

## Freeze

### Description

Target becomes encased in ice.

### Effect

Cannot Act

### Duration

1–2 Turns

### Removal

Fire attacks instantly remove Freeze.

---

## Silence

### Description

Prevents spellcasting.

### Effect

Cannot use:

* Rune Skills
* Magic Skills
* Covenant Abilities

### Duration

3 Turns

---

## Sleep

### Description

Target falls asleep.

### Effect

Cannot Act

### Wake Conditions

* Taking damage
* Duration expires

### Duration

2 Turns

---

# Debuffs

---

## Curse

### Description

Corruptive power from Helheim.

### Effects

-20% ATK
-20% MAG

### Duration

5 Turns

---

## Weakness

### Description

Physical power reduced.

### Effect

```text id="st005"
ATK -25%
```

### Duration

4 Turns

---

## Frailty

### Description

Defenses lowered.

### Effect

```text id="st006"
DEF -25%
```

### Duration

4 Turns

---

## Mindbreak

### Description

Mental focus shattered.

### Effect

```text id="st007"
MAG -25%
```

### Duration

4 Turns

---

## Vulnerability

### Description

Magical defenses reduced.

### Effect

```text id="st008"
RES -25%
```

### Duration

4 Turns

---

## Slow

### Description

Movement becomes sluggish.

### Effect

```text id="st009"
SPD -30%
```

### Duration

3 Turns

---

## Shock

### Description

Thunder disruption affects reaction speed.

### Effects

-20% SPD

10% chance to lose turn.

### Duration

3 Turns

---

# Buffs

---

## Barrier

### Description

Protective magical shield.

### Effect

```text id="st010"
Damage Taken -25%
```

### Duration

3 Turns

---

## Ward

### Description

Magical protection.

### Effect

```text id="st011"
RES +25%
```

### Duration

3 Turns

---

## Haste

### Description

Accelerates movement.

### Effect

```text id="st012"
SPD +30%
```

### Duration

3 Turns

---

## Focus

### Description

Improves magical concentration.

### Effect

```text id="st013"
MAG +25%
```

### Duration

3 Turns

---

## Fortify

### Description

Strengthens defenses.

### Effect

```text id="st014"
DEF +25%
```

### Duration

3 Turns

---

## Courage

### Description

Heroic inspiration.

### Effects

ATK +20%

Critical Rate +10%

### Duration

4 Turns

---

## Regeneration

### Description

Natural healing over time.

### Effect

```text id="st015"
Heal 8% Max HP each turn
```

### Duration

4 Turns

---

# Special Covenant Effects

These effects originate from the Ten Rune Covenant.

---

## Lightblessed

Rune of Light

### Effect

* Immune to Blindness
* +10% Healing Received

---

## Radiant Aura

Rune of Radiance

### Effect

* Deals Light damage to attackers

### Duration

3 Turns

---

## Forgeheart

Rune of Craft

### Effect

* DEF +20%
* RES +20%

### Duration

4 Turns

---

## Verdant Growth

Rune of Growth

### Effect

Regeneration is doubled.

### Duration

4 Turns

---

## Giant's Might

Rune of Giants

### Effect

ATK +30%

### Duration

3 Turns

---

## Frozen Mind

Rune of Ice

### Effect

Immune to Freeze.

### Duration

4 Turns

---

## Living Flame

Rune of Fire

### Effect

Burn immunity.

### Duration

4 Turns

---

## Stormcaller

Rune of Thunder

### Effect

Counterattack chance +20%.

### Duration

4 Turns

---

## Deathward

Rune of Death

### Effect

Survive fatal damage with 1 HP once.

### Duration

Until Triggered

---

## Wisdom Awakened

Rune of Wisdom

### Effect

MP costs reduced by 25%.

### Duration

5 Turns

---

# Boss Status Rules

Bosses ignore many control effects.

---

## Immune Effects

Most bosses are immune to:

* Stun
* Sleep
* Freeze

---

## Resistant Effects

Bosses receive reduced duration from:

* Silence
* Slow
* Shock
* Curse

---

## Vulnerable Effects

Some bosses may still be affected by:

* Frailty
* Vulnerability
* Weakness

As part of encounter design.

---

# Stacking Rules

---

## Same Status

Does Not Stack

Duration refreshes.

---

## Different Buffs

May stack together.

---

## Different Debuffs

May stack together.

---

# Cleansing Effects

The following remove negative effects:

* Purify
* Renewal
* Memory Restore
* Sacred Waters
* Certain Inns
* Story Events

---

# Death and Status Effects

Upon KO:

All temporary effects are removed.

This includes:

* Buffs
* Debuffs
* Control effects

---

# Canon Notes

This document replaces all previous status systems.

The following are no longer canon:

* Fear
* Blind
* Doom Timer
* Shadow Corruption
* Chaos Alignment Effects

Only the statuses listed in this document are considered canonical.
