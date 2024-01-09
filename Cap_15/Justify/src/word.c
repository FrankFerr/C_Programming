#include <stdio.h>
#include "..\include\word.h"

int readChar(void){
    int ch = getchar();

    return (ch == '\n' || ch == '\t') ? ' ' : ch;
}

int readWord(char* word, int len){
    int ch, pos = 0;

    while((ch = readChar()) == ' ')
        ;
    
    while(ch != ' ' && ch != EOF){
        if(pos < len)
            word[pos++] = ch;
        
        ch = readChar();
    }
    
    word[pos] = '\0';
    
    return pos;
}