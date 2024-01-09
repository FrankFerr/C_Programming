#include <stdio.h>
#include <string.h>
#include "..\include\line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int lineLen = 0, numWords = 0;

void clearLine(void){
    line[0] = '\0';
    lineLen = 0;
    numWords = 0;
}

void addWord(const char* word){
    if(numWords > 0){
        line[lineLen] = ' ';
        line[lineLen + 1] = '\0';
        lineLen++;
    }
    strcat(line, word);
    lineLen += strlen(word);
    numWords++;
}

int spaceRemaning(void){
    return MAX_LINE_LEN - lineLen;
}

void writeLine(void){
    int extraSpaces, spaceToInsert, i, j;

    extraSpaces = MAX_LINE_LEN - lineLen;
    for(i = 0; i < lineLen; i++){
        if(line[i] != ' ')
            putchar(line[i]);
        else{
            spaceToInsert = extraSpaces / (numWords - 1);
            
            for(j = 0; j < spaceToInsert + 1; j++)
                putchar(' ');

            extraSpaces -= spaceToInsert;
            numWords--;
        }
    }
    putchar('\n');
}

void flushLine(void){
    if(lineLen > 0)
        puts(line);
}