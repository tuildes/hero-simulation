#include "principal.h"

/* TAD de LISTA DE EVENTOS FUTUROS */
typedef struct objeto_evento evento;
struct objeto_evento {
    int tempo; // Tempo no evento
    int tipo; // Tipo, que vai ser utilizado para a impressao
    int dado1;
    int dado2;
};

// Cada célula que possui INFO (struct evento) e um ponteiro do proximo
typedef struct objeto_nodo_lef nodo_lef;
struct objeto_nodo_lef {
    evento *info;
    nodo_lef *prox;
};

// Cabeça do LEF
typedef struct objeto_lef lef;
struct objeto_lef {
    nodo_lef *primeiro;
};

// Cria um evento contendo os parâmetros informados.
// Retorna um ponteiro para o evento
// ERRO -> retorna NULL se falhar.
evento *cria_evento (int tempo, int tipo, int dado1, int dado2);

// Destroi um evento e retorna NULL.
evento *destruir_evento (evento *EVENTO);

// Inicializa a LEF
// Retorna um ponteiro
// ERRO -> Retorna NULL se falhar
lef *cria_lef (void);

// Destroi a LEF
// Retorna NULL 
lef *destruir_lef (lef *LEF);

// Inserir o evento no LEF
// Insere com Insertion sort
// Retorna 1 para ERRO e 0 para SUCESSO
int inserir_lef (lef *LEF, evento *EVENTO);

// Remove o primeiro evento na LEF
// Retorna o ponteiro do evento ou NULL para falha
evento *retirar_lef (lef *LEF);

// Verifica se a LEF esta vazia
// Retorna 1 para vazia, 0 para nao ou -1 para ERRO
int vazia_lef (lef *LEF);

// Imprime a LEF
// tempo tipo dado1 dado2
void imprime_lef (lef *LEF);