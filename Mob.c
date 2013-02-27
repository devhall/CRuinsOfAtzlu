#include "Mob.h"

void generate_mobs_from_file(Mob* mobs)
{
    
    FILE *fp;
    char line[BUFSIZ];
    int i = 0;

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
            
            /* Allocate some mem for the struct in array */
           // mobs[i] = (Mob*)malloc(sizeof(Mob)); 
            
            /* parse line buffer into mob struct */
            sscanf(line, "%d %d %d %d %d %d %[^\n]s", &mobs[i].id, &mobs[i].max_hp, &mobs[i].atk, &mobs[i].dfs, &mobs[i].gold, &mobs[i].unique, mobs[i].name);
           
            /* for now, set cur_hp to max_hp base */
            mobs[i].cur_hp = mobs[i].max_hp;      
            
            ++i;
        }
    }
    fclose(fp);
}