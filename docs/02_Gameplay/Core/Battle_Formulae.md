# Battle_Formulae

## Yggdrasil Saga

Version: 1.0

Purpose:

Define all combat calculations used by Yggdrasil Saga.

These formulas govern:

* Physical damage
* Magical damage
* Healing
* Critical hits
* Accuracy
* Evasion
* Status effects
* Turn order
* Experience rewards

All battle calculations must be deterministic and reproducible.

---

# Core Stats

Every combatant possesses:

```text
HP
MP

ATK
DEF

MAG
RES

AGI
LUK
```

Definitions:

| Stat | Purpose                             |
|------|-------------------------------------|
| HP   | Health                              |
| MP   | Skill resource                      |
| ATK  | Physical damage                     |
| DEF  | Physical defense                    |
| MAG  | Magical power                       |
| RES  | Magical defense                     |
| AGI  | Turn order                          |
| LUK  | Criticals, drops, status resistance |

---

# Damage Philosophy

Goals:

* Simple calculations
* Easy balancing
* Predictable growth
* Meaningful equipment upgrades
* DQ-inspired progression

Damage should scale smoothly from:

```text
Level 1
```

to

```text
Level 99
```

without excessive inflation.

---

# Physical Damage Formula

Base Formula:

```text
Damage =
(Attacker ATK × Skill Power)
-
(Target DEF ÷ 2)
```

Minimum Damage:

```text
1
```

Example:

```text
ATK = 30
Skill Power = 1.0
DEF = 20

Damage =
30 - 10

Damage = 20
```

---

# Physical Skill Power Values

| Skill Type         | Multiplier |
|--------------------|------------|
| Normal Attack      | 1.0        |
| Heavy Strike       | 1.3        |
| Rune Slash         | 1.5        |
| Judgment Blade     | 2.0        |
| World Tree's Wrath | 3.0        |

Example:

```text
Rune Slash

ATK = 40

40 × 1.5 = 60
```

---

# Magical Damage Formula

Base Formula:

```text
Damage =
(MAG × Spell Power)
-
(Target RES ÷ 2)
```

Minimum Damage:

```text
1
```

Example:

```text
MAG = 50
Spell Power = 1.8
RES = 20

Damage =
90 - 10

Damage = 80
```

---

# Spell Power Values

| Spell               | Power |
|---------------------|-------|
| Spark               | 1.0   |
| Flame               | 1.2   |
| Frost               | 1.2   |
| Thunderstorm        | 1.8   |
| Blizzard            | 2.0   |
| Inferno             | 2.2   |
| Elemental Cataclysm | 3.0   |

---

# Healing Formula

Single Target Heal:

```text
Healing =
(MAG × Power)
+
Random(0–10)
```

Example:

```text
MAG = 40

Heal:
40 × 1.5

= 60
```

---

# Healing Power Values

| Skill        | Power |
|--------------|-------|
| Heal         | 1.5   |
| Greater Heal | 2.5   |
| Mass Heal    | 2.0   |
| Miracle      | 4.0   |

---

# Critical Hit Formula

Base Chance:

```text
4%
```

Luck Bonus:

```text
LUK ÷ 200
```

Formula:

```text
Critical Chance =
4%
+
(LUK ÷ 200)
```

Example:

```text
LUK = 20

20 ÷ 200

= 10%

Total = 14%
```

Maximum Critical Chance:

```text
25%
```

Critical Damage:

```text
Damage × 2
```

Critical hits ignore:

```text
50% DEF
```

---

# Accuracy Formula

Base Accuracy:

```text
95%
```

Formula:

```text
Accuracy =
95
+
(Attacker AGI ÷ 5)
-
(Target AGI ÷ 10)
```

Maximum:

```text
99%
```

Minimum:

```text
75%
```

---

# Evasion Formula

Base Evasion:

```text
0%
```

Formula:

```text
Evasion =
AGI ÷ 10
```

Example:

```text
AGI = 30

Evasion = 3%
```

Maximum Evasion:

```text
20%
```

---

# Elemental Weakness Formula

Weakness:

```text
Damage × 1.5
```

Resistance:

```text
Damage × 0.5
```

Strong Resistance:

```text
Damage × 0.25
```

Absorb:

```text
Target heals damage amount.
```

Immunity:

```text
0 damage
```

---

# Status Effect Formula

Base Chance:

```text
Skill Chance
```

Modified By:

```text
Caster LUK
Target LUK
```

Formula:

```text
Final Chance =
Base Chance
+
(Caster LUK ÷ 4)
-
(Target LUK ÷ 4)
```

Example:

```text
Poison = 40%

Caster LUK = 20
Target LUK = 10

40 + 5 - 2

= 43%
```

Minimum Chance:

```text
5%
```

Maximum Chance:

```text
95%
```

---

# Turn Order Formula

Formula:

```text
Turn Score =
AGI
+
Random(0–20)
```

Combatants act from:

```text
Highest
to
Lowest
```

This creates slight unpredictability while preserving AGI importance.

---

# Escape Formula

Base Chance:

```text
50%
```

Formula:

```text
Escape =
50
+
(Party Average AGI)
-
(Enemy Average AGI)
```

Maximum:

```text
95%
```

Minimum:

```text
5%
```

Bosses:

```text
Cannot Escape
```

---

# Guard Formula

When guarding:

```text
Incoming Damage × 0.5
```

Status resistance bonus:

```text
+25%
```

for one turn.

---

# Berserker Rage Bonus

When Berserker enters Rage:

```text
ATK × 1.5
DEF × 0.8
```

Duration:

```text
3 turns
```

---

# Valkyrie Divine Stance

Effects:

```text
ATK × 1.2
RES × 1.2
```

Duration:

```text
3 turns
```

---

# Experience Formula

Enemy EXP:

```text
Enemy Base EXP
```

Victory Reward:

```text
Total EXP =
Sum(All Enemy EXP)
```

Party Distribution:

```text
Equal Split
```

Benched party members receive:

```text
50%
```

of normal EXP.

---

# Gold Formula

Enemy Gold:

```text
Enemy Base Gold
```

Victory Reward:

```text
Total Gold =
Sum(All Enemy Gold)
```

Luck Bonus:

```text
+1% Gold
per 10 LUK
```

Maximum Bonus:

```text
+25%
```

---

# Drop Rate Formula

Base Drop Rate:

Defined by enemy.

Luck Modifier:

```text
(LUK ÷ 5)%
```

Example:

```text
Base = 10%

LUK = 20

Bonus = 4%

Final = 14%
```

Maximum Drop Rate:

```text
95%
```

---

# Boss Scaling Rules

Bosses gain:

```text
+25% HP
+10% DEF
+10% RES
```

compared to normal enemies of equivalent level.

Major Story Bosses gain:

```text
+50% HP
+20% DEF
+20% RES
```

Examples:

* Draugr Jarl
* Shade Warden
* Forgemind Construct
* Season Keeper
* Thrym
* Primordial Wyrm
* Surtr
* Einherjar Commander
* Memory of the Last Hero
* Loki

---

# Damage Caps

Maximum Single Hit:

```text
9999
```

Maximum HP:

```text
9999
```

Maximum MP:

```text
999
```

---

# Rounding Rules

All fractions:

```text
Round Down
```

Example:

```text
35.9

= 35
```

---

# Technical Goal

```text
Provide classic Dragon Quest-style combat that is easy to balance, easy to understand, and scales cleanly across the entire adventure.
```

---

End of File
