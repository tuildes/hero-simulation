#include "eventos.h"

int evento_chega (int INSTANTE, heroi* HEROI, base BASE, lef* LEF) {

    HEROI->base_atual = BASE.id;
    short ESPERA;

    // Verifica se há vagas na BASE
    if ((BASE.num_presentes != BASE.lotacao) && (fila_vazia(*BASE.espera)))
        ESPERA = 1;
    else
        ESPERA = (HEROI->paciencia > (10 * (BASE.espera->tamanho)));

    // Se pode esperar, ela entra na fila de ESPERA da BASE
    // Se não, o heroi DESISTE
    if (ESPERA)
        inserir_lef(LEF, cria_evento (INSTANTE, 1, HEROI->id, BASE.id));
    else
        inserir_lef(LEF, cria_evento (INSTANTE, 2, HEROI->id, BASE.id));

    return ESPERA;
};

void evento_espera (int INSTANTE, heroi HEROI, base* BASE, lef* LEF) {

    if (inserir_fila(BASE->espera, HEROI.id)) {
        printf ("ERRO! Não foi possivel colocar o HEROI na FILA");
        return;
    };

    // Insere na LEF: AVISO ao PORTEIRO
    inserir_lef(LEF, cria_evento (INSTANTE, 3, BASE->id, 0));
};

void evento_desiste (int INSTANTE, heroi HEROI, base BASE, lef* LEF, mundo MUNDO) {

    int base_aleatoria;

    // Fica até gerar uma base diferente da que desistiu
    do { 
        base_aleatoria = gerar_aleatorio(0, (MUNDO.num_bases-1));
    } while ( base_aleatoria == BASE.id);

    // Insere na LEF: A viagem do HEROI na BASE ALEATORIA
    inserir_lef(LEF, cria_evento (INSTANTE, 6, HEROI.id, base_aleatoria));

};

void evento_avisa (int INSTANTE, base* BASE, lef* LEF, mundo* MUNDO) {

    int aux;
    conjunto* temp;
    while ((BASE->num_presentes != BASE->lotacao) && (!(fila_vazia(*BASE->espera)))) {
        aux = remover_fila(BASE->espera);
        inserir_conjunto(BASE->presentes, aux);
        BASE->num_presentes++;
        inserir_lef(LEF, cria_evento (INSTANTE, 4, aux, BASE->id));

        // Inserir as HABILIDADES no conjunto
        for (temp = MUNDO->herois[aux].habilidades->prox; temp != NULL; temp = temp->prox)
            inserir_conjunto(BASE->habilidades, temp->num);

        // Imprimir a entrada de cada pessoa
        printf ("%6d: AVISA\t PORTEIRO BASE %2d ADMITE %2d\n", INSTANTE, BASE->id, aux);
    };
};

int evento_entra (int INSTANTE, heroi HEROI, base BASE, lef* LEF) {

    // Tempo de permanencia na BASE
    int TPB = (15 + HEROI.paciencia * gerar_aleatorio(1,20) );
    // Insere na LEF: SAIDA do HEROI
    inserir_lef(LEF, cria_evento ((INSTANTE + TPB), 5, HEROI.id, BASE.id));
    return (TPB + INSTANTE);
};

void evento_sai (int INSTANTE, heroi HEROI, base* BASE, lef* LEF, mundo MUNDO) {

    int base_aleatoria;
    conjunto* aux;

    // Fica até gerar uma base diferente da que desistiu
    do { 
        base_aleatoria = gerar_aleatorio(0, (MUNDO.num_bases-1));
    } while ( base_aleatoria == BASE->id);

    // Remover o HEROI dos PRESENTES da BASE
    if (buscar_remover_conjunto(BASE->presentes, HEROI.id) == -1)
        printf("ERRO! O Heroi não estava na BASE antes de SAIR");

    // Remover todas as habilidades do HEROI da BASE
    for (aux = HEROI.habilidades->prox; aux != NULL; aux = aux->prox)
        if (buscar_remover_conjunto(BASE->habilidades, aux->num) == -1)
            printf("ERRO! A habilidades não estava na BASE antes de ser retirada");

    BASE->num_presentes--;
    
    // Insere na LEF: VIAJA do HEROI
    inserir_lef(LEF, cria_evento (INSTANTE, 6, HEROI.id, base_aleatoria));
    // Insere na LEF: AVISA da BASE
    inserir_lef(LEF, cria_evento (INSTANTE, 3, BASE->id, 0));

};

double evento_viaja (int INSTANTE, heroi* HEROI, base* BASE, lef* LEF, mundo MUNDO) {

    double distancia = distancia_pontos (
        MUNDO.bases[HEROI->base_atual].local.x,
        MUNDO.bases[HEROI->base_atual].local.y,
        BASE->local.x,
        BASE->local.y
    );
    int duracao = ceil ( distancia / HEROI->velocidade );

    // Insere na LEF: CHEGA na BASE
    inserir_lef(LEF, cria_evento ((INSTANTE + duracao), 0, HEROI->id, BASE->id));

    return distancia;
};

int evento_missao (int INSTANTE, missao MISSAO, lef* LEF, mundo MUNDO) {

    conjunto* aux;

    printf("%6d: MISSAO %4d HAB REQ: ", INSTANTE, MISSAO.id);
    imprimir_conjunto(MISSAO.habilidades);
    printf("\n");

    // Verifica se uma das bases consegue terminar a MISSAO
    for (int i=0; i<MUNDO.num_bases; i++) {

        printf("%6d: MISSAO %4d HAB BASE %2d: ", INSTANTE, MISSAO.id, MISSAO.ordem_bases[i]);
        imprimir_conjunto(MUNDO.bases[MISSAO.ordem_bases[i]].habilidades);
        printf("\n");

        if (contem_conjunto(MISSAO.habilidades, MUNDO.bases[MISSAO.ordem_bases[i]].habilidades)) {
            printf("%6d: MISSAO %4d CUMPRIDA BASE %2d HEROIS: ", INSTANTE, MISSAO.id, MUNDO.bases[MISSAO.ordem_bases[i]].id);
            imprimir_conjunto(MUNDO.bases[MISSAO.ordem_bases[i]].presentes);
            printf("\n");

            // Dar XP para os herois
            for (aux = MUNDO.bases[MISSAO.ordem_bases[i]].presentes->prox; aux != NULL; aux = aux->prox)
                MUNDO.herois[aux->num].experiencia += 1;

            return 1;
        };
    };

    printf("%6d: MISSAO %4d IMPOSSIVEL\n", INSTANTE, MISSAO.id);
    inserir_lef(LEF, cria_evento ((INSTANTE + (24*60)), 7, MISSAO.id, 0));

    return 0;
};

void evento_fim (int INSTANTE, mundo MUNDO, int TENTATIVA, int CONCLUIDAS) {

    // Parece que tudo chegou ao fim, não?
    printf("%6d: FIM\n", INSTANTE);
    for (int i=0; i<MUNDO.num_herois; i++) {
        printf("HEROI %2d PAC %3d VEL %4d EXP %4d HABS ", 
                i, 
                MUNDO.herois[i].paciencia,
                MUNDO.herois[i].velocidade,
                MUNDO.herois[i].experiencia);
        imprimir_conjunto (MUNDO.herois[i].habilidades);
        printf("\n");
    };
    printf("%d/%d MISSOES CUMPRIDAS (%.2f%%) MEDIA %.2f TENTATIVAS/MISSAO\n",
            CONCLUIDAS,
            MUNDO.num_missoes,
            media((CONCLUIDAS*100), MUNDO.num_missoes),
            media(TENTATIVA, MUNDO.num_missoes));
};