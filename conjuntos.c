#include "conjuntos.h"

/* TAD de LISTA */

    // Insere na lista
    int inserir_conjunto (conjunto *conj, int numero) {

        conjunto* nova;

        // Aloca espaco na lista
        if ((nova = (conjunto *) malloc (sizeof(conjunto))) == NULL) {
            printf("ERRO! Não foi possível alocar memória no conjunto");
            return 1;
        };

        // Inserir as infos na lista
        nova->num = numero;

        nova->prox = conj->prox;
        conj->prox = nova;

        return 0;
    };

    // Imprimir o conjunto
    void imprimir_conjunto (conjunto *conj) {
        conjunto *aux;

        // Para o CASO de conjunto vazio
        if (conj->prox == NULL) {
            printf("[ ]");
            return;
        };

        printf("[");

        // Imprime o primeiro sem virgula
        printf("\e[1;37m%d\e[0;37m", conj->prox->num);

        // Imprime o restante como ", NUM"
        for (aux = conj->prox->prox; aux != NULL; aux = aux->prox)
            printf(", \e[1;37m%d\e[0;37m", aux->num);

        printf("]");
    };

    // Deleta um valor da lista
    // Remove sempre o primeiro item do conjunto (ultimo colocado)
    // Retorna o removido
    int remover_conjunto (conjunto *conj) {
        conjunto *removivel;
        int num_removido;

        // Remove o proximo elemento
        removivel = conj->prox;
        num_removido = removivel->num;
        conj->prox = removivel->prox;

        // Libera espaço e retorna o removido
        free (removivel);
        return num_removido;
    }

    // Busca um item na lista e retorna o conjunto dele para frente
    conjunto* busca_conjunto (conjunto *conj, int dado) {

        conjunto *auxiliar;

        // Procura por todas as células
        for (auxiliar = conj->prox; auxiliar != NULL; auxiliar = auxiliar->prox) {
            if (auxiliar->num == dado)
                return auxiliar;
        }

        // Se não encontrar, vai retornar NULL
        return NULL;

    }

/* TAD de LISTA */
/* Relação de Conjuntos */

    // União entre dois conjuntos
    conjunto* uniao_conjunto (conjunto *A, conjunto *B) {

        conjunto *auxiliar;
        conjunto *C;

        C = NULL;
        if ((C = ((conjunto *) malloc(sizeof(conjunto)))) == NULL) {
            printf("ERRO! Não foi possível alocar memória na UNIAO em C");
		    return NULL;
        };

        // Adiciona totalmente A
        for (auxiliar = A->prox; auxiliar != NULL; auxiliar = auxiliar->prox)
            inserir_conjunto(C, auxiliar->num);

        // Adiciona B-A
        for (auxiliar = B->prox; auxiliar != NULL; auxiliar = auxiliar->prox)
            if ((busca_conjunto (A, (auxiliar->num))) == NULL)
                inserir_conjunto(C, auxiliar->num);

        return C;

    }

    // Intersecção entre dois conjuntos
    conjunto* interseccao_conjunto (conjunto *A, conjunto *B) {

        conjunto *auxiliar;
        conjunto *C;

        C = NULL;
        if ((C = ((conjunto *) malloc(sizeof(conjunto)))) == NULL) {
            printf("ERRO! Não foi possível alocar memória na INTERSECCAO em C");
		    return NULL;
        };

        // Criacao da interseccao de A por B
        for (auxiliar = B->prox; auxiliar != NULL; auxiliar = auxiliar->prox)
            if ((busca_conjunto (A, (auxiliar->num))) != NULL)
                inserir_conjunto(C, auxiliar->num);

        return C;
    }

    // Pertence - verifica se existe um numero no conjunto
    // Retorna 1 para verdadeiro e 0 para falso
    int pertence_conjunto (int NUM, conjunto *A) {

        if ((busca_conjunto (A, NUM)) != NULL)
            return 1;
        return 0;
    }

    // Contém entre conjunto A em conjunto B
    // Retorna 1 para verdadeiro e 0 para falso
    int contem_conjunto (conjunto *A, conjunto *B) {

        conjunto* auxiliar;

        for (auxiliar = A->prox; auxiliar != NULL; auxiliar = auxiliar->prox)
            if (pertence_conjunto(auxiliar->num, B) == 0)
                return 0;
        return 1;
    }

/* TAD de LISTA */