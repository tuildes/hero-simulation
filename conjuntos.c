#include "conjuntos.h"

/* TAD de LISTA */

    void destruir_conjunto (conjunto *conj) {
        while (conj->prox != NULL)
            remover_conjunto(conj);
        free (conj);
    };

    conjunto* inicializar_conjunto () {
        
        conjunto *temp;
        if ((temp = (conjunto *) malloc (sizeof(conjunto))) == NULL) {
            free (temp);
            return NULL;
        };

        // Valores padrões
        temp->prox = NULL;
        temp->num = 0;
        
        return temp;
    };

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
        int temp[50];
        int i = 0;
        int max;
        int j;
        int temp2;

        // Para o CASO de conjunto vazio
        if (conj->prox == NULL) {
            printf("[ ]");
            return;
        };

        // Insere todos os elementos do conjunto num ARRAY
        for (aux = conj->prox; aux != NULL; aux = aux->prox) {
            temp[i] = aux->num;
            i++;
        };

        // Troca REPETIDOS por -1
        max = i;
        for (i=0; i<max; i++) {
            for (j=(i+1); j<max; j++) {
                if (temp[j] == temp[i])
                    temp[j] = -1;
            };
        };

        // Insertion Sort
        for (i=1; i<max; i++) {

            j=i;
            while ((j != 0) && (temp[j] < temp[j-1])) {
                temp2 = temp[j-1];
                temp[j-1] = temp[j];
                temp[j] = temp2;
                j--;
            };
        };

        // Imprime o restante como "NUM, "
        printf("[");
        for (i=0; i<max; i++) {
            if (temp[i] != (-1))
                printf(" %d", temp[i]);
        };
        
        printf(" ]");

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

    // Busca e Remove um certo numero no conjunto
    // Retorna o removido
    // Retorna 0 em caso de NAO EXISTIR
    int buscar_remover_conjunto (conjunto *conj, int NUM) {

        conjunto *auxiliar;

        if (conj->prox->num == NUM)
            return remover_conjunto (conj);

        if ((auxiliar = busca_conjunto (conj, NUM)) == NULL)
            return -1;

        return remover_conjunto (auxiliar);

    };

    // Mesma funcao a baixo mas retorna 1 ou 0
    int search_conj (conjunto *conj, int dado) {

        conjunto *auxiliar;

        // Caso Base - conjunto VAZIO
        if (conj->prox == NULL)
            return 0;

        for (auxiliar = conj->prox; auxiliar != NULL; auxiliar = auxiliar->prox) {
            if (auxiliar->num == dado)
                return 1;
        };

        // Se não encontrar, vai retornar NULL
        return 0;

    };

    // Busca um item na lista e retorna o conjunto dele para frente
    conjunto* busca_conjunto (conjunto *conj, int dado) {

        conjunto *auxiliar;

        // Caso Base - conjunto VAZIO
        if (conj->prox == NULL)
            return NULL;

        for (auxiliar = conj->prox; auxiliar->prox != NULL; auxiliar = auxiliar->prox) {
            if (auxiliar->prox->num == dado)
                return auxiliar;
        };

        // Se não encontrar, vai retornar NULL
        return NULL;

    }

/* TAD de LISTA */
/* Relação de Conjuntos */

    // União entre dois conjuntos
    void uniao_conjunto (conjunto *A, conjunto *B, conjunto *C) {

        conjunto *auxiliar;

        // Adiciona totalmente A
        for (auxiliar = A->prox; auxiliar != NULL; auxiliar = auxiliar->prox)
            inserir_conjunto(C, auxiliar->num);

        // Adiciona B-A
        for (auxiliar = B->prox; auxiliar != NULL; auxiliar = auxiliar->prox)
            if (search_conj(A, B->num))
                inserir_conjunto(C, auxiliar->num);
    };

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