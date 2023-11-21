#include "principal.h"
#include "lef.h"
#include "entidades.h"

/*
    ---------------------------------------------------
     EVENTO  | TIPO (int) | DADO1 (int) | DADO2 (int)
    ---------------------------------------------------
     CHEGA   | 0          | ID HEROI    | ID BASE
     ESPERA  | 1          | ID HEROI    | ID BASE
     DESISTE | 2          | ID HEROI    | ID BASE
     AVISA   | 3          | ID BASE     | -
     ENTRA   | 4          | ID HEROI    | ID BASE
     SAI     | 5          | ID HEROI    | ID BASE
     VIAJA   | 6          | ID HEROI    | ID BASE
     MISSAO  | 7          | ID MISSAO   | -
     FIM     | 8          | -           | -
    --------------------------------------------------
*/

/* Funções de Eventos */

// Representa um HEROI chegando numa BASE em um TEMPO.
// Decide se vai FICAR na FILA ou DESISTIR
void evento_chega (int INSTANTE, heroi* HEROI, base BASE, lef* LEF); 

/* Funções de Eventos */