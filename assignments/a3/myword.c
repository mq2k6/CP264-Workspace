/*
* --------------------------------------------------
Project:
File:    myword.c
Author:  Mustafa Qasim
Version: 2025-09-25
--------------------------------------------------
*/

#include <stdio.h>
#include <string.h>
#include "mystring.c"
#include "myword.h"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

/*
 * Load word data from file, and insert words a directory represented by char array.
 *
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored.
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.
 */
int create_dictionary(FILE *fp, char *dictionary)
{
    char line[MAX_LINE_LEN];              // handles MAX_LINE_LEN number of characters at a time
    char delimiters[] = " .,\n\t\r";      // checks for these delimiters
    char *token;                          // pointer to the token word
    int count = 0;                        // number of words
    while (fgets(line, MAX_LINE_LEN, fp)) // while the file has characters to go through
    {
        token = (char *)strtok(line, delimiters); // token pointer points to the first character of the line, split into words using the delimiters array as splitting points
        str_lower(token);                         // lowercase the token word
        str_trim(token);                          // remove unnecessary whitespaces

        while (token != NULL) // while the token isn't a null value
        {
            count++;                   // increase the word count
            strcat(dictionary, token); // add the token word char by char
            strcat(dictionary, ",");   // add a comma to the dictionary

            token = (char *)strtok(NULL, delimiters); // continuing from where the thing left off, split the string by a delimiter (essentially goes to the next word)
        }
    }
    return count;
}

/*
 * Determine if a given word is contained in the given dictionary.
 *
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.
 *
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.
 */
BOOLEAN contain_word(char *dictionary, char *word)
{
    char *p = dictionary; // shortcut for dictionary
    BOOLEAN found = FALSE;

    while (*p != 0 && found == FALSE) // while the char isn't null & word hasn't been found
    {
        if (*p == *word) // if the curr character matches first character of the word
        {

            char *tempcheck = p;  // temp variable to go through the curr word in the dictionary
            char *w = word;       // temp variable to run through the word
            BOOLEAN maybe = TRUE; // switch to trigger a break in the sequence following
            while (maybe == TRUE) // while the characters in the dict. and the word match...
            {
                if (*tempcheck != *w) // if the characters are mismatched
                {
                    maybe = FALSE;
                }
                tempcheck++; // advance temp dict. pointer from where it is in outside loop
                w++;         // advance temp wrd pointer. from where it is in outside loop

                if ((*tempcheck == ',' || *tempcheck == 0) && *w == 0) // if the word ends via comma or null alongside the end of the word to find
                {
                    found = TRUE;
                }
            }
        }
        p++; // advance dict. pointer if the characters in the dict and the word don't match
    }
    return found;
}

/*
 * Process text data from a file for word statistic information of line count, word count, keyword count, and frequency of keyword.
 *
 * @param *fp -  FILE pointer of input text data file. .
 * @param *words  -  WORD array for keywords and their frequencies.
 * @param *dictionary  -  stop-word/common-word dictionary.
 *
 * @return - WORDSTATS value of processed word stats information.
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary)
{
    char line[MAX_LINE_LEN];
    char *delimiters = " ,.\t\n\r";
    WORDSTATS ws = {0};
    char *word_token;
    while (fgets(line, MAX_LINE_LEN, fp))
    {
        ws.line_count++;
        word_token = (char *)strtok(line, delimiters);

        while (word_token != 0)
        {
            str_lower(word_token);

            if (contain_word(dictionary, word_token))
            {
                ws.word_count++;
                int wi = 0;
                while (wi < ws.keyword_count && strcmp(word_token, words[wi].word) != 0)
                    wi++;


                if (wi < ws.keyword_count)
                    words[wi].count++;
                else
                {
                    ws.keyword_count++;
                    strcpy(words[wi].word, word_token);
                    words[wi].count = 1;
                }
            }


            word_token = (char *)strtok(NULL, delimiters);
        }
    }
    return ws;
}