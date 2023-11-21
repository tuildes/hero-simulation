#include "eventos.h"

void evento_chega (int INSTANTE, heroi* HEROI, base BASE, lef* LEF) {

    HEROI->base_atual = BASE.id;
    short ESPERA;

    // Teste
    imprimir_heroi(*HEROI);
    imprimir_base(BASE);

    // Verifica se há vagas na BASE
    if ((BASE.num_presentes != BASE.lotacao) && (fila_vazia(BASE.espera)))
        ESPERA = 1;
    else
        ESPERA = (HEROI->paciencia > (10 * ((BASE.espera.fim % BASE.espera.tamanho) - (BASE.espera.inicio % BASE.espera.tamanho))));

    printf("\nESPERA: %d\n", ESPERA);

    // Se pode esperar, ela entra na fila de ESPERA da BASE
    // Se não, o heroi DESISTE
    if (ESPERA)
        inserir_lef(LEF, cria_evento (INSTANTE, 1, HEROI->id, BASE.id));
    else
        inserir_lef(LEF, cria_evento (INSTANTE, 2, HEROI->id, BASE.id));

    return;
};