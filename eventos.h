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
// Retorna se ESPERA (1) ou DESISTE (0)
int evento_chega (int INSTANTE, heroi* HEROI, base BASE, lef* LEF); 

// Representa um HEROI que aceitou ESPERAR na FILA da BASE
// Termina AVISANDO o porteiro da BASE
void evento_espera (int INSTANTE, heroi HEROI, base* BASE, lef* LEF);

// Representa um HEROI que DESISTIU de entrar na BASE
// Termina VIAJANDO para outra BASE
void evento_desiste (int INSTANTE, heroi HEROI, base BASE, lef* LEF, mundo MUNDO);

// Representa que o PORTEIRO tratou a FILA de ESPERA da BASE
// Termina entrando HEROIS ou NADA
void evento_avisa (int INSTANTE, base* BASE, lef* LEF, mundo* MUNDO);

// Representa um HEROI que ENTROU na BASE
// Calcula o tempo de estadia e termina em SAIDA
// Retorna TEMPO DE ESTADIA
int evento_entra (int INSTANTE, heroi HEROI, base BASE, lef* LEF);

// Representa um HEROI que SAI da BASE
void evento_sai (int INSTANTE, heroi HEROI, base* BASE, lef* LEF, mundo MUNDO);

// Representa um HEROI que VIAJA para BASE
// Retorna DISTANCIA
double evento_viaja (int INSTANTE, heroi* HEROI, base* BASE, lef* LEF, mundo MUNDO);

// Representa uma MISSAO no MUNDO
// Retorna COMPLETADA (1) ou ADIADA (0)
int evento_missao (int INSTANTE, missao MISSAO, lef* LEF, mundo MUNDO);

// Representa o FIM do MUNDO
// Encerra a simulação e dá os resultados
void evento_fim (int INSTANTE, mundo MUNDO, int TENTATIVA, int CONCLUIDAS);

/* Funções de Eventos */