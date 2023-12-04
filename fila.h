#include "principal.h"

// Células da FILA
typedef struct objeto_nodo_fila nodo_fila;
struct objeto_nodo_fila {
    int id;
    nodo_fila *prox;
};

// Cabeça da FILA
typedef struct objeto_fila fila;
struct objeto_fila {
    nodo_fila *primeiro;
    int tamanho;
};

// Inicializar a fila com tamanho TAM
// Retorna 1 para ERRO
fila* inicializar_fila ();

// Destruir a fila
void destruir_fila (fila *FILA);

// Verificar se está vazia
// Retorna 1 para verdadeiro e 0 para falso
int fila_vazia (fila FILA);

// Inserir um elemento no fim da fila
// Retorna 1 para ERRO (não foi possivel inserir)
int inserir_fila (fila *FILA, int NUM);

// Remover um elemento (primeiro da fila)
// Retorna o removido
// Se não for possivel remover, retorna 0
int remover_fila (fila *FILA);

// Imprime o conteudo da fila [ a b c d e f g .. n]
void imprimir_fila (fila *FILA);