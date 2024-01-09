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

void writeLine(void){
    int extraSpaces, spaceToInsert, i, j;
}

int spaceRemaning(void){
    return MAX_LINE_LEN - lineLen;
}

void flushLine(void){
    if(lineLen > 0)
        puts(line);
}