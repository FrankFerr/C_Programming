Francesco Ferrante 19/11/2023

Crea un percorso casuale di lettere A-Z in una matrice 10x10.
La direzione da prendere è casuale e il percorso termina se si arriva alla lettera Z o nessuna direzione è disponibile

direzioni: 
    0 -> su, 
    1 -> destra, 
    2 -> giù, 
    3 -> sinistra

esempio percorso completo:
    A    D    E    F    G    H    I    J    K    L
    B    C    .    .    .    .    .    .    .    M
    .    .    .    .    .    .    .    .    O    N
    .    .    .    .    .    .    .    .    P    Q
    .    .    .    .    .    .    .    .    .    R
    .    .    .    .    .    .    .    .    .    S
    .    .    .    .    .    .    .    .    .    T
    .    .    .    .    .    .    .    .    .    U
    .    .    .    .    .    .    .    .    .    V
    .    .    .    .    .    .    Z    Y    X    W

esempio percorso interrotto:
    A    B    C    D    E    F    G    .    O    P
    .    .    .    .    .    .    H    I    N    M
    .    .    .    .    .    .    .    J    K    L
    .    .    .    .    .    .    .    .    .    .
    .    .    .    .    .    .    .    .    .    .
    .    .    .    .    .    .    .    .    .    .
    .    .    .    .    .    .    .    .    .    .
    .    .    .    .    .    .    .    .    .    .
    .    .    .    .    .    .    .    .    .    .
    .    .    .    .    .    .    .    .    .    .