#include <stdio.h>
#include <ctype.h>
#include "..\include\readline.h"

int readLine(char str[], int len){
    int pos = 0, ch;

    while(isspace(ch = getchar()))
        ;

    while(ch != '\n' && ch != EOF){
        if(pos < len)
            str[pos++] = ch;
        
        ch = getchar();
    }
    
    str[pos] = '\0';

    return pos;
}