# Cutscene Event List

# Yggdrasil Saga

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document defines every mandatory story cutscene used throughout **Yggdrasil Saga**.

It serves as the master reference for:

- Story progression
- Event scripting
- Dialogue triggers
- Boss introductions
- Party recruitment
- Rune acquisition
- Ending routes

Each cutscene should have:

- Unique Event ID
- Trigger
- Required Flags
- Flags Set
- Narrative Summary

---

# Event ID Format

```text
CUT_XXXX
```

Examples:

```text
CUT_0000
CUT_0102
CUT_0800
CUT_1003
```

---

# PROLOGUE

---

## CUT_0000

### Awakening Beneath Yggdrasil

**Location**

Yggdrasil Roots

**Trigger**

New Game

**Summary**

The Hero awakens beneath the roots of Yggdrasil.

The Norns reveal that the Ten Rune Covenant is weakening.

Ratatoskr arrives and guides the Hero to Yggdrasil Sanctuary.

**Flags Set**

- FLAG_PROLOGUE_STARTED

---

## CUT_0001

### Vision of the First Rune

**Location**

Rune Chamber

**Trigger**

Tutorial Complete

**Summary**

The Hero witnesses a vision of the Rune of Light.

The Norns explain that ten cosmic Runes maintain the Covenant.

**Flags Set**

- FLAG_FIRST_RUNE_VISION

---

## CUT_0002

### Ratatoskr's Oath

**Location**

Yggdrasil Sanctuary

**Trigger**

Leave Rune Chamber

**Summary**

Ratatoskr becomes the Hero's permanent companion.

Fast Travel and the Journal are unlocked.

**Flags Set**

- FLAG_RATATOSKR_JOINED

---

## CUT_0003

### The Traveller

**Location**

Yggdrasil Sanctuary

**Trigger**

Before leaving for Midgard

**Summary**

The Hero meets a mysterious traveller named Loki.

He quietly questions whether every story is as simple as it first appears.

**Flags Set**

- FLAG_LOKI_INTRODUCED

---

# CHAPTER 1 — MIDGARD

---

## CUT_0100

### Arrival at Mannheim

**Trigger**

Enter Mannheim Village

**Flags Set**

- FLAG_MIDGARD_STARTED

---

## CUT_0101

### Astrid Joins

**Trigger**

Speak with Elder Sigrun

**Summary**

Astrid joins the Hero.

**Flags Set**

- FLAG_ASTRID_JOINED

---

## CUT_0102

### Draugr Jarl Defeated

**Trigger**

Boss Defeated

**Summary**

The Hero recovers the Rune of Craft.

Midgard begins recovering.

Ratatoskr quietly notices Yggdrasil weakening.

**Flags Set**

- FLAG_RUNE_CRAFT_OBTAINED
- FLAG_MIDGARD_COMPLETE

---

# CHAPTER 2 — ALFHEIM

---

## CUT_0200

### Arrival in Luminara

**Flags Set**

- FLAG_ALFHEIM_STARTED

---

## CUT_0201

### Eirik Joins

**Trigger**

Crystal Spring

**Flags Set**

- FLAG_EIRIK_JOINED

---

## CUT_0202

### Shade Warden Falls

**Summary**

Rune of Radiance recovered.

**Flags Set**

- FLAG_RUNE_RADIANCE_OBTAINED
- FLAG_ALFHEIM_COMPLETE

---

# CHAPTER 3 — SVARTALFHEIM

---

## CUT_0300

### The Silent Forges

**Flags Set**

- FLAG_SVARTALFHEIM_STARTED

---

## CUT_0301

### Thora Ironhand

**Flags Set**

- FLAG_THORA_JOINED

---

## CUT_0302

### Forgemind Destroyed

**Summary**

Rune of Light recovered.

Ancient forge records question the origin of the Covenant.

**Flags Set**

- FLAG_RUNE_LIGHT_OBTAINED
- FLAG_SVARTALFHEIM_COMPLETE

---

# CHAPTER 4 — VANAHEIM

---

## CUT_0400

### The Seasons Collapse

**Flags Set**

- FLAG_VANAHEIM_STARTED

---

## CUT_0401

### The First Truth

**Summary**

The Season Keeper reveals that the Covenant regulates Ragnarök rather than preventing it.

The party begins questioning their mission.

**Flags Set**

- FLAG_FIRST_REVELATION

---

## CUT_0402

### Rune of Growth

**Flags Set**

- FLAG_RUNE_GROWTH_OBTAINED
- FLAG_VANAHEIM_COMPLETE

---

# CHAPTER 5 — JÖTUNHEIM

---

## CUT_0500

### Giants Await

**Flags Set**

- FLAG_JOTUNHEIM_STARTED

---

## CUT_0501

### Thrym's Respect

**Summary**

After defeat, Thrym joins the Hero.

**Flags Set**

- FLAG_THRYM_JOINED

---

## CUT_0502

### Rune of Giants

**Flags Set**

