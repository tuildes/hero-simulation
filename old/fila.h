#include "principal.h"

#define TAMANHO_FILA 100

/* Funções de manipulação de fila */

struct fila {

	int inicio;
	int final;
	int fila[TAMANHO_FILA];

};

int filaVazia(struct fila p);
int filaCheia(struct fila p);
void inserirFila (struct fila *p, int n);
int removerFila (struct fila *p);
int inicioFila (struct fila p);