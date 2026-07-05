# Dungeon Flowcharts

## Yggdrasil Saga

---

# Overview

This document defines the high-level dungeon flow for each major dungeon in Yggdrasil Saga.

Each flowchart shows:

* Entry point
* Main progression path
* Optional branches
* Puzzle gates
* Mini-bosses
* Save points
* Boss chambers
* Rune chambers
* Exit routes

These flowcharts are intended for level design, scripting, encounter placement, and event flag planning.

---

# Flowchart Legend

```text
[Area]              Standard room or zone
{Puzzle}            Puzzle or interaction gate
<Mini-Boss>         Mini-boss encounter
<Boss>              Main boss encounter
(Save)              Save point
[Treasure]          Optional treasure branch
=>                  Required progression
--                  Optional path
```

---

# Midgard

## Draugr Barrow

```text
[Barrow Entrance]
        =>
[Offering Hall]
        =>
[Crypt Passage]
        -- [Side Tomb: Iron Blade]
        =>
{Rune Door Puzzle}
        =>
[Lower Burial Chamber]
        =>
<Mini-Boss: Draugr Champion>
        =>
(Save)
        =>
[Jarl's Antechamber]
        =>
<Boss: Draugr Jarl>
        =>
[Rune Chamber: Rune of Light]
        =>
[Exit Cutscene]
```

Design Notes:

* Introductory dungeon.
* Teaches locked doors, simple puzzles, treasure rooms, save points, mini-bosses, and boss flow.
* Used as the vertical slice dungeon.

---

# Alfheim

## Radiant Spire

```text
[Spire Entrance]
        =>
[Mirror Hall]
        =>
{Light Reflection Puzzle 1}
        =>
[Crystal Stair]
        -- [Treasure Room: Radiant Cloak]
        =>
[Twilight Gallery]
        =>
{Light Reflection Puzzle 2}
        =>
<Mini-Boss: Twilight Sentinel>
        =>
[Upper Spire]
        =>
{Prism Alignment Puzzle}
        =>
(Save)
        =>
[Crown Chamber]
        =>
<Boss: Shade Warden>
        =>
[Rune Chamber: Rune of Radiance]
        =>
[Exit Cutscene]
```

Design Notes:

* First major puzzle dungeon.
* Teaches light redirection mechanics.
* Optional treasure branches reward puzzle mastery.

---

# Svartalfheim

## Core Forge

```text
[Forge Gate]
        =>
[Steamworks]
        =>
{Pressure Valve Puzzle}
        =>
[Conveyor Hall]
        -- [Treasure Room: Rune Hammer]
        =>
[Machine Core Access]
        =>
<Mini-Boss: Forge Guardian>
        =>
[Anvil Lift]
        =>
{Forge Machinery Puzzle}
        =>
(Save)
        =>
[Core Chamber]
        =>
<Boss: Forgemind Construct>
        =>
[Rune Chamber: Rune of Craft]
        =>
[Forge Shutdown Cutscene]
```

Design Notes:

* Mechanically focused dungeon.
* Emphasizes moving machinery, steam vents, and conveyor paths.
* Thora's recruitment is tied to this dungeon.

---

# Vanaheim

## Temple of Seasons

```text
[Temple Entrance]
        =>
[Spring Hall]
        =>
{Season Switch: Spring}
        =>
[Summer Garden]
        -- [Treasure Grove: Nature Ring]
        =>
{Season Switch: Summer}
        =>
[Autumn Court]
        =>
<Mini-Boss: Verdant Protector>
        =>
[Winter Passage]
        =>
{Season Switch: Winter}
        =>
(Save)
        =>
[Heart of Seasons]
        =>
<Boss: Season Keeper>
        =>
[Rune Chamber: Rune of Growth]
        =>
[First Warning Cutscene]
```

Design Notes:

* Each season changes paths, hazards, and treasure access.
* Major narrative turning point.
* Introduces the idea that the runes may not be purely beneficial.

---

# Jötunheim

## Frozen Citadel

```text
[Citadel Approach]
        =>
[Giant Gate]
        =>
[Ice Platform Hall]
        =>
{Moving Ice Platform Puzzle}
        =>
[Warrior Barracks]
        -- [Treasure Room: Giantbreaker Axe]
        =>
<Mini-Boss: Ancient Giant>
        =>
[Throne Ascent]
        =>
{Weight Gate Puzzle}
        =>
(Save)
        =>
[Thrym's Hall]
        =>
<Boss: Thrym>
        =>
[Rune Chamber: Rune of Giants]
        =>
[Thrym Joins Cutscene]
```

Design Notes:

* Large rooms to emphasize giant scale.
* Party roster completes after this dungeon.
* Thrym acts as both boss and future companion.

---

# Niflheim

## Frozen Archive

```text
[Archive Entrance]
        =>
[Frozen Records Hall]
        =>
{Memory Reconstruction Puzzle 1}
        =>
[Hall of Lost Cycles]
        -- [Treasure Room: Memory Crystal]
        =>
[Silent Vault]
        =>
<Mini-Boss: Frozen Guardian>
        =>
[Cycle Archive]
        =>
{Memory Reconstruction Puzzle 2}
        =>
(Save)
        =>
[Primordial Chamber]
        =>
<Boss: Primordial Wyrm>
        =>
[Rune Chamber: Rune of Ice]
        =>
[Truth Revealed Cutscene]
```

