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
 * A filter program to remove trailing whitespace
 */

int filter( FILE *input, FILE *output )
{
    int emptylines = 0;
    char buffer[5000], temp[5000], *fp;

    while ( !feof( input ) ) {
        if ( ferror( input ) ) {
            return 1;
        }
        // Do stuff here:
        fgets(buffer, 5000, input);
        fp = buffer;
        
        char *end;

        end = buffer + (strlen(buffer) - 1);

        int count = 0;

        while (end > buffer && isspace(*end)) {
          end--;
          count++;
        }
        if (count > 1) {
          *(end + 1) = '\n';
          *(end + 2) = '\r';
          *(end + 3) = '\0';
        }
        
        fputs(buffer, output);

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
