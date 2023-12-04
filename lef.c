#include "lef.h"

// Cria um evento contendo os parâmetros informados.
// Retorna um ponteiro para o evento
// ERRO -> retorna NULL se falhar.
evento *cria_evento (int tempo, int tipo, int dado1, int dado2) {

    evento *temp;

    // Aloca memoria, mas retorna NULL em caso de erro
    if ((temp = ((evento *) malloc(sizeof(evento)))) == NULL) {
        printf("ERRO! Não foi possível alocar memória no evento");
		return NULL;
    };

    temp->tempo = tempo;
    temp->tipo = tipo;
    temp->dado1 = dado1;
    temp->dado2 = dado2;

    return temp;
};

// Destroi um evento e retorna NULL.
evento *destruir_evento (evento *EVENTO) {
    free (EVENTO);
    return NULL;
};

// Inicializa a LEF
// Retorna um ponteiro
// ERRO -> Retorna NULL se falhar
lef *cria_lef (void) {

    lef *temp;

    // Aloca memoria, mas retorna NULL em caso de erro
    if ((temp = ((lef *) malloc(sizeof(lef)))) == NULL) {
        printf("ERRO! Não foi possível alocar memória na CABEÇA do LEF");
		return NULL;
    };

    temp->primeiro = NULL;

    return temp;

};

// Destroi a LEF
// Retorna NULL 
lef *destruir_lef (lef *LEF) {

    while (LEF->primeiro != NULL)
        free(retirar_lef(LEF));

    free(LEF->primeiro);
    free(LEF);
    return NULL;
}

// Inserir o evento no LEF em ordenacao do MENOR para o MAIOR
// Retorna 1 para ERRO e 0 para SUCESSO
int inserir_lef (lef *LEF, evento *EVENTO) {

    nodo_lef* nova;
    nodo_lef* temp;

    // Aloca espaco na lista
    if ((nova = (nodo_lef *) malloc (sizeof(nodo_lef))) == NULL) {
        printf("ERRO! Não foi possível alocar memória no NODO da LEF");
        return 1;
    };

    // Insere o EVENTO na nono NODO do LEF
    nova->info = EVENTO;

    // Caso de ele ser o MAIOR
    if (LEF->primeiro == NULL) {
        nova->prox = NULL;
        LEF->primeiro = nova;
        return 0;
    };

    // Achar o local e inserir ordenadamente
    for (temp = LEF->primeiro; temp != NULL; temp = temp->prox) {

        // Caso de o inserido ser o MENOR entre todos
        if (EVENTO->tempo < temp->info->tempo) {
            if (EVENTO->tempo < LEF->primeiro->info->tempo) {
                nova->prox = LEF->primeiro;
                LEF->primeiro = nova;
                return 0;
            };
        };

        // Caso de ser o MAIOR entre todos
        if (temp->prox == NULL) {
            nova->prox = temp->prox;
            temp->prox = nova;
            return 0;
        };

        // Caso padrao -> apenas insere ordenado
        if (EVENTO->tempo < temp->prox->info->tempo) {
            nova->prox = temp->prox;
            temp->prox = nova;
            return 0;
        };
        
    };

    return 0;
}

// Remove o primeiro evento na LEF
// Retorna o ponteiro do evento ou NULL para falha
evento *retirar_lef (lef *LEF) {

    evento *removido;
    nodo_lef *removivel;

    if (LEF->primeiro == NULL)
        return NULL;

    removivel = LEF->primeiro;
    LEF->primeiro = removivel->prox;
    removido = removivel->info;

    free (removivel);
    return removido;
};

// Verifica se a LEF esta vazia
// Retorna 1 para vazia, 0 para nao ou -1 para ERRO
int vazia_lef (lef *LEF) {

    if (LEF == NULL)
        return -1;

    if (LEF->primeiro == NULL)
        return 1;
    return 0;

};

// Imprime a LEF
// tempo | tipo | dado1 | dado2
void imprime_lef (lef *LEF) {

    nodo_lef *aux;
    printf("\n\e[1;37mTEMPO | TIPO | DADO1 | DADO2\e[0;37m");
    printf("\n------|------|-------|------\n");
    for (aux = (LEF->primeiro); aux != NULL; aux = aux->prox)
        printf("%5d |%5d |%6d |%6d\n", aux->info->tempo, aux->info->tipo, aux->info->dado1, aux->info->dado2);

};