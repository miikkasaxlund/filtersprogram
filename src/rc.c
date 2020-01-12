/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: miikk
 *
 * Created on 03 January 2020, 14:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * A filter program to remove comments from the input
 */

int filter( FILE *input, FILE *output )
{
    int emptylines = 0;
    char buffer[5000], *fp;

    fseek(input, 0L, SEEK_END); 
    const int size = ftell(input); 
    char* retcontent;
    retcontent = (char *)malloc(size * sizeof(int));
    char ch;

    fpos_t position;

    while ( !feof( input ) ) {
        if ( ferror( input ) ) {
            return 1;
        }
        // Do stuff here:
        ch = fgetc(input);
        fgetpos(input, &position);
        // Check for a slash
        if (ch == '/') {
          // Check the next character
          ch = fgetc(input);
          // If slash again
          if (ch == '/') {
            // Advance in the stream until a new line
            while ((ch = fgetc(input)) != '\n') ;
          } else {
            /*
             Return the slash to the stream if not a comment.
             Probably should be done using fseek to go backward
             in the stream, but could not make it work.
            */
            fputc('/', output);
          }
        }
        fputc(ch, output);
    }
    return 0;
}

int main(void)
{
    const int retval = filter( stdin, stdout );
    // Flush the output buffer and move the buffered data to console
    fflush( stdout );
    return retval;
}
