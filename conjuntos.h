#include "principal.h"

/* TAD de LISTA */
typedef struct listaEncadeada conjunto;
struct listaEncadeada {
    int num;
    conjunto *prox;
};

// Manipulação de conjuntos
int inserir_conjunto (conjunto *conj, int numero);
void imprimir_conjunto (conjunto *conj);
int remover_conjunto (conjunto *conj);
conjunto* busca_conjunto (conjunto *conj, int dado);

// Relação de conjuntos e elementos
conjunto* uniao_conjunto (conjunto *A, conjunto *B);
conjunto* interseccao_conjunto (conjunto *A, conjunto *B);
int pertence_conjunto (int NUM, conjunto *A);
int contem_conjunto (conjunto *A, conjunto *B);