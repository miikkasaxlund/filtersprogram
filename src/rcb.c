/* 
 * File:   rcb.c
 * Author: Miikka Saxlund
 * Brief: A filter program to remove comment blocks from the input
 *
 * Created on 03 January 2020, 14:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*
 * @brief Filter function
 * 
 * Filters multi-line comment blocks from the stream
 * 
 * @param input a pointer to the standard input stream
 * @param output a pointer to the standard output stream
 */

int filter( FILE *input, FILE *output )
{
    // Define the essential variables
    char ch, prevch;
    bool endFound = false;

    // Loop through the stream until the end-of-file indicator
    while ( !feof( input ) ) {
        // Return in case of occurring error indicator
        if ( ferror( input ) ) {
            return 1;
        }
        /* 
         * Get a character from the stream and advance
         * the position indicator for the stream. Save
         * the found character to the prevchar variable
         * for later usage
         */
        ch = fgetc(input);
        prevch = ch;
        // Check for a slash character
        if (ch == '/') {
          ch = fgetc(input);
          // Check for an asterisk character
          if (ch == '*') {
            /* 
             * Comment start
             *
             * Loop until end is found
             */
            while (!endFound) {
              // Advance in the stream
              ch = fgetc(input);
              // If an asterisk is found
              if (ch == '*') {
                // Advance in the stream
                ch = fgetc(input);
                /*
                 * If a trailing slash is found,
                 * the end of the comment is found
                 */
                if (ch == '/') {
                  /*
                   * Set the endFound variable to true so
                   * that the loop wont run after current
                   * iteration
                   */
                  endFound = true;
                  /*
                   * Advance in the stream until new-line
                   * character is found so that the remaining
                   * parts of the multi-line comment is not
                   * written to the output stream
                   */
                  do {
                    ch = fgetc(input);
                  } while (ch != '\n');
                  // Advance once more to get rid of the empty line
                  ch = fgetc(input);
                }
              }
            }
          }
          /* 
           * If only one slash character was found, write
           * the previously found character to the stream
           */
          else {
            fputc(prevch, output);
          }
        }
        /*
         * Check that the end-of-file indicator is not found
         * and write the character to the output stream
         */
        if (!feof( input )) {
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
