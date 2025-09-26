/*
* --------------------------------------------------
Project:
File:    mystring.c
Author:  Mustafa Qasim
Version: 2025-09-25
--------------------------------------------------
*/

#include "mystring.h"

/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.
 *
 * @param s - char pointer to a string
 * @return - return the number of words.
 */
int str_words(char *s)
{
    int wordCount = 0;
    int wordStart = 0;
    char c;
    for (int i = 0; s[i] != 0; i++)
    {
        c = s[i];
        if (wordStart == 0)
        {
            if ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z')
            {
                wordStart = 1;
                wordCount++;
            }
        }
        else
        {
            if (c == ' ' || c == 9 || c == '.' || c == ',')
            {
                wordStart = 0;
            }
        }
    }

    return wordCount;
}

/**
 * Change every upper case English letter to its lower case of string passed by s.
 *
 * @param s - char pointer to a string
 * @return - return the number of actual flips.
 */
int str_lower(char *s)
{
    char c = s[0];
    int i = 0;
    int flips = 0;
    while (c != 0)
    {
        if ('A' <= c && c <= 'Z')
        {
            c += 32;
            s[i] = c;
            flips++;
        }
        i++;
        c = s[i];
    }
    return flips;
}

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a string
 */
void str_trim(char *s)
{
    char *src = s;
    char *dst = s;
    int prev_space = 0;

    while (*src)
    {
        if (*src == ' ')
        {
            if (!prev_space)
            {
                *dst++ = ' ';
                prev_space = 1;
            }
        }
        else if (*src == '\n')
        {
            *dst++ = '\n';
            prev_space = 0;
        }
        else
        {
            *dst++ = *src;
            prev_space = 0;
        }
        src++;
    }
    // Remove trailing space before null or newline, if present
    if ((dst > s) && (*(dst - 1) == ' '))
        dst--;
    *dst = '\0';
}