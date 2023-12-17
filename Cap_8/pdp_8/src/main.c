#include <stdio.h>
#include <stdbool.h>

#define LEN_STUDENTI 2
#define LEN_TEST 4
#define MAX_VOTO 10
#define MIN_VOTO 1

int main(void){

    printf("*** Inseriti i punteggi di n test per n studenti ne calcola: punteggio totale e medio per studente e punteggio medio, massimo e minimo di tutti ***\n\n");

    int studentiVoti[LEN_STUDENTI][LEN_TEST] = {0}, 
        totXStud[LEN_STUDENTI] = {0}, 
        totXTest[LEN_TEST] = {0},
        maxXTest[LEN_TEST] = {0},
        minXTest[LEN_TEST] = {0};
    float media = 0.0;
    
    for(int i = 0; i < LEN_TEST; i++)
        minXTest[i] = MAX_VOTO + 1;

    for(int stud = 0; stud < LEN_STUDENTI; stud++){
        printf("Inserisci i %d voti dello studente %d (0 per uscire dal programma)\n", LEN_TEST, stud+1);
        
        for(int test = 0; test < LEN_TEST; test++){
            printf("> ");
            do{
                scanf("%d", &studentiVoti[stud][test]);

                if(studentiVoti[stud][test] == 0)
                    return 0;
            }while(studentiVoti[stud][test] < MIN_VOTO || MAX_VOTO < studentiVoti[stud][test]);

            totXStud[stud] += studentiVoti[stud][test];
            totXTest[test] += studentiVoti[stud][test];

            if(maxXTest[test] < studentiVoti[stud][test]){
                maxXTest[test] = studentiVoti[stud][test];
            }

            if(minXTest[test] > studentiVoti[stud][test]){
                minXTest[test] = studentiVoti[stud][test];
            }
        }
    }

    printf("\n\nStudenti    ");
    for(int test = 0; test < LEN_TEST; test++){
        printf("T%-6d", test+1);
    }
    printf(" Totale     Media\n");

    for(int stud = 0; stud < LEN_STUDENTI; stud++){
        printf("S%-3d   ", stud+1);
        
        for(int test = 0; test < LEN_TEST; test++){
            printf("%7d", studentiVoti[stud][test]);
        }

        media = (float) totXStud[stud] / LEN_TEST;
        printf("%10d%12.2f\n", totXStud[stud], media);
    }

    printf("\n");
    printf("Max    ");
    for(int test = 0; test < LEN_TEST; test++){
        printf("%7d", maxXTest[test]);
    }

    printf("\n");
    printf("Min    ");
    for(int test = 0; test < LEN_TEST; test++){
        printf("%7d", minXTest[test]);
    }

    printf("\n");
    printf("Media    ");
    for(int test = 0; test < LEN_TEST; test++){
        media = (float) totXTest[test] / LEN_STUDENTI;
        printf("%7.2f", media);
    }

    printf("\n");
    return 0;
}