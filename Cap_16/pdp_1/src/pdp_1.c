#include <stdio.h>

#define LEN_COUNTRY (int) (sizeof countryCode / sizeof countryCode[0])

struct DialingCode{
    char* country;
    int prefix;
};

int main(void){
    printf("*** Mostra a quale nazione corrisponde il prefisso inserito ***\n\n");

    const struct DialingCode countryCode[] = {
        {"Argentina",      54}, {"Bangladesh",    880}, {"Brazil",         55},
        {"China",          86}, {"Colombia",       57}, {"Egypt",          20},
        {"France",         33}, {"Germany",        49}, {"India",          91},
        {"Indonesia",      62}, {"Iran",           98}, {"Italy",          39},
        {"Japan",          81}, {"Mexico",         52}, {"Nigeria",       234},
        {"Poland",         48}, {"Russia",          7}, {"South Korea",    82},
        {"Spain",          34}, {"Turkey",         90}, {"Ukraine",       380},
        {"United Kingdom", 44}, {"United States",   1}, {"Vietnam",        84}
    };
    int code = 0;

    while(1){
        printf("Inserisci un prefisso (0 = esci): ");
        scanf("%d", &code);
        getchar();

        if(code == 0)
            break;

        for(int i = 0; i < LEN_COUNTRY; i++){
            if(countryCode[i].prefix == code){
                printf("Country: %s\n", countryCode[i].country);
                break;
            }
        }

        printf("\n");
    }



    printf("\n");
    return 0;
}