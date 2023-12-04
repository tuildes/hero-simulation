#include "entidades.h"

/* Funções de manipulação do mundo de heróis */

// Inicializa todas as variaveis do mundo
// Retorna 1 para estado de erro - NAO FOI POSSIVEL INICIAR O MUNDO
int inicializar_mundo(mundo *mundo_virtual) {

    // Inicializa o tempo final
    // Tempo maximo = 525000 (365 dias)
    (*mundo_virtual).tempo_max = tempo_maximo;

    // Incializa o tamanho do mundo
    (*mundo_virtual).tamanho_mundo.x = tamanho_maximo;
    (*mundo_virtual).tamanho_mundo.y = tamanho_maximo;

    // Incializa o numero de habilidades
    // Numero de habilidades = 10
    (*mundo_virtual).num_habilidades = max_habilidades;

    // Inicializa o numero de herois
    // Numero de habilidades * 5
    (*mundo_virtual).num_herois = ((*mundo_virtual).num_habilidades * 5);

    // Inicializa o numero de bases
    // Numero de herois / 6 (teto)
    (*mundo_virtual).num_bases = ((*mundo_virtual).num_herois / 6);

    // Inicializa o numero de missoes
    // Numero de missoes = Tempo_max / 100
    (*mundo_virtual).num_missoes = ((*mundo_virtual).tempo_max / 100);

    /* HEROIS */

    // Alocar memoria para o ARRAY de HEROIS
    if ((mundo_virtual->herois = (heroi *) malloc ((mundo_virtual->num_herois) * sizeof (heroi)) ) == NULL) {
        printf("ERRO! Não foi possível alocar memória para o ARRAY de HEROIS (MUNDO)");
        return 1;
    };

    // Inicializar os N herois
    for (int i=0; i<(mundo_virtual->num_herois); i++) {
        if (inicializar_heroi(&(*mundo_virtual).herois[i], *mundo_virtual, i)) 
            return 1;
    };

    /* HEROIS */
    /* BASES */

    // Alocar memoria para o ARRAY de BASES
    if ((mundo_virtual->bases = (base *) malloc ((mundo_virtual->num_bases) * sizeof (base)) ) == NULL) {
        printf("ERRO! Não foi possível alocar memória para o ARRAY de BASES (MUNDO)");
        return 1;
    };

    // Inicializar as N bases
    for (int i=0; i<(mundo_virtual->num_bases); i++) {
            if (inicializar_base(&(*mundo_virtual).bases[i], *mundo_virtual, i))
                return 1;
    };

    /* BASES */
    /* MISSOES */

    // Alocar memoria para o ARRAY de MISSOES
    if ((mundo_virtual->missoes = (missao *) malloc ((mundo_virtual->num_missoes) * sizeof (missao)) ) == NULL) {
        printf("ERRO! Não foi possível alocar memória para o ARRAY de MISSOES (MUNDO)");
        return 1;
    };

    // Inicializar as missoes
    for (int i=0; i<(mundo_virtual->num_missoes); i++) {
        if (inicializar_missao(&mundo_virtual->missoes[i], *mundo_virtual, i))
            return 1;
    };

    /* MISSOES */

    // Retorno que deu tudo certo :)
    return 0;
};

void imprimir_mundo (mundo mundo_virtual) {

    printf("\n");
    printf("Tempo final (minutos): \t T_FIM_DO_MUNDO \t = %d \n", (mundo_virtual).tempo_max);
    printf("Tamanho do mundo: \t T_TAMANHO_MUNDO \t = %d \n", ((mundo_virtual).tamanho_mundo.x));
    printf("Numero de habilidades: \t N_HABILIDADES \t\t = %d \n", (mundo_virtual).num_habilidades);
    printf("Numero de herois: \t N_HEROIS \t\t = %d \n", (mundo_virtual).num_herois);
    printf("Numero de bases: \t N_BASES \t\t = %d \n", (mundo_virtual).num_bases);
    printf("Numero de missoes: \t N_MISSOES \t\t = %d \n", (mundo_virtual).num_missoes);

};

