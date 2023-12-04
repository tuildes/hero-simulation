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

    // Busca e Remove um certo numero no conjunto
    // Retorna o removido
    // Retorna -1 em caso de erro
    int buscar_remover_conjunto (conjunto *conj, int NUM);

    // Retorna 1 se encontrado
    int search_conj (conjunto *conj, int dado);

    // Imprimir o conjunto: [1, 2, 3, ..., n]
    void imprimir_conjunto (conjunto *conj);

    // Destroi o conjunto
    void destruir_conjunto (conjunto *conj);

    // Inicializar o conjunto
    conjunto* inicializar_conjunto ();

/* Manipulação de conjuntos */
/* Relação de conjuntos e elementos */

    // União entre dois conjuntos
    // Faz a UNIAO de A e B em C
    void uniao_conjunto (conjunto *A, conjunto *B, conjunto *C);

    // Intersecção entre dois conjuntos
    // Retorna a Intersecao
    conjunto* interseccao_conjunto (conjunto *A, conjunto *B);

    // Pertence - verifica se existe um numero no conjunto
    // Retorna 1 para verdadeiro e 0 para falso
    int pertence_conjunto (int NUM, conjunto *A);

    // Contém entre conjunto A em conjunto B (Se A está totalmente em B)
    // Retorna 1 para verdadeiro e 0 para falso
    int contem_conjunto (conjunto *A, conjunto *B);

/* Relação de conjuntos e elementos */