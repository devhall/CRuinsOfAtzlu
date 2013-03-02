#include "utils.h"


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