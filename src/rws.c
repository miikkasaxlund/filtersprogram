/* 
 * File:   rws.c
 * Author: Miikka Saxlund
 * Brief: A filter program to remove whitespace
 *
 * Created on 03 January 2020, 14:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * @brief Filter function
 * 
 * Filters whitespace from the stream
 * 
 * @param input a pointer to the standard input stream
 * @param output a pointer to the standard output stream
 */

int filter( FILE *input, FILE *output )
{
    /* 
     * Define a variable for storing the returned character 
     * from the input stream
     */
    char ch;

    // Loop through the stream until the end-of-file indicator
    while ( !feof( input ) ) {
        // Return in case of occurring error indicator
        if ( ferror( input ) ) {
            return 1;
        }
        /* 
         * Get a character from the stream and advance
         * the position indicator for the stream
         */
        ch = fgetc(input);
        /* 
         * Check that spaces, tab characters or an 
         * end-of-file indicators are not found and
         * write the character to the output stream
         */
        if (ch != ' ' || ch != '\t' && !feof( input )) {
          fputc(ch, output);
        }
    }
    return 0;
}

/*
 * @brief Main function
 * 
 * Passes the stdin stream to the filter function to be filtered
 * and flushes the output buffer so it can be outputted to the
 * stdout output stream
 */

int main(void)
{
    // Get the return value from the filter function
    const int retval = filter( stdin, stdout );
    // Flush the output buffer and move the buffered data to console
    fflush( stdout );
    // Return the return value
    return retval;
}
