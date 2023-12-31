#include <stdio.h>
#include <string.h>

#define CUBE(x) ((x) * (x) * (x))
#define DIV_BY_4(n) ((n) % 4)
#define PROD_100(x, y) (((x)*(y)) < 100.0f ? 1 : 0)
#define NELEMS(a) (int) (sizeof a / sizeof a[0])
#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

#define GENERIC_MAX(type)        \
type type##_max(type x, type y){ \
    return x > y ? x : y;        \
}                                \

GENERIC_MAX(long);

typedef unsigned long U_LONG;
GENERIC_MAX(U_LONG);

#define GET_LINE(line) #line
#define LINE(line) GET_LINE(line)
#define LINE_FILE "Line " LINE(__LINE__) " of file " __FILE__

#define ERROR(formatStr, ...) fprintf(stderr, formatStr, __VA_ARGS__)

#define SPANISH 1

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

int main(void){
    printf("max int: %d\n", __INT_MAX__);
    printf("max long: %ld\n", __LONG_MAX__);
    printf("max long long unsigned: %llu\n", __UINT64_MAX__);

    printf("\n");
    // ---------------------------------------------->
    printf("CUBE %d: %d\n", 5, CUBE(5));
    printf("DIV_BY_4 %d: %d\n", 5, DIV_BY_4(86));

    int a = 60, b = 10;
    if(PROD_100(a, b)){
        printf("PROD_100(%d, %d): true\n", a, b);
    } else {
        printf("PROD_100(%d, %d): false\n", a, b);
    }
    // <----------------------------------------------

    printf("\n");
    // ---------------------------------------------->
    float arr[20] = {.0f};
    printf("NELEMS(arr): %d\n", NELEMS(arr));
    // <----------------------------------------------

    printf("\n");
    // ---------------------------------------------->
    char s[5] = "abcd";
    int i = 0;
    printf("s = %s, i = %d, TOUPPER(s[++i]): %c\n", s, i, TOUPPER(s[++i])); // -> ('a' <= (s[++i]) && (s[++i]) <= 'z' ? (s[++i]) - 'a' + 'A' : (s[++i])) la i viene incrementata 3 volte
    
    strcpy(s, "0123");
    i = 0;
    printf("s = %s, i = %d, TOUPPER(s[++i]): %c\n", s, i, TOUPPER(s[++i])); // -> qui solo 2 volte
    // <----------------------------------------------

    printf("\n");
    // ---------------------------------------------->
    long l1 = 5436547, l2 = 1234233;
    printf("long_max(%ld, %ld): %ld\n", l1, l2, long_max(l1, l2));

    U_LONG ul1 = 2000000000, ul2 = 3000000000;
    printf("U_LONG_max(%lu, %lu): %lu\n", ul1, ul2, U_LONG_max(ul1, ul2));    
    // <----------------------------------------------

    printf("\n");
    // ---------------------------------------------->
    const char* str = LINE_FILE;
    printf("const char* str = LINE_FILE -> %s\n", str);
    // <----------------------------------------------
    
    printf("\n");
    // ---------------------------------------------->
    ERROR("Range error: index = %d\n", 10);
    // <----------------------------------------------
    
    printf("\n");
    // ---------------------------------------------->
#ifdef ENGLISH
    printf("Insert Disk 1\n");
#elif defined FRENCH
    printf("Inserez Le Disque 1\n");
#elif defined SPANISH
    printf("Inserte El Disco 1\n");
#endif
    // <----------------------------------------------


    printf("\n");
    return 0;
}