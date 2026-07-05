# Event_Scripting_Reference

## Yggdrasil Saga

Version: 1.0

Purpose:

Define the event scripting language used for dialogue, cutscenes, quests, battles, shops, map transitions, and story
progression.

---

# Event Script Overview

Event scripts control:

* NPC dialogue
* Cutscenes
* Quest updates
* Map transitions
* Boss encounters
* Treasure chests
* Party joins
* Rune rewards
* Save point interactions

Script files use:

```text
.evt
```

Encoding:

```text
UTF-8
```

Naming convention:

```text
snake_case
```

Example:

```text
midgard_mannheim.evt
draugr_barrow.evt
```

---

# Basic Syntax

Each command appears on its own line.

```text
COMMAND argument_1 argument_2 argument_3
```

Example:

```text
SHOW_DIALOGUE ASTRID 1001
SET_FLAG FLAG_ASTRID_JOINED
GIVE_ITEM ITEM_HEALING_HERB 3
```

Blank lines are allowed.

Comments begin with:

```text
#
```

Example:

```text
# Astrid joins after the Draugr Jarl battle
```

---

# Script Structure

```text
SCRIPT script_id
    COMMAND
    COMMAND
    COMMAND
END_SCRIPT
```

Example:

```text
SCRIPT CUT_102_DRAUGR_JARL_DEFEATED
    SHOW_DIALOGUE ASTRID 10201
    SET_FLAG FLAG_DRAUGR_JARL_DEFEATED
    GIVE_RUNE RUNE_LIGHT
    ADD_PARTY_MEMBER ASTRID
    CHANGE_MAP YGGDRASIL_SANCTUARY 12 8
END_SCRIPT
```

---

# Event Trigger Types

| Trigger      | Description                      |
|--------------|----------------------------------|
| NPC_INTERACT | Player talks to an NPC           |
| TILE_TRIGGER | Player steps on tile             |
| BOSS_DEFEAT  | Boss is defeated                 |
| QUEST_UPDATE | Quest state changes              |
| ITEM_USE     | Player uses an item              |
| MAP_ENTER    | Player enters a map              |
| SAVE_POINT   | Player interacts with save point |

---

# Core Commands

## Dialogue

```text
SHOW_DIALOGUE speaker_id dialogue_id
```

Displays dialogue from the Dialogue Bible.

Example:

```text
SHOW_DIALOGUE ASTRID 1001
```

---

## Choice

```text
SHOW_CHOICE choice_id
```

Displays a branching choice.

Example:

```text
SHOW_CHOICE CHOICE_FINAL_ROUTE
```

Choice results should set event flags.

---

## Wait

```text
WAIT frames
```

Example:

```text
WAIT 60
```

At 60 FPS:

```text
60 frames = 1 second
```

---

## Screen Fade

```text
FADE_OUT frames
FADE_IN frames
```

Example:

```text
FADE_OUT 30
CHANGE_MAP MIDGARD_MANNHEIM 10 12
FADE_IN 30
```

---

# Flag Commands

## Set Flag

```text
SET_FLAG flag_id
```

Example:

```text
SET_FLAG FLAG_ASTRID_JOINED
```

## Clear Flag

```text
CLEAR_FLAG flag_id
```

Example:

```text
CLEAR_FLAG FLAG_TEMP_BOSS_WARNING
```

## Check Flag

```text
IF_FLAG flag_id
    COMMAND
END_IF
```

Example:

```text
IF_FLAG FLAG_ASTRID_JOINED
    SHOW_DIALOGUE ASTRID 1200
END_IF
```

## Check Flag Not Set

```text
IF_NOT_FLAG flag_id
    COMMAND
END_IF
```

Example:

```text
IF_NOT_FLAG FLAG_ASTRID_JOINED
    SHOW_DIALOGUE ASTRID 1100
END_IF
```

---

# Branching Commands

```text
IF_FLAG flag_id
    COMMAND
ELSE
    COMMAND
END_IF
```

Example:

```text
IF_FLAG FLAG_MIDGARD_COMPLETE
    SHOW_DIALOGUE ELDER_SIGRUN 1300
ELSE
    SHOW_DIALOGUE ELDER_SIGRUN 1000
END_IF
```

Nested conditionals should be avoided where possible.

Maximum nesting depth:

```text
3
```

---

