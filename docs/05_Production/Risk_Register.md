# Yggdrasil Saga

## Risk Register

**Version:** 5.0 — Canon Edition

**Authority:** CANON_REFERENCE.md

---

# Purpose

This document identifies, evaluates, and tracks risks throughout the development of **Yggdrasil Saga**.

It serves as the primary reference for:

- Project Management
- Production Planning
- Technical Planning
- Scope Control
- QA
- Release Readiness

Every identified risk should include:

- Probability
- Impact
- Mitigation
- Owner
- Status

---

# Risk Ratings

## Probability

| Rating | Meaning  |
|--------|----------|
| Low    | Unlikely |
| Medium | Possible |
| High   | Likely   |

---

## Impact

| Rating | Meaning             |
|--------|---------------------|
| Low    | Minor inconvenience |
| Medium | Significant delay   |
| High   | Project threatening |

---

# Production Risks

---

## RISK-001

### Scope Creep

Probability

High

Impact

High

Description

Additional features may continually expand the project beyond the Nintendo DS target.

Mitigation

- Lock canon first.
- Require approval before adding new systems.
- Finish existing systems before creating new ones.

Owner

Project Lead

Status

Open

---

## RISK-002

### Documentation Drift

Probability

High

Impact

High

Description

Documents become inconsistent over time.

Mitigation

- CANON_REFERENCE.md remains the single source of truth.
- Regenerate outdated documents rather than patching them.
- Perform regular documentation audits.

Owner

Narrative Lead

Status

Mitigated

---

## RISK-003

### Feature Creep

Probability

Medium

Impact

High

Description

Adding mechanics late in development may destabilise gameplay.

Mitigation

- Feature lock at Beta.
- New ideas move to sequel or expansion backlog.

Owner

Design Lead

Status

Open

---

# Technical Risks

---

## RISK-004

### Nintendo DS Memory Limits

Probability

Medium

Impact

High

Description

Asset usage exceeds available RAM or VRAM.

Mitigation

- Follow Memory_Budget.md.
- Optimise sprite sheets.
- Stream assets where appropriate.

Owner

Technical Lead

Status

Open

---

## RISK-005

### Performance

Probability

Medium

Impact

High

Description

Frame rate drops below acceptable targets.

Mitigation

- Profile frequently.
- Optimise AI.
- Reduce particle counts.
- Respect sprite limits.

Owner

Programming Lead

Status

Open

---

## RISK-006

### Save Compatibility

Probability

Low

Impact

High

Description

Future updates break save files.

Mitigation

- Incremental save migration.
- Automatic backup creation.
- Version validation.

Owner

Engine Programmer

Status

Open

---

# Gameplay Risks

---

## RISK-007

### Combat Balance

Probability

Medium

Impact

Medium

Description

Certain classes or Rune Skills become significantly stronger than intended.

Mitigation

- Continuous balance testing.
- Arena testing.
- Endgame simulations.

Owner

Combat Designer

Status

Open

---

## RISK-008

### Difficulty Spikes

Probability

Medium

Impact

Medium

Description

Realm progression becomes inconsistent.

Mitigation

- Maintain recommended level ranges.
- Playtest every chapter.

Owner

Gameplay Designer

Status

Open

---

## RISK-009

### Boss Frustration

Probability

Medium

Impact

Medium

Description

Boss mechanics become unfair rather than challenging.

Mitigation

- Telegraph major attacks.
- Reward learning.
- Avoid unavoidable damage.

Owner

Combat Designer

Status

Open

---

# Narrative Risks

---

## RISK-010

### Canon Inconsistency

Probability

High

Impact

High

Description

Story documents contradict one another.

Mitigation

- All documents derive from CANON_REFERENCE.md.
- Regenerate outdated files instead of editing piecemeal.

Owner

Narrative Lead

Status

Mitigated

---

## RISK-011

### Route Bias

Probability

Medium

Impact

High

Description

One ending route appears objectively "correct."

Mitigation

Ensure:

- Preservation
- Renewal
- Liberation

are all philosophically valid.

Owner

Lead Writer

Status

Open

---

## RISK-012

### Character Voice Drift

Probability

Medium

Impact

Medium

Description

Dialogue becomes inconsistent across writers.

Mitigation

Use Dialogue_Bible.md as the sole dialogue reference.

Owner

Narrative Team

Status

Open

---

# Art Risks

---

## RISK-013

### Style Inconsistency

Probability

Medium

Impact

Medium

Description

Assets no longer appear visually cohesive.

Mitigation

Follow:

- Art_Bible.md
- Portrait_Guidelines.md
- UI_Style_Guide.md

Owner

Art Director

Status

Open

---

## RISK-014

### Oversized Assets

Probability

Medium

Impact

High

Description

Sprites or portraits exceed Nintendo DS memory budgets.

Mitigation

Strict adherence to Technical.md.

Owner

Lead Artist

Status

Open

---

# Audio Risks

---

## RISK-015

### Audio Memory

Probability

Low

Impact

Medium

Description

Music exceeds cartridge or RAM limits.

Mitigation

Compress assets.

Reuse instruments.

Owner

Audio Lead

Status

Open

---

# QA Risks

---

## RISK-016

### Regression Bugs

Probability

High

Impact

Medium

Description

Previously fixed bugs return.

Mitigation

Full regression testing before every milestone.

Owner

QA Lead

Status

Open

---

## RISK-017

### Insufficient Playtesting

Probability

Medium

Impact

High

Description

Balance problems discovered too late.

Mitigation

Internal playtesting after every completed realm.

Owner

QA Lead

Status

Open

---

# Schedule Risks

---

## RISK-018

### Milestone Delays

Probability

Medium

Impact

High

Description

Vertical Slice or Alpha slips significantly.

Mitigation

Prioritise core gameplay over optional content.

Owner

Producer

Status

Open

---

## RISK-019

### Asset Bottlenecks

Probability

Medium

Impact

Medium

Description

Programming blocked waiting for art or audio.

Mitigation

Use placeholders.

Prioritise gameplay implementation.

Owner

Production Lead

Status

Open

---

# Release Risks

---

## RISK-020

### Gold Master Instability

Probability

Low

Impact

High

Description

Critical bugs discovered late.

Mitigation

Multiple Release Candidates.

Full QA pass.

Owner

Project Lead

Status

Open

---

# Risk Review Schedule

Risks should be reviewed:

- Weekly during active development.
- At every milestone.
- Before every Release Candidate.
- Before Gold Master.

---

# Escalation Rules

A risk must be escalated if:

- Probability becomes High.
- Impact becomes High.
- It blocks milestone completion.
- It threatens Nintendo DS compatibility.
- It threatens canon consistency.

---

# Canon Principles

- Canon consistency is treated as a project-level risk.
- CANON_REFERENCE.md is the single source of truth.
- Scope control takes priority over feature expansion.
- Technical limitations of the Nintendo DS must always be respected.
- Every identified risk should have a documented mitigation strategy.

---

**End of File**