- FLAG_RUNE_GIANTS_OBTAINED
- FLAG_JOTUNHEIM_COMPLETE

---

# CHAPTER 6 — NIFLHEIM

---

## CUT_0600

### Frozen Memories

**Flags Set**

- FLAG_NIFLHEIM_STARTED

---

## CUT_0601

### The Forgotten Ages

**Summary**

The Hero witnesses memories from previous cycles.

Loki admits he remembers them all.

Ratatoskr admits he remembers fragments.

**Flags Set**

- FLAG_PREVIOUS_AGES_REVEALED

---

## CUT_0602

### Rune of Ice

**Flags Set**

- FLAG_RUNE_ICE_OBTAINED
- FLAG_NIFLHEIM_COMPLETE

---

# CHAPTER 7 — MUSPELHEIM

---

## CUT_0700

### The Worldforge

**Flags Set**

- FLAG_MUSPELHEIM_STARTED

---

## CUT_0701

### Surtr's Trial

**Summary**

Surtr tests the Hero.

He willingly entrusts the Rune of Fire.

**Flags Set**

- FLAG_RUNE_FIRE_OBTAINED
- FLAG_MUSPELHEIM_COMPLETE

---

# CHAPTER 8 — ASGARD

---

## CUT_0800

### Audience with Odin

**Summary**

Odin explains Preservation.

He believes the current age deserves more time.

**Flags Set**

- FLAG_ODIN_REVELATION

---

## CUT_0801

### Rune of Wisdom

**Summary**

The Hero defeats the Einherjar Commander.

Odin entrusts the Rune of Wisdom.

**Flags Set**

- FLAG_RUNE_WISDOM_OBTAINED
- FLAG_ASGARD_COMPLETE

---

# CHAPTER 9 — HELHEIM

---

## CUT_0900

### Hel's Revelation

**Summary**

Hel explains Loki's burden.

The Hero learns why he seeks Liberation.

**Flags Set**

- FLAG_HEL_REVELATION

---

## CUT_0901

### Memory of the Last Hero

**Summary**

The Hero defeats the previous Rune Bearer.

Rune of Death recovered.

**Flags Set**

- FLAG_RUNE_DEATH_OBTAINED
- FLAG_HELHEIM_COMPLETE

---

# CHAPTER 10 — YGGDRASIL

---

## CUT_1000

### The Covenant Core

**Trigger**

All previous Runes collected.

**Summary**

The Hero discovers the Covenant Core.

The complete history of the Covenant is revealed.

**Flags Set**

- FLAG_COVENANT_CORE_DISCOVERED

---

## CUT_1001

### World Rune

**Summary**

The Hero recovers the Rune of Thunder.

The Covenant Core awakens.

**Flags Set**

- FLAG_RUNE_THUNDER_OBTAINED

---

## CUT_1002

### Three Philosophies

**Summary**

Odin.

The Norns.

Loki.

Each presents their vision for the future.

**Flags Set**

- FLAG_THREE_PHILOSOPHIES

---

## CUT_1003

### The Final Choice

**Required**

- FLAG_THREE_PHILOSOPHIES

Player chooses:

- Preservation
- Renewal
- Liberation

**Flags Set**

Exactly one:

- FLAG_ROUTE_PRESERVATION
- FLAG_ROUTE_RENEWAL
- FLAG_ROUTE_LIBERATION

---

# PRESERVATION ROUTE

---

## CUT_1100

### Path of Preservation

**Representative**

Odin

---

## CUT_1101

### Níðhöggr Awakens

**Final Boss**

Níðhöggr

---

## CUT_1102

### Preservation Ending

**Flags Set**

- FLAG_ENDING_PRESERVATION

---

# RENEWAL ROUTE

---

## CUT_1200

### Path of Renewal

**Representative**

The Norns

---

## CUT_1201

### Loki True Form

**Final Boss**

Loki True Form

---

## CUT_1202

### Renewal Ending

**Flags Set**

- FLAG_ENDING_RENEWAL

---

# LIBERATION ROUTE

---

## CUT_1300

### Path of Liberation

**Representative**

Loki

---

## CUT_1301

### Odin's Final Guardian

**Final Boss**

Odin's Final Guardian

---

## CUT_1302

### Liberation Ending

**Flags Set**

- FLAG_ENDING_LIBERATION

---

# POSTGAME

---

## CUT_1400

### Hvergelmir Opens

**Trigger**

Complete any ending.

**Flags Set**

- FLAG_POSTGAME_UNLOCKED

---

## CUT_1401

### Ancient World Serpent

**Trigger**

Reach Hvergelmir Depths.

**Flags Set**

- FLAG_SECRET_BOSS_AVAILABLE

---

# Canon Notes

- Ratatoskr is the Hero's permanent companion.
- Loki is introduced as a mysterious traveller.
- Odin represents Preservation.
- The Norns represent Renewal.
- Loki represents Liberation.
- The World Rune (Thunder) is recovered inside the Heart of Yggdrasil immediately before the Three Philosophies and the
  final choice.

---

**End of File**