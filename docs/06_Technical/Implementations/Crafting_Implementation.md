# Crafting_Implementation.md

````markdown id="c7r4yf"
# Crafting Implementation
## Yggdrasil Saga
### Version 1.0

---

# Purpose

This document defines the technical implementation of the Crafting System.

It supplements:

- Crafting_System.md
- Achievement_Implementation.md
- Save_Migration.md
- Testing_Plan.md

This document focuses on:

- Recipe management
- Material consumption
- Equipment creation
- Upgrade systems
- Rune forging
- Save integration

---

# Design Goals

The Crafting System must:

- Be simple to expand
- Require minimal memory
- Be deterministic
- Support progression
- Prevent duplication exploits
- Operate without dynamic allocation

---

# System Overview

Crafting consists of:

1. Recipe Unlock
2. Material Collection
3. Recipe Selection
4. Validation
5. Crafting Execution
6. Reward Processing

---

# Crafting Categories

```c
typedef enum
{
    CRAFT_WEAPON,
    CRAFT_ARMOR,
    CRAFT_ACCESSORY,
    CRAFT_CONSUMABLE,
    CRAFT_RUNE,
    CRAFT_UPGRADE

} crafting_category_t;
```

---

# Recipe IDs

```c
typedef enum
{
    RECIPE_IRON_BLADE,
    RECIPE_HUNTERS_BOW,
    RECIPE_WOLF_CLOAK,
    RECIPE_RUNE_DAGGER,

    RECIPE_COUNT

} recipe_id_t;
```

Recipe IDs must never be reordered after release.

New recipes are appended only.

---

# Material IDs

Reference Item Database.

```c
typedef enum
{
    MATERIAL_BOAR_TUSK,
    MATERIAL_WOLF_PELT,
    MATERIAL_SPIRIT_ESSENCE,
    MATERIAL_MYTHRIL,

    MATERIAL_COUNT

} material_id_t;
```

---

# Recipe Definition

Static data.

```c
typedef struct
{
    recipe_id_t id;

    item_id_t result_item;

    uint16_t result_quantity;

    crafting_category_t category;

} recipe_definition_t;
```

---

# Recipe Cost Definition

```c
typedef struct
{
    material_id_t material;

    uint16_t quantity;

} recipe_cost_t;
```

---

# Example Recipe

Iron Blade

```c
Recipe:
Iron Blade

Requires:
5 Iron Ore
2 Wolf Pelts

Produces:
1 Iron Blade
```

---

# Recipe Database

Stored in ROM.

```c
const recipe_definition_t
g_recipe_database[];
```

---

# Recipe Unlock Data

Stored in save file.

```c
typedef struct
{
    bool unlocked;

} recipe_state_t;
```

---

# Crafting Save Data

```c
typedef struct
{
    recipe_state_t recipes[RECIPE_COUNT];

    uint32_t total_items_crafted;

} crafting_save_t;
```

---

# Recipe Unlock Methods

Recipes may unlock through:

- Story progression
- NPC rewards
- Arena rewards
- Rare discoveries
- NG+ content

---

# Unlock Function

```c
void recipe_unlock(
    recipe_id_t id)
{
    save.crafting.recipes[id].unlocked = true;
}
```

---

# Crafting Validation

Before crafting:

Verify:

1. Recipe unlocked
2. Materials owned
3. Inventory space available

---

# Validation Example

```c
if(player_materials < required_materials)
{
    return false;
}
```

---

# Material Consumption

Materials removed immediately after successful validation.

Example:

```c
inventory_remove_item(
    MATERIAL_WOLF_PELT,
    2);
```

---

# Crafting Execution

Process:

```text
Select Recipe
↓
Validate Materials
↓
Consume Materials
↓
Create Item
↓
Add To Inventory
↓
Trigger Events
↓
Save Data
```

---

# Item Creation

```c
inventory_add_item(
    result_item,
    quantity);
```

---

# Crafting Statistics

Tracked:

```c
total_items_crafted
```

