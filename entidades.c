#include "entidades.h"

/* Funções de manipulação do mundo de heróis */

// Inicializa todas as variaveis do mundo
// Retorna 1 para estado de erro - NAO FOI POSSIVEL INICIAR O MUNDO
int inicializar_mundo(mundo *mundo_virtual) {

    // Inicializa o tempo inicial
    (*mundo_virtual).relogio = 0;
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
    (*mundo_virtual).num_bases = ceil(((*mundo_virtual).num_herois / 6.0));

    // Inicializa o numero de missoes
    // Numero de missoes = Tempo_max / 100
    (*mundo_virtual).num_missoes = ((*mundo_virtual).tempo_max / 100);

    // Retorno que deu tudo certo :)
    return 0;
};

void imprimir_mundo (mundo mundo_virtual) {

    printf("\n");
    printf("Tempo inicial: \t\t T_INICIO \t\t = %d \n", (mundo_virtual).relogio);
    printf("Tempo final (minutos): \t T_FIM_DO_MUNDO \t = %d \n", (mundo_virtual).tempo_max);
    printf("Tamanho do mundo: \t T_TAMANHO_MUNDO \t = %d \n", ((mundo_virtual).tamanho_mundo.x));
    printf("Numero de habilidades: \t N_HABILIDADES \t\t = %d \n", (mundo_virtual).num_habilidades);
    printf("Numero de herois: \t N_HEROIS \t\t = %d \n", (mundo_virtual).num_herois);
    printf("Numero de bases: \t N_BASES \t\t = %d \n", (mundo_virtual).num_bases);
    printf("Numero de missoes: \t N_MISSOES \t\t = %d \n", (mundo_virtual).num_missoes);

}

