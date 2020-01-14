/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rws.c
 * Author: miikk
 *
 * Created on 03 January 2020, 14:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * A filter program to remove whitespace
 */

int filter( FILE *input, FILE *output )
{
    char ch;
    while ( !feof( input ) ) {
        if ( ferror( input ) ) {
            return 1;
        }
        // Do stuff here:
        ch = fgetc(input);
        // Check for a whitespace
        if (!isspace(ch) && !feof( input )) {
          fputc(ch, output);
        }
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
