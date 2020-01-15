/* 
 * File:   rel.c
 * Author: Miikka Saxlund
 * Brief: A filter program to remove empty lines from the input
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
    // Define the buffer and file pointer variables
    char buffer[5000], *fp;
    
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
        // Make the pointer point to the beginning of the buffer
        fp = buffer; 
        /*
         * Skip whitespace from the beginning of the line
         * 
         * While a space or a tab character is found, increment
         * the pointer
         */
        while (*fp == ' ' || *fp == '\t') fp++;
        // If carriage return is found, increment the pointer
        if (*fp == '\r') fp++;
        /*
         * If the next character is not a new-line character,
         * write the buffer to the output stream
         */
        if (*fp != '\n') {
          fputs(buffer, output);
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
