Francesco Ferrante 10/02/2024

compress.c   : Comprime un file utilizzando la tecnica run-length encoding, sostituendo i byte con una coppia contatore+byte (è utile con file con sequenze di byte identici)
uncompress.c : Scompatta un file rel, compresso precedentemente da compress.c