// Inicializa todas as variaveis de um UNICO heroi
// Retorna 1 para estado de erro - NAO FOI POSSIVEL INICIAR O HEROI
int inicializar_heroi (heroi *heroi_virtual, mundo mundo_virtual, int id) {

    int total_de_habilidades;
    int temp;
    
    // Inicializar o ID
    (*heroi_virtual).id = id;

    // Inicializar o XP em 0
    (*heroi_virtual).experiencia = 0;

    // Inicializar a Paciencia
    // Inteiro de 0 - 100
    (*heroi_virtual).paciencia = gerar_aleatorio(0,100);

    // Inicializar a Velocidade (metros/min)
    // Inteiro de 50 a 5000
    (*heroi_virtual).velocidade = gerar_aleatorio(50,5000);

    // Inicializar as habilidades
    // Gera um numero de 1 a 3, para ver o numero de habilidades do heroi
    total_de_habilidades = gerar_aleatorio(1, 3);
    
    // Inicializar a TAD de CONJUNTOS
    if ((heroi_virtual->habilidades = inicializar_conjunto()) == NULL)
        return 1;

    (*heroi_virtual).habilidades->prox = NULL;

    // Habilidades de 1 a MAX_HABILIDADES
    // Retorna 1 em caso de ERRO
    // Gera 1 a 3 habilidades aleatorias DIFERENTES
    temp = 0;
    for (int i=1; i<=total_de_habilidades; i++) {
        // Repete até achar uma habilidade diferente das que ja tem
        do { 
            temp = gerar_aleatorio(0,(mundo_virtual.num_habilidades - 1)); 
        } while ( (busca_conjunto ((*heroi_virtual).habilidades, temp) != NULL ) );
        // Insere a habilidade
        if (inserir_conjunto ((*heroi_virtual).habilidades, temp)) {
                printf("ERRO! Não foi possível alocar memória para HERÓI");
            return 1;
        };
    };
    
    // Retorno que deu tudo certo :)
    return 0;
};

void imprimir_heroi (heroi heroi_virtual) {
    printf("\n");
    printf("ID: \t\t = %d \n", (heroi_virtual).id);
    printf("Experiencia: \t = %d \n", (heroi_virtual).experiencia);
    printf("Paciencia: \t = %d \n", (heroi_virtual).paciencia);
    printf("Velocidade: \t = %d \n", (heroi_virtual).velocidade);
    printf("Habilidades: \t = ");
    imprimir_conjunto ((heroi_virtual).habilidades);
    printf("\n\n");
};

// Incializar uma única base
// Retorna 1 para estado de erro - NAO FOI POSSIVEL INICIAR O HEROI
int inicializar_base (base *base_virtual, mundo mundo_virtual, int id) {

    // ID inteiro >= 0
    (*base_virtual).id = id;

    // Inicializar a lotacao da base, sendo um numero de 3 a 10
    (*base_virtual).lotacao = gerar_aleatorio(3,10);

    // Inicializar o conjunto vazio de presentes
    if ((base_virtual->presentes = inicializar_conjunto()) == NULL)
        return 1;

    // Inicializar o numero de presentes
    (*base_virtual).num_presentes = 0;

    // Inicializar a lista de espera - VAZIA
    if (((*base_virtual).espera = inicializar_fila()) == NULL)
        return 1;

    // Inicializar a localizacao
    // Localizacao da base (representado por (x,y))
    (*base_virtual).local.x = gerar_aleatorio(0, (mundo_virtual.tamanho_mundo.x - 1));
    (*base_virtual).local.y = gerar_aleatorio(0, (mundo_virtual.tamanho_mundo.y - 1));

    // Inicializar o conjunto
    if ((base_virtual->habilidades = inicializar_conjunto()) == NULL) {
        printf("ERRO! Não foi possivel alocar memoria para HABILIDADES da BASE");
        return 1;
    };

    return 0;
};