# Quest Commands

## Start Quest

```text
START_QUEST quest_id
```

Example:

```text
START_QUEST QUEST_DYING_BRANCH
```

## Complete Quest

```text
COMPLETE_QUEST quest_id
```

Example:

```text
COMPLETE_QUEST QUEST_DYING_BRANCH
```

## Set Quest Progress

```text
SET_QUEST_PROGRESS quest_id value
```

Example:

```text
SET_QUEST_PROGRESS QUEST_BOAR_HUNT 3
```

---

# Inventory Commands

## Give Item

```text
GIVE_ITEM item_id quantity
```

Example:

```text
GIVE_ITEM ITEM_HEALING_HERB 5
```

## Remove Item

```text
REMOVE_ITEM item_id quantity
```

Example:

```text
REMOVE_ITEM ITEM_RUSTED_KEY 1
```

## Check Item

```text
IF_HAS_ITEM item_id quantity
    COMMAND
END_IF
```

Example:

```text
IF_HAS_ITEM ITEM_RUSTED_KEY 1
    OPEN_DOOR DOOR_BARROW_LOCKED
END_IF
```

---

# Party Commands

## Add Party Member

```text
ADD_PARTY_MEMBER character_id
```

Example:

```text
ADD_PARTY_MEMBER ASTRID
```

## Remove Party Member

```text
REMOVE_PARTY_MEMBER character_id
```

Example:

```text
REMOVE_PARTY_MEMBER THRYM
```

## Set Active Party

```text
SET_ACTIVE_PARTY character_id character_id character_id character_id
```

Example:

```text
SET_ACTIVE_PARTY HERO ASTRID EIRIK THORA
```

---

# Rune Commands

## Give Rune

```text
GIVE_RUNE rune_id
```

Example:

```text
GIVE_RUNE RUNE_LIGHT
```

## Check Rune

```text
IF_HAS_RUNE rune_id
    COMMAND
END_IF
```

Example:

```text
IF_HAS_RUNE RUNE_LIGHT
    UNLOCK_REALM ALFHEIM
END_IF
```

Rune IDs:

```text
RUNE_LIGHT
RUNE_RADIANCE
RUNE_CRAFT
RUNE_GROWTH
RUNE_GIANTS
RUNE_ICE
RUNE_FIRE
RUNE_THUNDER
RUNE_DEATH
RUNE_WISDOM
```

---

# Map Commands

## Change Map

```text
CHANGE_MAP map_id x y
```

Example:

```text
CHANGE_MAP MIDGARD_MANNHEIM 10 12
```

## Move Player

```text
MOVE_PLAYER direction steps
```

Example:

```text
MOVE_PLAYER NORTH 3
```

## Move NPC

```text
MOVE_NPC npc_id direction steps
```

Example:

```text
MOVE_NPC ASTRID NORTH 2
```

## Set NPC Visible

```text
SET_NPC_VISIBLE npc_id true
SET_NPC_VISIBLE npc_id false
```

Example:

```text
SET_NPC_VISIBLE LOKI false
```

---

# Battle Commands

## Start Battle

```text
START_BATTLE encounter_id
```

Example:

```text
START_BATTLE ENCOUNTER_DRAUGR_JARL
```

## Start Boss Battle

```text
START_BOSS boss_id
```

Example:

```text
START_BOSS BOSS_DRAUGR_JARL
```

## Battle Result Branch

```text
IF_BATTLE_WON
    COMMAND
END_IF
```

Example:

```text
START_BOSS BOSS_DRAUGR_JARL
IF_BATTLE_WON
    SET_FLAG FLAG_DRAUGR_JARL_DEFEATED
    GIVE_RUNE RUNE_LIGHT
END_IF
```

---

# Shop Commands

## Open Shop

```text
OPEN_SHOP shop_id
```

Example:

```text
OPEN_SHOP SHOP_MANNHEIM_GENERAL
```

## Open Inn

```text
OPEN_INN inn_id
```

Example:

```text
OPEN_INN INN_MANNHEIM
```

---

# Save Commands

## Open Save Menu

```text
OPEN_SAVE_MENU
```

Used by save points and Norn Shrines.

Example:

```text
SCRIPT SAVE_NORN_SHRINE_MIDGARD
    SHOW_DIALOGUE NORN_SHRINE 9001
    OPEN_SAVE_MENU
END_SCRIPT
```

