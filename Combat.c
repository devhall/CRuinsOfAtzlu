#include "Combat.h"

static int rnd = 1; /* keeps track of battle rounds */


void battle(Hero* h, Mob the_mob)
{
    /* for now, hero always attacks first at beginning of battle */
    int hero_is_attacking = 1;
    
    /* for now, set copy of the mob to being alive */
    the_mob.is_alive = 1;
    
    printf("\n***** Battle! *****\n");
    wait(1);
    printf("\nYou engage with %s! \n", the_mob.name);
    wait(1);
    
    while (h->is_alive && the_mob.is_alive)
    {
        process_battle_rnd(h, &the_mob, hero_is_attacking);
        
        /* check for hero death */
        if (!h->is_alive)
        {
            printf("\n***** You've been killed! *****\n");
            wait(3);
            printf("\nBetter luck next time!\n");
        }
        
        /* check for mob death */
        if (!the_mob.is_alive)
        {
            printf("\n***** You've slain %s!*****\n", the_mob.name);
            wait(2);
        }
        
        /* switch attacker */
        if (hero_is_attacking)
        {
            hero_is_attacking = 0;
        }
        else
        {
            hero_is_attacking = 1;
        }
    }
    
   
    /* reset battle round counter */
    rnd = 1;
    printf("\n***** End Combat *****\n");
}

void process_battle_rnd(Hero* h, Mob* m, int hero_is_attacker)
{
    int dmg;
    printf("\n*** Round: %d %s HP: %d/%d  %s HP: %d/%d\n", rnd, h->name, h->cur_hp, h->max_hp, 
                                                                m->name, m->cur_hp, m->max_hp);
    wait(2);
    
    /* perform battle round here */
 
    if (check_for_hit(h, m, hero_is_attacker))
    {
        if (hero_is_attacker)
        {
            /* get dmg */
            dmg = h->atk - m->dfs;
            printf("\n%s attacks %s for %d points of damage!\n", h->name, m->name, dmg);
            m->cur_hp -= dmg;
            
            if (m->cur_hp <= 0)
            {
                m->is_alive = 0;
            }
        }
        else
        {
            /* get dmg */
            dmg = m->atk - h->dfs;
            printf("\n%s attacks YOU for %d of damage!\n", m->name, dmg);
            h->cur_hp -= dmg;
            
            if (h->cur_hp <= 0)
            {
                h->is_alive = 0;
            }
        }
    }
    else
    {
        if (hero_is_attacker)
        {
            printf("\nYou MISS!\n");
        }
        else
        {
            printf("\n%s attacks but misses!\n", m->name);
        }
    }

    
    wait(1);
    ++rnd;
}

int check_for_hit(Hero* h, Mob* m, int hero_is_attacker)
{
    int roll;
    
    /* find out who is attacking */
    if (hero_is_attacker)
    {
         /* really simple formula for now:
          -check attacker's atk vs enemy's dfs 
          -if it's positive, then 80% chance of hit */
        if ((h->atk - m->dfs) > 0)
        {
            /* roll for 100 */
            roll = get_random_int(100);

            /* if '80' or lower, we hit */
            if (roll <= 80)
            {
                return 1;
            }
        }
        /* otherwise, we miss */
        return 0;
    }
    else
    {
        /* mob is attacking */
        if ((m->atk - h->dfs) > 0)
        {
            /* roll for 100 */
            roll = get_random_int(100);
            
            /* if '80' or lower, we hit */
            if (roll <= 80)
            {
                return 1;
            }
        }
        /* otherwise, we miss */
        return 0;
    }
}
    
