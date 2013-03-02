/* 
 * File:   utils.h
 * Author: devin
 *
 * Created on March 2, 2013, 2:44 PM
 */

#ifndef UTILS_H
#define UTILS_H
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

void wait(int seconds);
void get_user_input(char* user_input);
int get_user_char(char* user_input);
int get_random_int(int limit);

#endif	/* UTILS_H */

