#include "mundo.h"

// Função que chama todas as outras
// Usada para inicializar TODO o mundo virtual -> herois, mundo, missao, etc...
// Retorna 1 para caso de erro ou 0 para sucesso
int inicializar_realidade_virtual(mundo *mundo_virtual, lef *eventos_mundo) {

    // Utiliza-se DEFINES em ENTIDADES.H
    // Inicializar as variaveis do MUNDO
    if (inicializar_mundo(mundo_virtual))
        return 1;

    // Gera o primeiro EVENTO para cada um dos HEROIS
    // Cada HEROI chega entre 0 .. 3 dias
    for (int i=0; i<mundo_virtual->num_herois; i++)
        inserir_lef(eventos_mundo, cria_evento (gerar_aleatorio(0,4320),
                                                0, 
                                                mundo_virtual->herois[i].id, 
                                                gerar_aleatorio(0, (mundo_virtual->num_bases - 1))));

    // Insere TODAS as MISSOES na LEF
    for (int i=0; i<mundo_virtual->num_missoes; i++)
        inserir_lef(eventos_mundo, cria_evento (gerar_aleatorio(0,(mundo_virtual->tempo_max)),
                                                7, 
                                                mundo_virtual->missoes[i].id, 
                                                0));

    // Inserir o FIM
    inserir_lef(eventos_mundo, cria_evento (mundo_virtual->tempo_max, 8, 0, 0));

    return 0;
};

// Função de finalizacao da realidade virtual
// Imprime todos os resultados e libera a memória
void finalizar_realidade_virtual(mundo *mundo_virtual, lef *eventos_futuros) {

    // Deletar todos os herois
    for (int i=0; i<mundo_virtual->num_herois; i++) {
        destruir_conjunto(mundo_virtual->herois[i].habilidades);
    };
    free (mundo_virtual->herois);

    // Deletar todas as bases
    for (int i=0; i<mundo_virtual->num_bases; i++) {
        destruir_fila(mundo_virtual->bases[i].espera);
        destruir_conjunto(mundo_virtual->bases[i].presentes);
        destruir_conjunto(mundo_virtual->bases[i].habilidades);
    };
    free (mundo_virtual->bases);

    // Deletar todas as missoes
    for (int i=0; i<mundo_virtual->num_missoes; i++) {
        destruir_conjunto(mundo_virtual->missoes[i].habilidades);
        free (mundo_virtual->missoes[i].ordem_bases);
    };
    free (mundo_virtual->missoes);

    // Deletar todos os eventos
    destruir_lef(eventos_futuros);

    // Deletar o mundo

    return;
};