void imprimir_base(base base_virtual) {
    printf("\n");
    printf("ID: \t\t\t = %d \n", base_virtual.id);
    printf("Lotacao: \t\t = %d \n", base_virtual.lotacao);
    printf("Localizacao X e Y: \t = (%d,%d) \n", base_virtual.local.x,  base_virtual.local.y);
    printf("Presentes: \t\t = ");
    imprimir_conjunto(base_virtual.presentes);
    printf("\n");
    printf("Quantidade de presentes: = %d", base_virtual.num_presentes);
    printf("\n");
};

// Inicializar uma UNICA missao
// Retona 1 em caso de erro
int inicializar_missao (missao *missao_virtual, mundo mundo_virtual, int id) {

    int total_de_habilidades;
    int habilidade;
    double distancia;
    double temp;
    int menor;

    // Inicializar o ID
    (*missao_virtual).id = id;

    // Inicializar a localizacao
    (*missao_virtual).local.x = gerar_aleatorio(0, (mundo_virtual.tamanho_mundo.x - 1));
    (*missao_virtual).local.y = gerar_aleatorio(0, (mundo_virtual.tamanho_mundo.y - 1));

    // Inicializar as habilidades necessárias
    // Deve ser pertencente a [6..10] no caso de 10
    total_de_habilidades = gerar_aleatorio(6,10);

    // Alocar memoria e verificar erro de MALLOC
    if ((missao_virtual->habilidades = inicializar_conjunto()) == NULL) {
        printf("ERRO! Não foi possível alocar memória para HABILIDADES da MISSAO");
        return 1;
    };

    // Insere 0..total_habilidades habilidades aleatorias diferentes
    for (int i=0; i<total_de_habilidades; i++) {
        do { 
            habilidade = gerar_aleatorio(0,(mundo_virtual.num_habilidades-1));
        } while ( search_conj (missao_virtual->habilidades, habilidade) );
        inserir_conjunto(missao_virtual->habilidades, habilidade);
    };

    // Aloca memoria para o ARRAY de BASES ORDENADAS
    // ORDENADAS POR PROXIMIDADE
    if ((missao_virtual->ordem_bases = (int *) malloc (mundo_virtual.num_bases * sizeof(int))) == NULL) {
        printf("ERRO! Não foi possível alocar memória para BASES ORDENADAS (missao)");
        return 1;
    };

    // Selection SORT
    // Ordena as BASES em DISTANCIA
    for (int i=0; i<mundo_virtual.num_bases; i++) {
        missao_virtual->ordem_bases[i] = mundo_virtual.bases[i].id;
    };
    for (int i=0; i<mundo_virtual.num_bases; i++) {

        // Indice no ARRAY que tem IDS
        menor = i;
        distancia = distancia_pontos(mundo_virtual.bases[missao_virtual->ordem_bases[i]].local.x,
                                     mundo_virtual.bases[missao_virtual->ordem_bases[i]].local.y,
                                     missao_virtual->local.x,
                                     missao_virtual->local.y);

        // Acha o menor
        for (int j=(i+1); j<mundo_virtual.num_bases; j++) {
            temp = distancia_pontos(mundo_virtual.bases[missao_virtual->ordem_bases[j]].local.x,
                                    mundo_virtual.bases[missao_virtual->ordem_bases[j]].local.y,
                                    missao_virtual->local.x,
                                    missao_virtual->local.y);
            if (temp < distancia) {
                distancia = temp;
                menor = j;
            };
        };

        // Troca os indices
        habilidade = missao_virtual->ordem_bases[i];
        missao_virtual->ordem_bases[i] = missao_virtual->ordem_bases[menor];
        missao_virtual->ordem_bases[menor] = habilidade;
    };

    return 0;
};

void imprimir_missao (missao missao_virtual) {
    printf("\n");
    printf("ID: \t\t\t = %d \n", missao_virtual.id);
    printf("Local: \t\t\t = (%d,%d) \n", missao_virtual.local.x, missao_virtual.local.y);
    printf("Habilidades minimas: \t = ");
    imprimir_conjunto(missao_virtual.habilidades);
    printf("\n");
};