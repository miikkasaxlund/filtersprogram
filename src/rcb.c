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
#include <stdbool.h>

/*
 * A filter program to remove comment blocks from the input
 */

int filter( FILE *input, FILE *output )
{
    char buffer[5000], *fp, ch, prevch;
    bool endFound = false;

    while ( !feof( input ) ) {
        if ( ferror( input ) ) {
            return 1;
        }
        // Do stuff here:
        ch = fgetc(input);
        prevch = ch;
        //nextch = fgetc(input);

        // Check for a slash
        if (ch == '/') {
          ch = fgetc(input);
          if (ch == '*') {
            while (!endFound) {
              ch = fgetc(input);
              if (ch == '*') {
                ch = fgetc(input);
                if (ch == '/') {
                  endFound = true;
                  do {
                    ch = fgetc(input);
                  } while (ch != '\n');
                  ch = fgetc(input);
                }
              } else if (ch == '\0') {
                endFound = true;
                do {
                  ch = fgetc(input);
                } while (ch != '\n');
                ch = fgetc(input);
              }
            }
          }
          else {
            fputc(prevch, output);
          }
        } 
        if (!feof( input )) {
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
