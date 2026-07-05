# Yggdrasil Saga

## Localization Pipeline

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document defines the localization workflow for **Yggdrasil Saga**.

It serves as the production reference for:

- Writers
- Translators
- Editors
- Localization QA
- Build Engineers

Every localized version must preserve the meaning, tone, and themes of the original English script while remaining
natural in the target language.

---

# Localization Philosophy

The English script is the **master script**.

All translations are derived from the English version after narrative approval.

Localization should preserve:

- Character personality
- Story intent
- Mythological atmosphere
- Emotional impact

Natural translation is preferred over literal translation.

---

# Supported Languages

## Launch Languages

- English (Master)
- Japanese
- French
- German
- Spanish
- Italian

---

## Future Languages

- Portuguese
- Korean
- Simplified Chinese
- Traditional Chinese

---

# Workflow

```text
Story Writing
        ↓
Narrative Review
        ↓
Canon Verification
        ↓
English Master Locked
        ↓
Translation
        ↓
Editing
        ↓
Localization QA
        ↓
Implementation
        ↓
Build Verification
```

---

# Stage 1

## Narrative Approval

Requirements

- Story approved
- Dialogue approved
- Character voices approved

Only approved English dialogue proceeds to localization.

---

# Stage 2

## Canon Verification

Before translation begins, verify:

- Character names
- Realm names
- Rune names
- Story terminology
- Item names
- Skill names

Everything must match:

**CANON_REFERENCE.md**

---

# Stage 3

## Translation

Translators should preserve:

- Meaning
- Emotion
- Tone
- Character voice

Avoid:

- Literal translation
- Modern slang
- Regional internet terminology

---

# Stage 4

## Editing

Editors verify:

- Grammar
- Flow
- Readability
- Nintendo DS text limits

Dialogue should remain concise.

---

# Stage 5

## Localization QA

Verify:

- Text overflow
- Incorrect line breaks
- Missing punctuation
- Incorrect terminology
- Canon consistency

---

# Stage 6

## Engine Integration

Localized text is imported into:

```text
/data/text/
```

Folder Structure

```text
en/

jp/

fr/

de/

es/

it/
```

---

# Stage 7

## Build Verification

Every language build verifies:

- Dialogue
- Menus
- Inventory
- Battle
- Cutscenes
- Credits

---

# Naming Rules

Dialogue Files

```text
dlg_midgard_en.txt

dlg_midgard_jp.txt
```

---

Quest Files

```text
quest_en.txt

quest_fr.txt
```

---

UI Files

```text
ui_en.txt
```

---

# Character Names

These names are never translated.

- Hero
- Ratatoskr
- Loki
- Odin
- Hel
- Surtr
- Níðhöggr
- Urðr
- Verðandi
- Skuld
- Astrid
- Eirik
- Thora Ironhand
- Thrym

---

# Realm Names

Never translated.

- Midgard
- Alfheim
- Svartalfheim
- Vanaheim
- Jötunheim
- Niflheim
- Muspelheim
- Asgard
- Helheim
- Yggdrasil

---

# Core Terminology

Never translated.

- Rune Covenant
- Covenant Core
- Ragnarök
- Bifröst
- Ginnungagap
- Mímir's Well
- Hvergelmir

---

# UI Limits

Recommended maximum lengths

Dialogue Line

```text
120 characters
```

---

Menu Entry

```text
24 characters
```

---

Skill Name

```text
20 characters
```

---

Item Name

```text
24 characters
```

---

Quest Name

```text
32 characters
```

---

# Version Control

Every localized file should track:

- Version
- Translator
- Reviewer
- Approval Date

Example

```text
Version: 5.0

Translator: JP Team

Reviewer: Narrative Lead

Status: Approved
```

---

# Regression Testing

Every localization update requires verification of:

- Existing dialogue
- New dialogue
- Menu layout
- Save compatibility
- Event text
- Quest text

---

# Completion Criteria

A language is considered complete when:

✓ All text translated

✓ Canon terminology verified

✓ UI verified

✓ QA approved

✓ Integrated into release build

---

# Canon Principles

- English is the master script.
- CANON_REFERENCE.md overrides all translated terminology.
- Character voices must remain consistent across every language.
- Localization should preserve intent over literal wording.
- No localized version may alter story, lore, or gameplay.

---

**End of File**