Design Notes:

* Narrative-heavy dungeon.
* Memory puzzles reveal previous cycles of Ragnarök.
* Confirms that the runes are seals.

---

# Muspelheim

## Worldforge

```text
[Worldforge Gate]
        =>
[Ember Walkway]
        =>
{Lava Flow Puzzle 1}
        =>
[Molten Engine Room]
        -- [Treasure Room: Flamebrand]
        =>
[Inferno Bridge]
        =>
<Mini-Boss: Inferno Titan>
        =>
[Furnace Core Access]
        =>
{Lava Flow Puzzle 2}
        =>
(Save)
        =>
[Surtr's Furnace]
        =>
<Boss: Surtr>
        =>
[Rune Chamber: Rune of Fire]
        =>
[Ragnarök Accelerates Cutscene]
```

Design Notes:

* High-damage environmental hazards.
* Lava routing opens and closes paths.
* Surtr represents acceptance of destruction rather than simple villainy.

---

# Asgard

## Hall of Champions

```text
[Valhalla Gate]
        =>
[Hall of Oaths]
        =>
{Trial 1: Courage}
        =>
[Hall of Blades]
        -- [Treasure Room: Thunder Spear]
        =>
{Trial 2: Wisdom}
        =>
[Hall of Storms]
        =>
<Mini-Boss: Valhalla Champion>
        =>
{Trial 3: Resolve}
        =>
(Save)
        =>
[Champion's Arena]
        =>
<Boss: Einherjar Commander>
        =>
[Rune Chamber: Rune of Thunder]
        =>
[Odin Revelation Cutscene]
```

Design Notes:

* Trial-based dungeon.
* Tests combat fundamentals, puzzle logic, and resource management.
* Odin clarifies the necessity of the cycle.

---

# Helheim

## Hall of Echoes

```text
[Silent Shore]
        =>
[Gate of the Dead]
        =>
[Echo Corridor]
        =>
{Past-Life Illusion 1}
        =>
[Judgment Hall]
        -- [Treasure Room: Death Sigil]
        =>
<Mini-Boss: Gatekeeper of Hel>
        =>
[Hall of Failed Heroes]
        =>
{Past-Life Illusion 2}
        =>
(Save)
        =>
[Mirror of the Last Cycle]
        =>
<Boss: Memory of the Last Hero>
        =>
[Rune Chamber: Rune of Death]
        =>
[Hel Revelation Cutscene]
```

Design Notes:

* Emotional and narrative-focused dungeon.
* Illusions show previous versions of the Hero.
* Prepares the player for the final choice.

---

# Yggdrasil

## Heart of the World Tree

```text
[Rootway Entrance]
        =>
[Living Root Maze]
        =>
{Rune Reality Shift: Light/Radiance}
        =>
[Broken Branch Path]
        -- [Treasure Room: World Tree Relic]
        =>
[Cycle Chamber]
        =>
<Mini-Boss: Root Guardian>
        =>
[Unstable Heartway]
        =>
{Rune Reality Shift: Fire/Ice/Thunder}
        =>
<Mini-Boss: Rune Titan>
        =>
(Save)
        =>
[Heart of Yggdrasil]
        =>
<Boss: Loki>
        =>
[Rune Chamber: Rune of Wisdom]
        =>
[Final Choice]
```

Design Notes:

* Final dungeon uses mechanics from previous worlds.
* Rune Reality Shifts alter the map layout.
* Leads directly into route split.

---

# Preserve Route

## Níðhöggr Arena

```text
[Final Choice: Preserve]
        =>
[Root Collapse]
        =>
[Dragon Pit]
        =>
(Save)
        =>
<Boss: Níðhöggr>
        =>
[Preserve Ending Cutscene]
```

Design Notes:

* Short final sequence.
* Focus is on boss encounter and ending resolution.

---

# Renew Route

## Loki True Form Arena

```text
[Final Choice: Renew]
        =>
[Cycle Break]
        =>
[Fate Spiral]
        =>
(Save)
        =>
<Boss: Loki True Form>
        =>
{Final Decision}
        =>
[Return Runes Ending]
        OR
[Destroy Runes Ending]
```

Design Notes:

* The final decision after battle determines Renew A or Renew B.
* Uses all party members and final rune abilities.

---

# Optional Endgame

## Hvergelmir Depths

```text
[Postgame Entrance]
        =>
[River Source]
        =>
[Depth Layer 1]
        -- [Treasure: Ultimate Weapon Material]
        =>
[Depth Layer 2]
        =>
<Mini-Boss: River Titan>
        =>
[Depth Layer 3]
        -- [Treasure: Secret Accessory]
        =>
[Depth Layer 4]
        =>
<Mini-Boss: Abyss Watcher>
        =>
[Deepest Spring]
        =>
(Save)
        =>
<Boss: Ancient World Serpent>
        =>
[Postgame Reward Chamber]
```

Design Notes:

* Largest optional dungeon.
* Designed for completionists.
* Contains superboss-tier enemies and ultimate equipment materials.

---

# Implementation Notes

Each dungeon should include:

* At least one save point before the main boss.
* At least one optional treasure branch.
* One key mechanic unique to that dungeon.
* One mini-boss or elite encounter.
* A Rune Chamber after the boss.
* A story cutscene after Rune acquisition.

---

Version 1.0