// Inicializa todas as variaveis de um UNICO heroi
// Retorna 1 para estado de erro - NAO FOI POSSIVEL INICIAR O HEROI
int inicializar_heroi (heroi *heroi_virtual, mundo mundo_virtual, int id) {

    int total_de_habilidades;
    
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
    if (((*heroi_virtual).habilidades = (conjunto *) malloc (sizeof(conjunto))) == NULL)
        return 1;

    (*heroi_virtual).habilidades->prox = NULL;

    // Habilidades de 1 a MAX_HABILIDADES
    // Retorna 1 em caso de ERRO
    for (int i=1; i<=total_de_habilidades; i++) {
        if (inserir_conjunto ((*heroi_virtual).habilidades, gerar_aleatorio(1,(mundo_virtual.num_habilidades)))) {
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

    // Inicializar a lotacao da base, sendo um numero de 4 a 10
    // Possivel faltar espaço nos outros (minimo 6 para QUALQUER funcionar)
    (*base_virtual).lotacao = gerar_aleatorio(3,10);

    // Inicializar o conjunto vazio de presentes
    if (((*base_virtual).presentes = (conjunto *) malloc (sizeof(conjunto))) == NULL)
        return 1;

    // Inicializar o numero de presentes
    (*base_virtual).num_presentes = 0;

    // Inicializar a lista de espera - VAZIA
    if (inicializar_fila (&(*base_virtual).espera, ((*base_virtual).lotacao * 2)))
        return 1;

    // Inicializar a localizacao
    // Localizacao da base (representado por (x,y))
    (*base_virtual).local.x = gerar_aleatorio(0, (mundo_virtual.tamanho_mundo.x - 1));
    (*base_virtual).local.y = gerar_aleatorio(0, (mundo_virtual.tamanho_mundo.y - 1));
    (*base_virtual).local.distancia = 0;

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

// Retorna 0 se foi possivel, 1 para impossivel entrar
int inserir_heroi_base (heroi *heroi_virtual, base *base_virtual) {

    if ((base_virtual->num_presentes) == (base_virtual->lotacao))
        return 1;

    inserir_conjunto(base_virtual->presentes, heroi_virtual->id);
    base_virtual->num_presentes++;

    return 0;

};

// Inicializar uma UNICA missao
// Retona 1 em caso de erro
int inicializar_missao (missao *missao_virtual, mundo mundo_virtual, int id) {

    int total_de_habilidades;
    int habilidade;
    // Inicializar o ID
    (*missao_virtual).id = id;

    // Inicializar a localizacao
    (*missao_virtual).local.x = gerar_aleatorio(0, (mundo_virtual.tamanho_mundo.x - 1));
    (*missao_virtual).local.y = gerar_aleatorio(0, (mundo_virtual.tamanho_mundo.y - 1));

    // Inicializar as habilidades necessárias
    // Deve ser pertencente a [6..10] no caso de 10
    total_de_habilidades = gerar_aleatorio((mundo_virtual.num_habilidades - 4),(mundo_virtual.num_habilidades));

    // Alocar memoria e verificar erro de MALLOC
    if ((missao_virtual->habilidades = (conjunto *) malloc (sizeof(conjunto))) == NULL) {
        printf("ERRO! Não foi possível alocar memória para HABILIDADES da BASE");
        return 1;
    };

    // Insere 0..total_habilidades habilidades aleatorias iiferentes
    for (int i=0; i<total_de_habilidades; i++) {
        habilidade = gerar_aleatorio(0,(mundo_virtual.num_habilidades));
        while ((busca_conjunto (missao_virtual->habilidades, habilidade)) != NULL)
            habilidade = gerar_aleatorio(0,(mundo_virtual.num_habilidades));

        inserir_conjunto(missao_virtual->habilidades, habilidade);
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

// Função que chama todas as outras
// Usada para inicializar TODO o mundo virtual -> herois, mundo, missao, etc...
// Retorna 1 para caso de erro ou 0 para sucesso
int inicializar_realidade_virtual(mundo *mundo_virtual) {

    int aux;

    // Inicializar todas as variaveis do mundo
    // Utiliza-se DEFINES
    inicializar_mundo(mundo_virtual);

    // Imprimir o MUNDO - DEPURACAO
    imprimir_mundo(*mundo_virtual);
    printf("\n");

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
        // imprimir_heroi((mundo_virtual)->herois[i]);
    };

    /* HEROIS */
    /* BASES */

    // Alocar memoria para o ARRAY de BASES
    if ((mundo_virtual->bases = (base *) malloc ((mundo_virtual->num_bases) * sizeof (base)) ) == NULL) {
        printf("ERRO! Não foi possível alocar memória para o ARRAY de BASES (MUNDO)");
        return 1;
    };

    // Inicializar as N bases
    aux = 0;
    for (int i=0; i<(mundo_virtual->num_bases); i++) {
            if (inicializar_base(&(*mundo_virtual).bases[i], *mundo_virtual, i))
                return 1;
            aux += (*mundo_virtual).bases[i].lotacao;
    };

    // Caso não de o numero minimo de lotacoes para todos os herois
    while (aux < (mundo_virtual->num_bases*6)) {
        printf("ERRO! Nao tem lotacao minima para todos os herois (MUNDO)\n");
        for (int i=0; i<(mundo_virtual->num_bases); i++) {
            if (inicializar_base(&(*mundo_virtual).bases[i], *mundo_virtual, i))
                return 1;
            aux += (*mundo_virtual).bases[i].lotacao;
        };
    };

    // Inserir aleatoriamente os herois nas bases
    // for (int i=0; i<(mundo_virtual->num_herois); i++) {
    //     aux = gerar_aleatorio(0, (mundo_virtual->num_bases - 1));
    //     while (inserir_heroi_base (&mundo_virtual->herois[i], &mundo_virtual->bases[aux]))
    //         aux = gerar_aleatorio(0, (mundo_virtual->num_bases - 1));
    // };

    // Imprimir a base - DEPURACAO
    // for (int i=0; i<(mundo_virtual->num_bases); i++)
    //     imprimir_base((mundo_virtual)->bases[i]);

    /* BASES */
    /* MISSOES */

    // Alocar memoria para o ARRAY de MISSOES
    if ((mundo_virtual->missoes = (missao *) malloc ((mundo_virtual->num_missoes) * sizeof (missao)) ) == NULL) {
        printf("ERRO! Não foi possível alocar memória para o ARRAY de MISSOES (MUNDO)");
        return 1;
    };

    // Inicializar as missoes
    for (int i=0; i<(mundo_virtual->num_missoes); i++)
        inicializar_missao(&mundo_virtual->missoes[i], *mundo_virtual, i);

    // Imprimir todas as missoes - DEPURACAO
    // for (int i=0; i<(mundo_virtual->num_missoes); i++)
    //     imprimir_missao(mundo_virtual->missoes[i]);

    /* MISSOES */

    return 0;
};

// Função de finalizacao da realidade virtual
// Imprime todos os resultados e libera a memória
void finalizar_realidade_virtual(mundo *mundo_virtual) {

    // Imprimir todo o resultado

    // Deletar todos os herois
    free (mundo_virtual->herois);

    // Deletar todas as bases
    free (mundo_virtual->bases);

    // Deletar todas as missoes
    free (mundo_virtual->missoes);

    // Deletar todos os eventos

    // Deletar o mundo

    return;
};