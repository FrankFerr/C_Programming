#include <stdio.h>
#include <string.h>
#include "..\include\word.h"
#include "..\include\line.h"

#define MAX_WORD_LEN 20

int main(void){

    char word[MAX_WORD_LEN + 2];
    int wordLen = 0;

    clearLine();
    for(;;){
        wordLen = readWord(word, MAX_WORD_LEN + 1);

        if(wordLen == 0){
            flushLine();
            break;
        }

        if(wordLen > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        
        if(wordLen + 1 > spaceRemaning()){
            writeLine();
            clearLine();
        }

        addWord(word);
    }

    return 0;
}