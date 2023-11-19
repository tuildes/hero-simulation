#include "mundo.h"

#define tamanho_maximo 20000;
#define tempo_maximo 525000;

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
    (*mundo_virtual).num_habilidades = 10;

    // Inicializa o numero de herois
    // Numero de habilidades * 5
    (*mundo_virtual).num_herois = ((*mundo_virtual).num_habilidades * 5);

    // Inicializa o numero de bases
    // Numero de herois / 6
    (*mundo_virtual).num_bases = ((*mundo_virtual).num_herois / 6);

    // Inicializa o numero de missoes
    // Numero de missoes = Tempo_max / 100
    (*mundo_virtual).num_missoes = ((*mundo_virtual).tempo_max / 100);

    /* Imprimir todas as infos a cima*/
    printf("\n");

    printf("Tempo inicial: \t\t T_INICIO \t\t = %d \n", (*mundo_virtual).relogio);
    printf("Tempo final (minutos): \t T_FIM_DO_MUNDO \t = %d \n", (*mundo_virtual).tempo_max);
    printf("Tamanho do mundo: \t T_TAMANHO_MUNDO \t = %d \n", ((*mundo_virtual).tamanho_mundo.x));
    printf("Numero de habilidades: \t N_HABILIDADES \t\t = %d \n", (*mundo_virtual).num_habilidades);
    printf("Numero de herois: \t N_HEROIS \t\t = %d \n", (*mundo_virtual).num_herois);
    printf("Numero de bases: \t N_BASES \t\t = %d \n", (*mundo_virtual).num_bases);
    printf("Numero de missoes: \t N_MISSOES \t\t = %d \n", (*mundo_virtual).num_missoes);

    printf("\n");

    // Retorno que deu tudo certo :)
    return 0;
};

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
    total_de_habilidades = (1 + (rand() % 3));
    
    // Habilidades de 1 a 10, 0 eh nenhuma habilidade
    for (int i=0; i<total_de_habilidades; i++) {
        
        if (i < total_de_habilidades) {

            (*heroi_virtual).habilidades[i] = gerar_aleatorio(1,mundo_virtual.num_habilidades);

            if (i == 1)
                while (((*heroi_virtual).habilidades[0]) == (*heroi_virtual).habilidades[1])
                    (*heroi_virtual).habilidades[i] = gerar_aleatorio(1,mundo_virtual.num_habilidades);;

            if (i == 2)
                while ((((*heroi_virtual).habilidades[0]) == (*heroi_virtual).habilidades[2]) ||
                       (((*heroi_virtual).habilidades[1]) == (*heroi_virtual).habilidades[2]))
                    (*heroi_virtual).habilidades[i] = gerar_aleatorio(1,mundo_virtual.num_habilidades);
        }
        else
            (*heroi_virtual).habilidades[i] = 0;
    }
    

    /* Imprimir todas as infos a cima*/

    // printf("\n");
    // printf("ID: \t\t = %d \n", (*heroi_virtual).id);
    // printf("Experiencia: \t = %d \n", (*heroi_virtual).experiencia);
    // printf("Paciencia: \t = %d \n", (*heroi_virtual).paciencia);
    // printf("Velocidade: \t = %d \n", (*heroi_virtual).velocidade);
    // printf("HAB 1: \t\t = %d \n", (*heroi_virtual).habilidades[0]);
    // printf("HAB 2: \t\t = %d \n", (*heroi_virtual).habilidades[1]);
    // printf("HAB 3: \t\t = %d \n", (*heroi_virtual).habilidades[2]);
    // printf("\n");

    // Retorno que deu tudo certo :)
    return 0;
};

// Incializar uma única base
// Retorna 1 para estado de erro - NAO FOI POSSIVEL INICIAR O HEROI
int inicializar_base (base *base_virtual, mundo mundo_virtual, int id) {

    // ID inteiro >= 0
    (*base_virtual).id = id;

    // Inicializar a lotacao da base, sendo um numero de 3 a 10
    (*base_virtual).lotacao = gerar_aleatorio(3,10);

    // Inicializar o conjunto vazio de presentes

    // Inicializar a lista de espera - VAZIA
    (*base_virtual).espera.inicio = 0;
    (*base_virtual).espera.final = 0;

    if (!filaVazia((*base_virtual).espera))
        return 1;

    // Inicializar a localizacao
    // Localizacao da base (representado por (x,y))
    (*base_virtual).local.x = gerar_aleatorio(0, (mundo_virtual.tamanho_mundo.x - 1));
    (*base_virtual).local.y = gerar_aleatorio(0, (mundo_virtual.tamanho_mundo.y - 1));
    (*base_virtual).local.distancia = 0;

    /* Imprimir todas as infos a cima*/

    // printf("\n");
    // printf("ID: \t\t\t = %d \n", (*base_virtual).id);
    // printf("Lotacao: \t\t = %d \n", (*base_virtual).lotacao);
    // printf("Localizacao X e Y: \t = (%d,%d) \n", (*base_virtual).local.x,  (*base_virtual).local.y);
    // printf("\n");

    /* Imprimir todas as infos a cima*/

    return 0;
};

// Inicializar uma UNICA missao
// Retona 1 em caso de erro
int inicializar_missao (missao *missao_virtual, mundo mundo_virtual, int id) {

    // Inicializar o ID

    // Inicializar a localizacao

    // Inicializar as habilidades necessárias
    // 1 a N de habilidades, sendo 0 sem habilidade

    return 0;
};

// Função que chama todas as outras
// Usada para inciailizar TODO o mundo virtual -> herois, mundo, missao, etc...
// Retorna 1 para caso de erro ou 0 para sucesso
int inicializar_realidade_virtual() {
    return 1;
};