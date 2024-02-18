#ifndef MERGE_H
#define MERGE_H

#define NAME_LEN 20

struct Prod{
    int id;
    char name[NAME_LEN + 1];
    int qta;
};

/// @brief effettua l'unione di due file contenenti una serie di elementi di tipo struct Prod
/// @param inFilename1 nome del primo file
/// @param inFilename2 nome del secondo file
/// @param outFilename nome del nuovo file
/// @param resolve Funzione che descrive in che modo devono essere risolti i conflitti tra prodotti con lo stesso id
/// @return 0 se l'unione è andata a buon fine, altrimenti un valore diverso da 0
int mergeFile(
    const char *inFilename1, 
    const char *inFilename2, 
    const char *outFilename, 
    struct Prod *(*resolve)(const struct Prod *obj1, const struct Prod *obj2)
);

#endif