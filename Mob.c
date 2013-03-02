#include "Mob.h"

void generate_mobs_from_file(Mob* mobs)
{
    
    FILE *fp;
    char line[BUFSIZ];
    int mob_count = 0;

    fp = fopen("mob.dat", "r");

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
            /* if we have more mobs in file than allowed in NUM_MOBS, 
               just ignore extras for now */
            if (mob_count == NUM_MOBS)
            {
                continue;
            }
            else
            {
            
                /* parse line buffer into mob struct */
                sscanf(line, "%d %d %d %d %d %d %[^\n]s", &mobs[mob_count].id, 
                                                          &mobs[mob_count].max_hp, 
                                                          &mobs[mob_count].atk, 
                                                          &mobs[mob_count].dfs, 
                                                          &mobs[mob_count].gold, 
                                                          &mobs[mob_count].unique, 
                                                          mobs[mob_count].name);

                /* for now, set cur_hp to max_hp base */
                mobs[mob_count].cur_hp = mobs[mob_count].max_hp;      

                ++mob_count;
            }
        }
    }
    fclose(fp);
}