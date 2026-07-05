# Event Flags

# Yggdrasil Saga

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document defines every persistent event flag used throughout **Yggdrasil Saga**.

Event flags control:

- Story progression
- Quest progression
- Party recruitment
- Rune acquisition
- Dungeon completion
- Boss defeats
- Route selection
- Ending progression
- Postgame unlocks

Flags are permanent unless explicitly reset by New Game Plus.

---

# Flag Naming Convention

All flags use uppercase snake case.

Examples:

```text
FLAG_PROLOGUE_STARTED
FLAG_RUNE_CRAFT_OBTAINED
FLAG_ASTRID_JOINED
FLAG_PRESERVATION_ROUTE
```

---

# Categories

- Story Flags
- Party Flags
- Rune Flags
- Realm Flags
- Boss Flags
- Quest Flags
- Route Flags
- Ending Flags
- Postgame Flags
- System Flags

---

# Story Flags

## Prologue

```text
FLAG_PROLOGUE_STARTED
FLAG_FIRST_RUNE_VISION
FLAG_RATATOSKR_JOINED
FLAG_LOKI_INTRODUCED
```

---

## Midgard

```text
FLAG_MIDGARD_STARTED
FLAG_MIDGARD_COMPLETE
```

---

## Alfheim

```text
FLAG_ALFHEIM_STARTED
FLAG_ALFHEIM_COMPLETE
```

---

## Svartalfheim

```text
FLAG_SVARTALFHEIM_STARTED
FLAG_SVARTALFHEIM_COMPLETE
```

---

## Vanaheim

```text
FLAG_VANAHEIM_STARTED
FLAG_FIRST_REVELATION
FLAG_VANAHEIM_COMPLETE
```

---

## Jötunheim

```text
FLAG_JOTUNHEIM_STARTED
FLAG_JOTUNHEIM_COMPLETE
```

---

## Niflheim

```text
FLAG_NIFLHEIM_STARTED
FLAG_PREVIOUS_AGES_REVEALED
FLAG_NIFLHEIM_COMPLETE
```

---

## Muspelheim

```text
FLAG_MUSPELHEIM_STARTED
FLAG_MUSPELHEIM_COMPLETE
```

---

## Asgard

```text
FLAG_ASGARD_STARTED
FLAG_ODIN_REVELATION
FLAG_ASGARD_COMPLETE
```

---

## Helheim

```text
FLAG_HELHEIM_STARTED
FLAG_HEL_REVELATION
FLAG_HELHEIM_COMPLETE
```

---

## Yggdrasil

```text
FLAG_YGGDRASIL_STARTED
FLAG_COVENANT_CORE_DISCOVERED
FLAG_THREE_PHILOSOPHIES
FLAG_FINAL_CHOICE_AVAILABLE
```

---

# Party Flags

```text
FLAG_ASTRID_JOINED
FLAG_EIRIK_JOINED
FLAG_THORA_JOINED
FLAG_THRYM_JOINED
```

Ratatoskr is always present after the Prologue.

No join flag is required beyond:

```text
FLAG_RATATOSKR_JOINED
```

---

# Rune Flags

```text
FLAG_RUNE_CRAFT_OBTAINED
FLAG_RUNE_RADIANCE_OBTAINED
FLAG_RUNE_LIGHT_OBTAINED
FLAG_RUNE_GROWTH_OBTAINED
FLAG_RUNE_GIANTS_OBTAINED
FLAG_RUNE_ICE_OBTAINED
FLAG_RUNE_FIRE_OBTAINED
FLAG_RUNE_WISDOM_OBTAINED
FLAG_RUNE_DEATH_OBTAINED
FLAG_RUNE_THUNDER_OBTAINED
```

---

# Boss Flags

```text
FLAG_DRAUGR_JARL_DEFEATED
FLAG_SHADE_WARDEN_DEFEATED
FLAG_FORGEMIND_CONSTRUCT_DEFEATED
FLAG_SEASON_KEEPER_DEFEATED
FLAG_THRYM_DEFEATED
FLAG_PRIMORDIAL_WYRM_DEFEATED
FLAG_SURTR_TRIAL_COMPLETE
FLAG_EINHERJAR_COMMANDER_DEFEATED
FLAG_LAST_HERO_DEFEATED
FLAG_LOKI_DEFEATED
FLAG_NIDHOGGR_DEFEATED
FLAG_ODINS_FINAL_GUARDIAN_DEFEATED
```

---

# Quest Flags

Main Story

