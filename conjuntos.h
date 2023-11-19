#include "principal.h"

/* TAD de LISTA */
typedef struct listaEncadeada conjunto;
struct listaEncadeada {
    int num;
    conjunto *prox;
};

/* Manipulação de conjuntos */

    // Insere na lista
    // Retorna 1 em caso de erro
    int inserir_conjunto (conjunto *conj, int numero);

    // Deleta um valor da lista
    // Remove sempre o primeiro item do conjunto (ultimo colocado)
    // Retorna o removido
    int remover_conjunto (conjunto *conj);

    // Busca um item na lista e retorna o conjunto dele para frente
    conjunto* busca_conjunto (conjunto *conj, int dado);

    // Imprimir o conjunto: [1, 2, 3, ..., n]
    void imprimir_conjunto (conjunto *conj);

/* Manipulação de conjuntos */
/* Relação de conjuntos e elementos */

    // União entre dois conjuntos
    conjunto* uniao_conjunto (conjunto *A, conjunto *B);

    // Intersecção entre dois conjuntos
    conjunto* interseccao_conjunto (conjunto *A, conjunto *B);

    // Pertence - verifica se existe um numero no conjunto
    // Retorna 1 para verdadeiro e 0 para falso
    int pertence_conjunto (int NUM, conjunto *A);

    // Contém entre conjunto A em conjunto B (Se A está totalmente em B)
    // Retorna 1 para verdadeiro e 0 para falso
    int contem_conjunto (conjunto *A, conjunto *B);

/* Relação de conjuntos e elementos */