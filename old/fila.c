#include "principal.h"
#include "fila.h"

/* Funções de manipulação de fila */

// Verifica se a fila esta vazia
// Retorna 1 para verdadeiro e 0 para falso
int filaVazia(struct fila p) {
    if ((p.inicio % TAMANHO_FILA) == (p.final % TAMANHO_FILA))
        return 1;
    
    return 0;
};

// Verifica se a fila esta cheia
// Retorna 1 para verdadeiro e 0 para falso
int filaCheia(struct fila p) {
    if ((p.inicio % TAMANHO_FILA) == ((p.final+1) % TAMANHO_FILA))
        return 1;
    return 0;
}

// Insere na fila, MAS NÃO verifica se a fila esta cheia, deve ser verificado antes do chamado
void inserirFila (struct fila *p, int n) {
    
    (*p).fila[((*p).final % TAMANHO_FILA)] = n;
    (*p).final++;

};

// Remove o primeiro da fila, MAS NÃO verifica se a fila esta vazia, deve ser verificado antes do chamado
// Remoção por substituição, ou seja, apenas permite sobreescrever o elemento da fila
int removerFila (struct fila *p) {
    (*p).inicio++;
    return (*p).fila[(*p).inicio-1];
};

// Retorna quem eh o primeiro na fila - proximo a ser removido
int inicioFila (struct fila p) {
    return p.fila[(p.inicio % TAMANHO_FILA)];
};