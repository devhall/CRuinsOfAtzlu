#include "Inventory.h"

// returns a pointer to a pre-populated inventory linked-list
Item* create_inventory()
{
    Item* head = load_inv_from_file();

    return head;
}

void add_to_inventory(Item* item_to_add, Item* inv)
{
    if (NULL == item_to_add || NULL == inv)
    {
        /* if we have null pointers, just return */
        return;
    }
    
    printf("\n*** Adding: %s to your inventory.***\n", item_to_add->name);

    /* check to see if the item already exists */
    while(inv)
    {
        if (inv->id == item_to_add->id)
        {
            /* if this is a unique item, don't do anything */
            if (inv->unique)
            {
                printf("*** You already have %s in your possession.***\n", inv->name);
                return;
            }
            else
            {
                /* add to qty of existing item */
                inv->qty += 1;

                /* free memory of new item */
                free(item_to_add);
                return;
            }
        }
        
        if (NULL == inv->next)
        {
            /* came to end of list, item doesn't already exist, so add it */
            inv->next = item_to_add;
            inv->next->next = NULL;
            return;
        }
        inv = inv->next;
    }
}

Item* remove_from_inventory(int id, Item* inv)
{
    Item* head, *item_to_delete = NULL;
    
    if (NULL == inv)
        return NULL;
    head = inv;

    /* handle head case */
    if (head->id == id)
    {
        /* if we don't have anything else and we're removing the only Item left, 
           inventory is now null */
        if (NULL == head->next)
            return NULL;
        else
        {
            item_to_delete = head;
            head = head->next;
            printf("\n*** Removing: %s ***\n", item_to_delete->name);
            free(item_to_delete);
            return head;
        }
    }

    /* find Item by id */
    while(inv)
    {
        if (NULL == inv->next)
        {
            /* Apparently item does not exist, return head */
            return head;
        }
       
       
        /* Otherwise, keep searching */
        if (inv->next->id == id)
        {
           /* found match */
           item_to_delete = inv->next;
           inv->next = item_to_delete->next;
           printf("\n*** Removing: %s ***\n", item_to_delete->name);
           free(item_to_delete);
           break;
        }
        else
           inv = inv->next;
    }
    return head;
}

void display_inventory(Item* inv)
{
    if (NULL == inv)
    {
        printf("\nYou do not currently carry anything\n");
        return;
    }

    printf("\nYou carry:\n");
    while(inv)
    {
        printf("%s x %d\n", inv->name, inv->qty);
        inv = inv->next;
    }
}

/* load initial inventory from file and return linked list of items */
Item* load_inv_from_file()
{
    FILE *fp;
    Item* itm = NULL;
    Item* head = NULL;
    char line[BUFSIZ];

    fp = fopen("inv.dat", "r");

    while(!feof(fp))
    {
        
        /* read line from file into buffer */
        fgets(line, BUFSIZ, fp);
        if (*line == '#')
        {    
            continue; /* ignore lines with comments # */
        }
        else
        {
            /* first time through, allocate mem to initial item */
            if (NULL == itm)
            {
                itm = (Item*)malloc(sizeof(Item));
            }
            else
            {
                /* otherwise, allocate mem for next item and move itm pointer to it */
                itm->next = (Item*)malloc(sizeof(Item));
                itm = itm->next;
            }

            /* parse line buffer into item struct */
            sscanf(line, "%d %d %d %d %[^\n]s", &itm->id, &itm->value, &itm->qty, &itm->unique, &itm->name);

            /* first time through, set head to initial item */
            if (NULL == head)
            {
                head = itm;
            }
        }
    }

    /* At this point, we're done loading inventory items. Set the last *next pointer to null */
    itm->next = NULL;

    fclose(fp);

    return head;
}