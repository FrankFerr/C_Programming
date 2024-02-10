#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int countChar(const char* filename);
int countWord(const char* filename);
int countLine(const char* filename);

int main(int argc, char **argv){

    if(argc != 2){
        printf("Lanciare: canopen <filename>\n");
        exit(EXIT_FAILURE);
    }

    int numChar = 0, numWord = 0, numLine = 0;

    numChar = countChar(argv[1]);
    printf("Totale caratteri: %d\n", numChar);
    
    numWord = countWord(argv[1]);
    printf("Totale parole: %d\n", numWord);

    numLine = countLine(argv[1]);
    printf("Totale righe: %d\n", numLine);


    return 0;
}

int countChar(const char* filename){
    int count = 0;

    FILE *fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Impossibile aprire %s", filename);
        exit(EXIT_FAILURE);
    }

    while(fgetc(fp) != EOF)
        count++;

    fclose(fp);

    return count;
}

int countWord(const char* filename){
    int count = 0, ch;
    FILE *fp = fopen(filename, "r");
    bool newWord = true;

    if(fp == NULL){
        printf("Impossibile aprire %s", filename);
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF){
        if(isalpha(ch)){
            if(newWord){
                count++;
                newWord = false;
            }
        } else {
            newWord = true;
        }
    }

    fclose(fp);

    return count;
}

int countLine(const char* filename){
    int count = 0;
    FILE *fp = fopen(filename, "r");
    char s[200 + 1];

    if(fp == NULL){
        printf("Impossibile aprire %s", filename);
        exit(EXIT_FAILURE);
    }

    while(fgets(s, 200, fp) != NULL)
        if(s[strlen(s) - 1] == '\n')
            count++;

    fclose(fp);

    return count;
}