## Open Quick Save

```text
OPEN_QUICK_SAVE
```

Used from the pause menu, not from world event scripts unless specifically required.

---

# Audio Commands

## Play Music

```text
PLAY_MUSIC music_id
```

Example:

```text
PLAY_MUSIC BGM_MIDGARD_FIELD
```

## Stop Music

```text
STOP_MUSIC
```

## Play Sound Effect

```text
PLAY_SFX sfx_id
```

Example:

```text
PLAY_SFX SFX_RUNE_OBTAINED
```

---

# Camera Commands

## Move Camera

```text
MOVE_CAMERA x y frames
```

Example:

```text
MOVE_CAMERA 80 64 60
```

## Shake Camera

```text
SHAKE_CAMERA strength frames
```

Example:

```text
SHAKE_CAMERA 3 30
```

---

# Screen Commands

## Flash Screen

```text
FLASH_SCREEN frames
```

Example:

```text
FLASH_SCREEN 20
```

## Show Top Screen Image

```text
SHOW_IMAGE image_id
```

Example:

```text
SHOW_IMAGE IMG_YGGDRASIL_CRACKING
```

## Hide Image

```text
HIDE_IMAGE
```

---

# Route Choice Commands

Final route choice uses the following flags:

```text
FLAG_ROUTE_PRESERVE
FLAG_ROUTE_RENEW
FLAG_RENEW_RETURN_RUNES
FLAG_RENEW_DESTROY_RUNES
```

Example:

```text
SCRIPT CUT_1002_FINAL_CHOICE
    SHOW_DIALOGUE LOKI 10020
    SHOW_CHOICE CHOICE_FINAL_ROUTE

    IF_FLAG FLAG_ROUTE_PRESERVE
        CHANGE_MAP ARENA_NIDHOGGR 8 8
    END_IF

    IF_FLAG FLAG_ROUTE_RENEW
        CHANGE_MAP ARENA_LOKI_TRUE_FORM 8 8
    END_IF
END_SCRIPT
```

---

# Example: Midgard Boss Resolution

```text
SCRIPT CUT_102_DRAUGR_JARL_DEFEATED
    FADE_OUT 30
    SHOW_DIALOGUE ASTRID 10201
    SET_FLAG FLAG_DRAUGR_JARL_DEFEATED
    GIVE_RUNE RUNE_LIGHT
    SET_FLAG FLAG_RUNE_LIGHT_OBTAINED
    ADD_PARTY_MEMBER ASTRID
    COMPLETE_QUEST QUEST_DYING_BRANCH
    PLAY_SFX SFX_RUNE_OBTAINED
    CHANGE_MAP YGGDRASIL_SANCTUARY 12 8
    FADE_IN 30
END_SCRIPT
```

---

# Example: DQ-Style Save Point

```text
SCRIPT SAVE_NORN_SHRINE
    SHOW_DIALOGUE NORN_SHRINE 9001
    SHOW_CHOICE CHOICE_SAVE_GAME

    IF_FLAG FLAG_PLAYER_CHOSE_SAVE
        OPEN_SAVE_MENU
    END_IF
END_SCRIPT
```

---

# Error Handling

If a command fails:

```text
Log Error
Skip Command
Continue Script
```

Fatal script errors:

* Missing script ID
* Invalid map transition
* Missing boss encounter
* Broken final route choice

Fatal errors should return to title screen in release builds.

---

# Limits

| System                  | Limit |
|-------------------------|-------|
| Max commands per script | 256   |
| Max active script stack | 4     |
| Max conditional nesting | 3     |
| Max dialogue line ID    | 99999 |
| Max event flags         | 2048  |
| Max scripts per map     | 128   |

---

# Development Rules

Required:

* Every boss defeat must set a flag.
* Every Rune reward must set a Rune flag.
* Every party join must set a party flag.
* Every permanent choice must set exactly one route/state flag.
* Every map transition must specify map ID and coordinates.

Forbidden:

* Infinite loops.
* Nested scripts deeper than 4.
* Giving the same Rune twice.
* Starting battles during dialogue.
* Saving during battle scripts.

---

# Technical Goal

```text
Provide a readable, reliable event scripting system suitable for story-heavy Nintendo DS RPG development.
```

---

End of File
