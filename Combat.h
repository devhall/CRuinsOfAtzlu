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
void process_battle_rnd(Hero* h, Mob* m);

#endif	/* COMBAT_H */

