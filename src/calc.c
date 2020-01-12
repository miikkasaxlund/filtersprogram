/* 
 * File:   calc.c
 * Author: Miikka Saxlund
 *
 * Created on 03 January 2020, 14:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
 * 
 */
int filter( FILE *input, FILE *output )
{
    int lines = 0;
    int chars = 0;
    int spaces = 0;
    
    while ( !feof( input ) ) {
        if ( ferror( input ) ) {
            return 1;
        }
        // Do stuff here:
        //fputc(fgetc( input ), output);

        int ch = fgetc(input);
        if (ch == '\n') {
            lines++;
        } else if (isspace(ch)) {
            spaces++;
            chars++;
        } else {
            chars++;
        }

    }
    char retcontent[1000];
    sprintf(retcontent, "LOC=%d\nCHARS=%d\nSPACES=%d", lines, chars, spaces);
    fputs(retcontent, output);
    return 0;
}

int main(void)
{
    const int retval = filter( stdin, stdout );
    // Flush the output buffer and move the buffered data to console
    fflush( stdout );
    return retval;
}