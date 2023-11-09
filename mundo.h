#include "principal.h"
#include "entidades.h"

/* Funções de manipulação do mundo de heróis */

// Funções com retorno de 0 para SUCCESS e 1 para ERROR
// Inicializam a sua respectiva entidade, um por vez
int inicializar_mundo(mundo *mundo_virtual);
int inicializar_heroi (heroi *heroi_virtual, mundo mundo_virtual, int id);
int inicializar_base (base *base_virtual, mundo mundo_virtual, int id);
int inicializar_missao (missao *missao_virtual, mundo mundo_virtual, int id);

// Inicializa tudo de uma vez
// Retorna 0 para SUCCESS e 1 para ERROR
int inicializar_realidade_virtual();

// Funções sem retorno que APENAS imprimem na tela
void imprimir_mundo(mundo mundo_virtual);
void imprimir_heroi(heroi heroi_virtual);
void imprimir_base(base base_virtual);
void imprimir_missao(missao missao_virtual);

// Função que executa 1 minuto no mundo
void clock_mundo(void);

// Função de finalizacao da realidade virtual
// Imprime todos os resultados e libera a memória
void finalizar_realidade_virtual(mundo mundo_virtual);