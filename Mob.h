#ifndef MOB_H
#define MOB_H

#define NUM_MOBS    5

#include <stdio.h>
#include <stdlib.h>

typedef struct Mob{
    int id;
    char name[50];
    int cur_hp;
    int max_hp;
    int atk;
    int dfs;
    int gold;
    int unique;
} Mob;

/* Generates an array of mobs */
void generate_mobs_from_file(Mob* mobs);

#endif