#include <string.h>
#include <stdio.h>
#include "libsearch.h"

/*
Working inputs
./exercise5 text.txt tendency
./exercise5 text.txt surroundings

Non-working inputs (but the words are there in the text)
./exercise5 text.txt something  
./exercise5 text.txt clever
./exercise5 text.txt wobbly


Algorithm Pseudocode

    for i in 0..text_length:  // <-- outer loop, in source code
        ___________________________________________________________________
        |// inner loop, not in source code                                |
        |var s = i;                                                       |
        |for j in 0..pattern_lenght:                                      |
        |    if j == pattern_lenght-1:                                    |
        |        <first occurance of pattern found at index i, return i>  |
        |    else if text[s] != pattern[j]                                |
        |        break;                                                   |
        |    else                                                         |
        |        s++;                                                     |     
        ___________________________________________________________________
            
*/


int main(int argc, char** argv){
    if(argc != 3){
        printf("The program should have 2 additional arguments: "
               "a filename for the text and the pattern to look for.\n");
        return 1;
    }

    char* filename = argv[1];
    char* pattern = argv[2];
    FILE* file = fopen(filename, "r");

    if(file != NULL){
        char text[2048];
        if(fgets(text, sizeof(text), file) != NULL){
            
            int text_lenth = strlen(text);
            int pattern_lenght = strlen(pattern);

            int index;
            for(int i = 0; i < text_lenth; i++){ // <-- outer loop
                index = inner_loop(i, text, pattern, pattern_lenght);
                if(index != -1) break;
            }

            if(index != -1)
                printf("First occurance found at index %d.\n", index);
            else 
                printf("Pattern is not found in text.\n");
            

        } else 
            printf("Could not read from file.\n");

        fclose(file);
    } else 
        printf("Could not open file.\n");
    
    return 0;     
}