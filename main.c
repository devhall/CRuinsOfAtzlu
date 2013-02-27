#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include "Inventory.h"
#include "Hero.h"
#include "Mob.h"


#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif


void wait(int seconds)
{
#ifdef _WIN32
    Sleep(1000 * seconds);
#else
    sleep(seconds);
#endif
}

void get_user_input(char* user_input)
{
    fgets(user_input, BUFSIZ, stdin);
}

/* This strips the first char from user input */
int get_user_char(char* user_input)
{
    int user_char;
    fgets(user_input, BUFSIZ, stdin);
    user_char = user_input[0];
    if (isdigit(user_char))
    {
        /* convert char to digit */
        user_char -= '0';
    }
    return user_char;
}

/* returns random int 
   from: http://stackoverflow.com/questions/2999075/generate-a-random-number-within-range/2999130#2999130 */
int get_random_int(int limit)
{
    int divisor = RAND_MAX / (limit + 1);
    int rv;
    
    do
    {
        rv = rand() / divisor;
    } while (rv > limit);
    
    return rv;
}

void display_intro()
{
    printf("Welcome to CRuins of Atzlu! A C program!\n");
    wait(2);
}

void display_main_menu()
{
    printf("\n1 - Start Game\n");
    printf("2 - Create a character\n");
    printf("3 - Save a character\n");
    printf("4 - Load a character\n");
    printf("5 - Status\n");
    printf("q - Quit\n\n");
}

void display_game_menu()
{
    printf("\nWhat do you want to do?\n");
    printf("\n1 - Explore\n");
    printf("2 - Fight a random enemy\n");
    printf("3 - Go to Town\n");
    printf("4 - Rest\n");
    printf("5 - Status\n");
    printf("q - Quit\n\n");
}

void load_resources(Mob* list)
{
    generate_mobs_from_file(list);
}

void start_game(Hero* h)
{
    Mob* mobs_list = (Mob*)malloc(sizeof(Mob) * NUM_MOBS);
    Hero* the_hero = h;
    int game_running;
    load_resources(mobs_list);
    
    wait(1);
    printf("\nEntering game...\n");
    wait(1);

    // start loop here
    game_running = 1;
    while (game_running)
    {
        char input_buf[BUFSIZ];
        int user_input;

        display_game_menu();
        user_input = get_user_char(input_buf);

        switch (user_input)
        {
        case 1:
            printf("\nExploring the lands of Abrun!\n");
            /* TODO: Add "Exploring" functionality here */
            break;
        case 2:
            printf("\nFighting random battle\n");
            /* TODO: Add random battle functionality here */
            wait(1);
            int rand = get_random_int(NUM_MOBS - 1);
            printf("\nYou might encounter: %s\n", mobs_list[rand].name);
            
            break;
        case 3:
            printf("\nEntering Town of Korith\n");
            /* TODO: Add town functionality here */
            break;
        case 4:
            printf("\nResting\n");
            /* TODO: Add rest functionality here */
            break;
        case 5:
            printf("\nDisplaying status\n");
            /* TODO: Add player status display functionality here */
            /* For now, displaying inventory */
            display_inventory(the_hero->inv);
            break;
        case 'q':
            game_running = 0;
            free(mobs_list);
            break;
        default:
            printf("\nThat's a non-answer. Please try again.\n");
            break;
        }
    }
}



int main()
{
    char input_buf[BUFSIZ];
    int user_input, game_is_running;
    Hero* p_hero = NULL;

    display_intro();

    game_is_running = 1;
    while(game_is_running)
    {
        display_main_menu();
        user_input = get_user_char(input_buf);

        switch (user_input)
        {
        case 1:
            if (NULL == p_hero)
            {
                printf("\nIt appears that you need to either load or create a hero first!\n");
            }
            else
            {
                start_game(p_hero);
            }
            break;
        case 2:
            printf("\nCreating hero\n");
            if (NULL == p_hero)
            {
                p_hero = create_hero();
            }
            else
            {
                printf("\nYou already seem to have a hero. (\"%s\" ring any bells?)\n", p_hero->name);
            }
            break;
        case 3:
            printf("\nSaving character\n");
            /* TODO: Add file save functionality here */
            break;
        case 4:
            printf("\nLoading character\n");
            /* TODO: Add file load functionality here */
            break;
        case 5:
            printf("\nDisplaying status\n");
            /* TODO: Add player status display functionality here */
            break;
        case 'q':
            game_is_running = 0;
            free(p_hero);
            printf("\nGoodbye!\n");
            break;
        default:
            printf("\nThat's a non-answer. Please try again.\n");
            break;
        }
    }

    return 0;
}