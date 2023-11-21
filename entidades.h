#ifndef _ENTIDADES_H
#define _ENTIDADES_H

#include "principal.h"
#include "conjuntos.h"
#include "fila.h"

#define max_habilidades 5 //10
#define tamanho_maximo 1000 //20000
#define tempo_maximo 1000 //525000

/* Funções de manipulação de Entidades */

// Estrutura padrao do plano cartesiano
typedef struct plano_cartesiano localizacao;
struct plano_cartesiano {
    
    // X e Y do plano cartesiano (inteiro >= 0)
    // Possui um maximo que X e Y podem estar, mas eh verificado na criacao do mundo
    int x;
    int y;

    // Variavel para definir a distancia, se necessario para comparacoes (Inteiro >= 0)
    unsigned int distancia;
};

// Estrutura padrao do heroi (H)
typedef struct objeto_heroi heroi;
struct objeto_heroi {

    // ID inteiro >= 0
    int id;
    // Conjunto de habilidades (inteiro ENTRE 1 e 3)
    conjunto* habilidades;
    // Paciencia do heroi (inteiro >= 0)
    // Afeta permanencia e escolha do heroi -> bases/filas
    int paciencia;
    // Velocidade do heroi (inteiro >= 0)
    // Afeta o tempo de deslocamento do heroi - metros/min
    int velocidade;
    // Experiencia do heroi (inteiro >= 0)
    // Recebida por missoes concluidas pelo heroi - valor inicial 0
    int experiencia;
    // Base que o heroi esta atualmente (id >= 0)
    int base_atual;

};

// Estrutura padrao da base (B)
typedef struct objeto_base base;
struct objeto_base {

    // ID inteiro >= 0
    int id;
    // Lotacao que determina o maximo de herois (inteiro > 0)
    int lotacao;
    // Presentes -> conjunto de IDS dos herois atualmente na base
    // Somente esses podem fazer as missoes de base juntos
    conjunto* presentes;
    // inteiro que diz quantos estão presentes
    int num_presentes;
    // Espera -> fila que representa os herois que vao entrar mais tarde
    fila espera;
    // Localizacao da base (representado por (x,y))
    localizacao local;
    
};

// Estrutura padrao da Missao (M)
typedef struct objeto_missao missao;
struct objeto_missao {

    // ID inteiro >= 0
    int id;
    // Conjunto de habilidades necessarias para a missao
    conjunto* habilidades;
    // Localizacao da missao (representado por (x,y))
    localizacao local;
};

// Estrutura padrao do Mundo (W)
typedef struct objeto_mundo mundo;
struct objeto_mundo {

    // Numero de herois no mundo (inteiro >= 0)
    int num_herois;
    // Vetor de todos os herois
    heroi* herois;

    // Numero de bases no mundo (inteiro >= 0)
    int num_bases;
    // Vetor de todos as bases
    base* bases;

    // Numero de missoes no mundo (inteiro >= 0)
    int num_missoes;
    // Vetor de todos as missoes
    missao* missoes;

    // Numero de habilidades no mundo (inteiro >= 0)
    int num_habilidades;

    // Tamanho do mundo (inteiro >= 0)
    // 1 Metro por unidade de X e Y (inteiros)
    localizacao tamanho_mundo;

    // Tempo do mundo (inteiro >= 0)
    // 1 unidade de tempo da simulação = 1 minuto do mundo real
    int relogio;
    // Tempo maximo do mundo (inteiro >= 0)
    int tempo_max;
};

/* Funções de manipulação do mundo de heróis */

// Inicializa todas as variaveis do mundo
// Retorna 1 para estado de erro - NAO FOI POSSIVEL INICIAR O MUNDO
int inicializar_mundo(mundo *mundo_virtual);
// Inicializa todas as variaveis de um UNICO heroi
// Retorna 1 para estado de erro - NAO FOI POSSIVEL INICIAR O HEROI
int inicializar_heroi (heroi *heroi_virtual, mundo mundo_virtual, int id);
int inicializar_base (base *base_virtual, mundo mundo_virtual, int id);
int inicializar_missao (missao *missao_virtual, mundo mundo_virtual, int id);

// Funções sem retorno que APENAS imprimem na tela - servem para DEPURACAO
void imprimir_mundo(mundo mundo_virtual);
void imprimir_heroi(heroi heroi_virtual);
void imprimir_base(base base_virtual);
void imprimir_missao(missao missao_virtual);

// Função que chama todas as outras
// Usada para inicializar TODO o mundo virtual -> herois, mundo, missao, etc...
// Retorna 1 para caso de erro ou 0 para sucesso
int inicializar_realidade_virtual(mundo *mundo_virtual);

// Função que executa 1 minuto no mundo
void clock_mundo(void);

// Função de finalizacao da realidade virtual
// Libera a memória
void finalizar_realidade_virtual(mundo *mundo_virtual);

#endif