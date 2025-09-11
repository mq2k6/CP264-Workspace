/*
* --------------------------------------------------
Project: a1q1
File:    mychar.c
Author:  Mustafa Qasim
Version: 2025-09-CURRENT_DAY
--------------------------------------------------
*/

#include "mychar.h"

char upperalpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char loweralpha[] = "abcdefghijklmnopqrstuvwxyz";
int digit[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

/**
 * Determine the type of a char character.
 *
 * @param c - char type
 * @return - 0 if c is a digit
             1 if c is an arithmetic operator
             2 if c is the left parenthsis (
             3 if c is the right parenthsis )
             4 if c is an English letter;
             otherwise -1.
 */
int mytype(char c)
{
    int x = c - '0';
    int L = -1;
    if (x <= 9 && x >= 0)
    {
        L = 0;
    }

    else if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        L = 1;
    }

    else if (c == '(')
    {
        L = 2;
    }

    else if (c == ')')
    {
        L = 3;
    }

    else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        L = 4;
    }

    return (L);
}

/**
 * Flip the case of an English character.
 *
 * @param c - char type
 * @return -  c's upper/lower case letter if c is a lower/upper case English letter.
 */
char case_flip(char c)
{
    char x = -1;
    for (int i = 0; i < 27; i++)
    {
        if (c == loweralpha[i])
        {
            x = upperalpha[i];
        }
        else if (c == upperalpha[i])
        {
            x = loweralpha[i];
        }
    }
    return (x);
}

/**
 * Convert digit character to the corresponding integer value.
 *
 * @param c - char type value
 * @return - its corresponding integer value if c is a digit character;
 *           otherwise -1.
 */
int digit_to_int(char c)
{
    int x = c - '0';
    return (x);
}