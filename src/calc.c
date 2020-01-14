/* 
 * File:   calc.c
 * Author: Miikka Saxlund
 * Brief: Program to calculate lines, chars, spaces and words from an input
 * 
 * Created on 03 January 2020, 14:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * @brief Calculation function
 * 
 * Calculates lines, chars, spaces and words from an input stream
 * 
 * @param input a pointer to the standard input stream
 * @param output a pointer to the standard output stream
 */

int calculate( FILE *input, FILE *output )
{
    // Define essential variables
    int lines = 0;
    int chars = 0;
    int spaces = 0;
    int words = 0;
    int ch, prevchar;

    // Loop through the stream until the end-of-file indicator
    while ( !feof( input ) ) {
        // Return in case of occurring error indicator
        if ( ferror( input ) ) {
            return 1;
        }
        /* 
         * Get the next character from the stream and advance
         * the position indicator for the stream
         */
        ch = fgetc(input);
        /*
         * If a new-line character is found increment lines and chars
         */
        if (ch == '\n') {
            lines++;
            chars++;
        } 
        /*
         * If a white-space character is found increment spaces and chars
         * 
         * This includes spaces, horizontal and vertical tabs,
         * new-line, feed and carriage return characters
         */
        else if (isspace(ch)) {
            spaces++;
            chars++;
        } 
        // Otherwise increment chars
        else {
            chars++;
        }
        /*
         * Check if the previous character was an alphabetic letter
         * and the current character is not an alphabetic letter
         * 
         * In such case, increment the word count
         */
        if (isalpha(prevchar) && !isalpha(ch)) words++;
        // Set the current character as the prevchar
        prevchar = ch;
    }

    /*
     * Define the string containing the calculated values
     * and write it to the output stream
     */
    char retStr[1000];
    sprintf(retStr, "WORDS=%d\nLOC=%d\nCHARS=%d\nSPACES=%d", words, lines, chars, spaces);
    fputs(retStr, output);
    return 0;
}

/*
 * @brief Main functiongi
 * 
 * Reads stdin, calculates parameters from the stream, and outputs
 * the calculations to the stdout stream
 */

int main(void)
{
    // Get the return value from the calculate function
    const int retval = calculate( stdin, stdout );
    // Flush the output buffer and move the buffered data to console
    fflush( stdout );
    // Return the return value
    return retval;
}