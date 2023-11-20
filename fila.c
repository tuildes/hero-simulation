#include "fila.h"

// Inicializar a fila com tamanho TAM
// Retorna 1 para estado de ERRO
int inicializar_fila (fila *FILA, int TAM) {
    (*FILA).tamanho = (TAM + 1);
    (*FILA).inicio = 0;
    (*FILA).fim = 0;
    
    // Alocação da memória do tamanho da fila
    if (((*FILA).elementos = (int *) malloc (TAM * (sizeof(int)))) == NULL) {
        printf("ERRO! Não foi possível alocar memória na FILA");
        return 1;
    };
    return 0;
}

// Destruir a fila
void destruir_fila (fila *FILA) {
    (*FILA).tamanho = 0;
    (*FILA).inicio = 0;
    (*FILA).fim = 0;
    free((*FILA).elementos);
};

// Verificar se está cheia
// Retorna 1 para verdadeiro e 0 para falso
int fila_cheia (fila FILA) {

    if ((FILA.inicio % FILA.tamanho) == ((FILA.fim + 1) % FILA.tamanho))
        return 1;
    return 0;

}

// Verificar se está vazia
// Retorna 1 para verdadeiro e 0 para falso
int fila_vazia (fila FILA) {

    if ((FILA.inicio % FILA.tamanho) == (FILA.fim % FILA.tamanho))
        return 1;
    return 0;

}

// Inserir um elemento no fim da fila
// Retorna 1 para ERRO (não foi possivel inserir)
int inserir_fila (fila *FILA, int NUM) {

    if (fila_cheia((*FILA)))
        return 1;

    (*FILA).elementos[((*FILA).fim % (*FILA).tamanho)] = NUM;
    (*FILA).fim++;
    return 0;
}

// Remover um elemento (primeiro da fila)
// Retorna o removido
// Se não for possivel remover, retorna 0
int remover_fila (fila *FILA) {

    if (fila_vazia ((*FILA))) {
        return 0;
    }

    (*FILA).inicio++;
    return (*FILA).elementos[((*FILA).inicio - 1) % (*FILA).tamanho];
}

// Retorna o primeiro elemento da fila
int inicio_fila (fila FILA) {
    return FILA.elementos[(FILA.inicio % FILA.tamanho)];
}