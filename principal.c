#include "principal.h"

/* Funções de manipulação principais do projeto */

// Retorna um aleatorio no intervalo [MIN..MAX]
int gerar_aleatorio (int min, int max) {
    return ( min + (rand() % (max - min + 1)) );
};

double distancia_pontos (int A, int B, int X, int Y) {

    double x = ((X-A) * 1.0);
    double y = ((Y-B) * 1.0);

    return sqrt (((x*x) + (y*y)));

};

float media (int A, int B) {

    if (B == 0)
        return 0;
    return ((A*1.0) / (B*1.0));

};