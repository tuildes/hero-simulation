#include "principal.h"

/* TAD de FILA */
typedef struct fila_circular fila;
struct fila_circular {
    int tamanho;
    int inicio;
    int fim;
    int *elementos;
};

// Inicializar a fila com tamanho TAM
// Retorna 1 para ERRO
int inicializar_fila (fila *FILA, int TAM);

// Destruir a fila
void destruir_fila (fila *FILA);

// Verificar se está cheia
// Retorna 1 para verdadeiro e 0 para falso
int fila_cheia (fila FILA);

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

// Retorna o primeiro elemento da fila
int inicio_fila (fila FILA);