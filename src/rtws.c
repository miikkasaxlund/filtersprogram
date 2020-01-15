/* 
 * File:   rtws.c
 * Author: Miikka Saxlund
 * Brief: A filter program to remove trailing whitespace
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
    // Define the buffer and line end pointer variables
    char buffer[5000], *end;
    /*
     * Define an int for counting the trailing whitespace
     * characters
     */
    int count = 0;

    // Loop through the stream until the end-of-file indicator
    while ( !feof( input ) ) {
        // Return in case of occurring error indicator
        if ( ferror( input ) ) {
            return 1;
        }
        /*
         * Read a line from the input stream and store it into
         * the defined buffer
         */
        fgets(buffer, 5000, input);
        // Make the line end pointer point to the end of the buffer
        end = buffer + (strlen(buffer) - 1);
        /*
         * Loop the buffer from the end towards the beginning
         * while checking for whitespace characters and
         * counting the whitespace characters found
         */
        while (end > buffer && isspace(*end)) {
          end--;
          count++;
        }
        /*
         * If more than one whitespace character was found,
         * we can determine that we're not handling a line
         * that contains only the new-line character.
         * 
         * If so, add the newline character, carriage return
         * and a null terminator to the end of the buffer to
         * cut out the trailing whitespace
         */
        if (count > 1) {
          *(end + 1) = '\n';
          *(end + 2) = '\r';
          *(end + 3) = '\0';
        }
        // Write the buffer to the output stream
        fputs(buffer, output);
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
