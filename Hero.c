#include "Hero.h"

Hero* create_hero()
{
    Hero* h = (Hero*)malloc(sizeof(Hero));

    h->id = 999;
    h->name = "Runeu";
    h->max_hp = 12;
    h->cur_hp = h->max_hp;
    h->atk = 10;
    h->dfs = 5;
    h->gold = 50;
    h->is_alive = 1;
    h->inv = create_inventory();

    return h;
}
    
