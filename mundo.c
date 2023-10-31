#include "mundo.h"

#define tamanho_max 20000;

/* Funções de manipulação do mundo de heróis */

// Inicializa todas as variaveis do mundo
// Retorna 1 para estado de erro - NAO FOI POSSIVEL INICIAR O MUNDO
int inicializar_mundo(mundo *mundo_virtual) {

    // Inicializa o tempo inicial
    (*mundo_virtual).relogio = 0;
    // Inicializa o tempo final
    // Tempo maximo = 525000 (365 dias)
    (*mundo_virtual).tempo_max = 525000;

    // Incializa o tamanho do mundo
    (*mundo_virtual).tamanho_mundo.x = tamanho_max;
    (*mundo_virtual).tamanho_mundo.y = tamanho_max;

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
    // Gera um numero de 1 a 3, para ver o numero de habilidades
    // Habilidades de 1 a 10, 0 eh nenhuma habilidade
    

    /* Imprimir todas as infos a cima*/
    /*
        printf("\n");
        printf("ID: \t\t = %d \n", (*heroi_virtual).id);
        printf("Experiencia: \t = %d \n", (*heroi_virtual).experiencia);
        printf("Paciencia: \t = %d \n", (*heroi_virtual).paciencia);
        printf("Velocidade: \t = %d \n", (*heroi_virtual).velocidade);
        printf("\n");
    */

    // Retorno que deu tudo certo :)
    return 0;
};