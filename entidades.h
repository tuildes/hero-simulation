#include "principal.h"

#define max_habilidades 10
#define tamanho_maximo 20000;
#define tempo_maximo 525000;

/* Funções de manipulação de Entidades */

// Estrutura padrao do plano cartesiano
typedef struct plano_cartesiano localizacao;
struct plano_cartesiano {
    
    // X e Y do plano cartesiano (inteiro >= 0)
    // Possui um maximo que X e Y podem estar, mas eh verificado na criacao do mundo
    int x;
    int y;

    // Variavel para definir a distancia, se necessario para comparacoes (Inteiro >= 0)
    int distancia;
};

// Estrutura padrao do heroi (H)
typedef struct objeto_heroi heroi;
struct objeto_heroi {

    // ID inteiro >= 0
    int id;
    // Conjunto de habilidades (inteiro ENTRE 1 e 3)
   
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
    
    // Espera -> fila que representa os herois que vao entrar mais tarde
    
    // Localizacao da base (representado por (x,y))
    localizacao local;
    
};

// Estrutura padrao da Missao (M)
typedef struct objeto_missao missao;
struct objeto_missao {

    // ID inteiro >= 0
    int id;
    // Conjunto de habilidades necessarias para a missao
    
    // Localizacao da missao (representado por (x,y))
    localizacao local;
};

// Estrutura padrao do Mundo (W)
typedef struct objeto_mundo mundo;
struct objeto_mundo {

    // Numero de herois no mundo (inteiro >= 0)
    int num_herois;
    // Vetor de todos os herois


    // Numero de bases no mundo (inteiro >= 0)
    int num_bases;
    // Vetor de todos as bases


    // Numero de missoes no mundo (inteiro >= 0)
    int num_missoes;
    // Vetor de todos as missoes


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

// Funções com retorno de 0 para SUCCESS e 1 para ERROR
// Inicializam a sua respectiva entidade, um por vez
int inicializar_mundo(mundo *mundo_virtual);
int inicializar_heroi (heroi *heroi_virtual, mundo mundo_virtual, int id);
int inicializar_base (base *base_virtual, mundo mundo_virtual, int id);
int inicializar_missao (missao *missao_virtual, mundo mundo_virtual, int id);

// Funções sem retorno que APENAS imprimem na tela
void imprimir_mundo(mundo mundo_virtual);
void imprimir_heroi(heroi heroi_virtual);
void imprimir_base(base base_virtual);
void imprimir_missao(missao missao_virtual);

// Inicializa tudo de uma vez
// Retorna 0 para SUCCESS e 1 para ERROR
int inicializar_realidade_virtual();

// Função que executa 1 minuto no mundo
void clock_mundo(void);

// Função de finalizacao da realidade virtual
// Imprime todos os resultados e libera a memória
void finalizar_realidade_virtual(mundo mundo_virtual);