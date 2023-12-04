#ifndef _MUNDO_H
#define _MUNDO_H

#include "entidades.h"
#include "lef.h"
#include "eventos.h"

// Função que chama todas as outras
// Usada para inicializar TODO o mundo virtual -> herois, mundo, missao, etc...
// Retorna 1 para caso de erro ou 0 para sucesso
int inicializar_realidade_virtual(mundo *mundo_virtual, lef *eventos_mundo);

// Função de finalizacao da realidade virtual
// Libera a memória
void finalizar_realidade_virtual(mundo *mundo_virtual, lef *eventos_futuros);

#endif