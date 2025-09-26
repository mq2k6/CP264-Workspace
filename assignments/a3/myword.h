/*
* --------------------------------------------------
Project:
File:    myword.h
Author:  Mustafa Qasim
Version: 2025-09-25
--------------------------------------------------
*/

#ifndef MYWORD_H
#define MYWORD_H

#include <stdio.h>

/*
 * Define enumeration type BOOLEAN with value FALSE = 0 and TRUE 1.
 */
typedef enum boolean
{
    FALSE = 0,
    TRUE = 1
} BOOLEAN;

/*
 * Define structure type WORD consists of char word[20] to store a word, int count to hold frequency of the word.
 */
typedef struct word
{
    char word[20];
    int count;
} WORD;

/*
 * Define structure type WORDSTATS consisting of int line_count, int word_count, and int keyword_count to represent
 * to represent the number of lines, number of all words, and the number of different non-common-word in text data.
 */
typedef struct wordstats
{
    int line_count, word_count, keyword_count;
} WORDSTATS;

int create_dictionary(FILE *fp, char *dictionary);

BOOLEAN contain_word(char *dictionary, char *word);

WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary);

#endif