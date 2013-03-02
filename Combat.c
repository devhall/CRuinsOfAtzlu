#include "Combat.h"

static int rnd = 1; /* keeps track of battle rounds */


void battle(Hero* h, Mob the_mob)
{
    printf("\n***** Battle! *****\n");
    wait(1);
    printf("\nYou engage with %s! \n", the_mob.name);
    wait(1);
    
    int i;
    for (i = 0; i < 5; ++i)
    {
        process_battle_rnd(h, &the_mob);
    }
    
    /* reset battle round counter */
    rnd = 1;
    
    printf("\n***** End Combat *****\n");
}

void process_battle_rnd(Hero* h, Mob* m)
{
    
    printf("*** Round: %d\n", rnd);
    wait(1);
    
    ++rnd;
}
