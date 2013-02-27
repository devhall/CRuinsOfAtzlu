#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Item{
    int id;
    char name[50];
    int value;
    int qty;
    int unique;
    struct Item* next;
} Item;

/* returns a pointer to an inventory linked-list */
Item* create_inventory();

/* add an item to inventory */
void add_to_inventory(Item* item_to_add, Item* inv);

/* removes an item from inventory, using item's id and returns new pointer to head of inventory */
Item* remove_from_inventory(int id, Item* inv);

/* prints out the contents of inventory linked list */
void display_inventory(Item* inv);

/* loads starting inventory from file */
Item* load_inv_from_file();

#endif