Used for:

- Achievements
- Completion tracking

---

# Crafting Events

Events generated:

```c
EVENT_ITEM_CRAFTED
EVENT_RECIPE_UNLOCKED
EVENT_UPGRADE_COMPLETE
EVENT_RUNE_FORGED
```

---

# Achievement Integration

Reference:

Achievement_Implementation.md

---

Examples:

- Apprentice Smith
- Skilled Artisan
- Master Artisan
- Rune Forger
- Worldsmith

---

# Equipment Upgrades

Equipment can be upgraded.

Range:

```text
+0 → +5
```

---

# Upgrade Levels

```c
typedef uint8_t upgrade_level_t;
```

Maximum:

```c
5
```

---

# Upgrade Save Data

Stored per equipment instance.

```c
typedef struct
{
    item_id_t item;

    uint8_t upgrade_level;

} equipment_instance_t;
```

---

# Upgrade Cost Formula

Example:

```text
+1 = Base Cost × 1
+2 = Base Cost × 2
+3 = Base Cost × 4
+4 = Base Cost × 8
+5 = Base Cost × 16
```

---

# Upgrade Validation

Verify:

- Equipment exists
- Upgrade below max
- Materials available
- Gold available

---

# Upgrade Success

Yggdrasil Saga uses:

```text
100% Success Rate
```

No RNG failures.

---

# Rune Forging

Special crafting category.

Unlocked:

Svartalfheim Completion

---

# Rune Weapon Definition

```c
typedef struct
{
    item_id_t weapon;

    rune_id_t required_rune;

} rune_weapon_t;
```

---

# Rune Forging Requirements

Requires:

- Rune
- Rare Materials
- Gold

---

# Legendary Crafting

Highest crafting tier.

Requirements:

- Legendary Recipe
- Rare Materials
- Story Progression

---

# Mythic Crafting

Unlocked:

New Game Plus

Reference:

New_Game_Plus.md

---

Requirements:

- Mythic Materials
- Mythic Recipe
- Legendary Base Item

---

# Inventory Integration

Reference:

Inventory System

---

Verify:

Inventory capacity before item creation.

If full:

Crafting denied.

---

# Vendor Integration

Primary Crafting NPC:

Völund

---

Crafting Menu Options:

```text
Craft Equipment
Upgrade Equipment
Forge Rune Weapons
Legendary Crafting
```

---

# Crafting UI Data

Displays:

- Recipe Name
- Required Materials
- Current Materials
- Result Item
- Craft Button

---

# Crafting Queue

Not supported.

Nintendo DS memory optimization.

One craft per action.

---

# Save Requirements

Crafting data must persist:

- Save
- Load
- NG+
- Version migration

Reference:

Save_Migration.md

---

# Memory Budget

Crafting Runtime:

Maximum 8 KB

Crafting Save Data:

Maximum 4 KB

Total Budget:

Less than 16 KB

---

# Performance Requirements

Crafting operations must:

- Complete instantly
- Avoid frame drops
- Avoid dynamic allocation

Target:

Less than 1 ms execution time

---

# Debug Support

Reference:

Debug_Tools.md

---

## Debug Commands

Unlock Recipe

```c
debug_unlock_recipe(id);
```

---

Unlock All Recipes

```c
debug_unlock_all_recipes();
```

---

Add Materials

```c
debug_add_material();
```

---

Force Craft

```c
debug_force_craft();
```

---

Set Upgrade Level

```c
debug_set_upgrade_level();
```

---

# Testing Requirements

Reference:

Testing_Plan.md

---

Verify:

- Recipe unlocking
- Material consumption
- Upgrade progression
- Rune forging
- Legendary crafting
- NG+ Mythic crafting
- Save persistence

---

# Future Expansion

Additional crafting content may be added by:

1. New recipes
2. New materials
3. New upgrade tiers
4. New crafting categories

Existing recipe IDs must never change.

---

# Core Crafting Principle

"Crafting should reward exploration, preparation, and progression—not random chance."
````
