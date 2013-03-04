/* 
 * File:   Combat.h
 * Author: devin
 *
 * Created on March 2, 2013, 2:18 PM
 */

#ifndef COMBAT_H
#define	COMBAT_H

#include "Mob.h"
#include "Hero.h"
#include "utils.h"



/* runs a battle; takes a hero pointer, but a copy of the mob (as it's destroyed after this function) */
void battle(Hero* h, Mob the_mob);

/* process one round of battle */
void process_battle_rnd(Hero* h, Mob* m, int hero_is_attacker);

/* checks if attacker hits - uses flag 'hero_is_attacker' 
 * if hero is attacking, otherwise '0' if enemy is attacking
 * - returns true or false */
int check_for_hit(Hero* h, Mob* m, int hero_is_attacker);

#endif	/* COMBAT_H */

