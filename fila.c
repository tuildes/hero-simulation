#include "fila.h"

// Inicializar a fila com tamanho TAM
// Retorna 1 para ERRO
fila* inicializar_fila () {

    fila *aux;

    if ((aux = (fila *) malloc (sizeof(fila))) == NULL) {
        printf("ERRO! Não foi possível iniciar a FILA");
        return NULL;
    };

    aux->primeiro = NULL;
    aux->tamanho = 0;

    return aux;

};

// Destruir a fila
void destruir_fila (fila *FILA) {

    while (FILA->primeiro != NULL)
        remover_fila(FILA);

    free (FILA);
};

// Verificar se está vazia
// Retorna 1 para verdadeiro e 0 para falso
int fila_vazia (fila FILA) {
    if (FILA.tamanho == 0)
        return 1;
    return 0;
};

// Inserir um elemento no fim da fila
// Retorna 1 para ERRO (não foi possivel inserir)
int inserir_fila (fila *FILA, int NUM) {

    nodo_fila* novo;
    nodo_fila* aux;

    // Aloca espaço para a nova celula
    if ((novo = (nodo_fila *) malloc (sizeof(nodo_fila))) == NULL) {
        printf("ERRO! Não foi possível alocar espaço para INSERIR (FILA)");
        return 1;
    };

    // Cria os campos necessários e aumenta o tamanho
    FILA->tamanho++;
    novo->id = NUM;
    novo->prox = NULL;

    // Caso 1 - SE FOR O PRIMEIRO COLOCADO NA FILA
    if (FILA->primeiro == NULL) {
        FILA->primeiro = novo;
        return 0;
    };

    for (aux = FILA->primeiro; aux->prox != NULL; aux = aux->prox);
    aux->prox = novo;

    return 0;
};

// Remover um elemento (primeiro da fila)
// Retorna o removido
// Se não for possivel remover, retorna 0
int remover_fila (fila *FILA) {

    if (fila_vazia(*FILA))
        return 0;

    nodo_fila *removivel;
    int num_removido;

    // Remove o proximo elemento
    removivel = FILA->primeiro;
    num_removido = removivel->id;
    FILA->primeiro = removivel->prox;

    // Libera espaço e retorna o removido
    free (removivel);
    FILA->tamanho--;
    return num_removido;
};

void imprimir_fila (fila *FILA) {

    nodo_fila* aux;

    if (fila_vazia(*FILA)) {
        printf("[ ]");
        return;
    };
    printf("[ ");
    for (aux = FILA->primeiro; aux != NULL; aux = aux->prox)
        printf("%d ", aux->id);
    printf("]");

};