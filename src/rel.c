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
 * A filter program to remove empty lines from the input
 */

int filter( FILE *input, FILE *output )
{
    int emptylines = 0;
    char buffer[5000], *fp;

    fseek(input, 0L, SEEK_END); 
    const int size = ftell(input); 
    char* retcontent;
    retcontent = (char *)malloc(size * sizeof(int));
    
    while ( !feof( input ) ) {
        if ( ferror( input ) ) {
            return 1;
        }
        // Do stuff here:
        fgets(buffer, 5000, input);
        fp = buffer; 
        
        // Skip whitespace
        while (*fp == ' ' || *fp == '\t') fp++;
        if (*fp == '\r') fp++;
        if (*fp != '\n') {
          fputs(buffer, output);
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
