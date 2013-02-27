#ifndef HERO_H
#define HERO_H

#include "Inventory.h"

typedef struct Hero{
    int id;
    char* name;
    int cur_hp;
    int max_hp;
    int atk;
    int dfs;
    int gold;
    Item* inv;
} Hero;

/* Generates a default hero character */
Hero* create_hero();

#endif