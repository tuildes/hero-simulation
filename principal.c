#include "principal.h"

/* Funções de manipulação principais do projeto */

// Retorna um aleatorio no intervalo [MIN..MAX]
int gerar_aleatorio (int min, int max) {
    return min + (rand() % (max - min + 1));
};