```text
FLAG_MQ001_COMPLETE
FLAG_MQ002_COMPLETE
...
FLAG_MQ025_COMPLETE
```

Side Quests

```text
FLAG_SQ001_COMPLETE
FLAG_SQ002_COMPLETE
...
```

Companion Quests

```text
FLAG_CQ001_COMPLETE
FLAG_CQ002_COMPLETE
FLAG_CQ003_COMPLETE
FLAG_CQ004_COMPLETE
```

Postgame

```text
FLAG_PQ001_COMPLETE
FLAG_PQ002_COMPLETE
```

---

# Dungeon Flags

```text
FLAG_DRAUGR_BARROW_CLEARED
FLAG_RADIANT_SPIRE_CLEARED
FLAG_FORGEHEART_CITADEL_CLEARED
FLAG_TEMPLE_OF_SEASONS_CLEARED
FLAG_HALL_OF_GIANTS_CLEARED
FLAG_FROZEN_ARCHIVE_CLEARED
FLAG_WORLDFORGE_CLEARED
FLAG_HALL_OF_CHAMPIONS_CLEARED
FLAG_HALL_OF_ECHOES_CLEARED
FLAG_HEART_OF_YGGDRASIL_CLEARED
```

---

# Route Flags

Exactly one of these may be active.

```text
FLAG_ROUTE_PRESERVATION
FLAG_ROUTE_RENEWAL
FLAG_ROUTE_LIBERATION
```

---

# Ending Flags

```text
FLAG_ENDING_PRESERVATION
FLAG_ENDING_RENEWAL
FLAG_ENDING_LIBERATION
```

These remain permanently set.

They unlock:

- New Game Plus
- Arena Expansion
- Postgame
- Hvergelmir

---

# Postgame Flags

```text
FLAG_POSTGAME_UNLOCKED
FLAG_HVERGELMIR_UNLOCKED
FLAG_BOSS_RUSH_UNLOCKED
FLAG_ENDLESS_ARENA_UNLOCKED
FLAG_MYTHIC_CHALLENGES_UNLOCKED
FLAG_SECRET_BOSS_AVAILABLE
```

---

# Secret Boss Flags

```text
FLAG_ODINS_TRIAL_COMPLETE
FLAG_FIRST_DRAGON_COMPLETE
FLAG_WORLD_SERPENT_COMPLETE
```

---

# Town Unlock Flags

```text
FLAG_MANNHEIM_UNLOCKED
FLAG_LUMINARA_UNLOCKED
FLAG_IRONDEEP_UNLOCKED
FLAG_VERDANT_GROVE_UNLOCKED
FLAG_FROSTHOLD_UNLOCKED
FLAG_FROZEN_REFUGE_UNLOCKED
FLAG_EMBER_BASTION_UNLOCKED
FLAG_VALHALLA_UNLOCKED
FLAG_SILENT_CROSSING_UNLOCKED
FLAG_YGGDRASIL_SANCTUARY_UNLOCKED
```

---

# Fast Travel Flags

```text
FLAG_FAST_TRAVEL_MIDGARD
FLAG_FAST_TRAVEL_ALFHEIM
FLAG_FAST_TRAVEL_SVARTALFHEIM
FLAG_FAST_TRAVEL_VANAHEIM
FLAG_FAST_TRAVEL_JOTUNHEIM
FLAG_FAST_TRAVEL_NIFLHEIM
FLAG_FAST_TRAVEL_MUSPELHEIM
FLAG_FAST_TRAVEL_ASGARD
FLAG_FAST_TRAVEL_HELHEIM
```

Unlocked by Ratatoskr after each realm is completed.

---

# System Flags

```text
FLAG_INTRO_COMPLETE
FLAG_CLASS_CHANGE_UNLOCKED
FLAG_CODEX_UNLOCKED
FLAG_ARENA_UNLOCKED
FLAG_CRAFTING_UNLOCKED
FLAG_NEW_GAME_PLUS_UNLOCKED
```

---

# Save Rules

Event flags:

- Are stored in the save file.
- Never reset during normal gameplay.
- Reset only when explicitly required by New Game Plus.

Ending completion flags persist permanently.

---

# Debug Rules

Debug builds may:

- View flags
- Search flags
- Toggle flags
- Export flags

Release builds must never expose the flag editor.

---

# Canon Principles

- Story progression is entirely event-flag driven.
- Only one route flag may ever be active.
- Ratatoskr's progression controls Fast Travel.
- Every Covenant Rune has its own acquisition flag.
- Ending flags permanently record player choices.
- All flags use deterministic naming for scripting compatibility.

---

**End of File**