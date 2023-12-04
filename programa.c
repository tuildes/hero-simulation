/*

    TRABALHO GRANDE - THE BOYS
    ESPECIFICACAÇÂO: https://wiki.inf.ufpr.br/maziero/doku.php?id=c:theboys
    Matéria: Programação 1 - 2023/2
    Professor: Luiz C. P. Albini

    Aluno: Gustavo Benitez Frehse
    Matricula: GRR 20235087
    Curso/Semestre: Informática Biomédica (2° semestre)

*/

#include "principal.h"
#include "entidades.h"
#include "eventos.h"
#include "lef.h"
#include "mundo.h"

int main () {

    // Definindo a seed randomica do programa
    srand(time(NULL));

    // Variaveis de ambiente
    mundo mundo_virtual;
    lef* eventos_mundo;
    int tentativas = 0;
    int concluidas = 0;

    // Inicializar a LEF da simulação
    if ((eventos_mundo = cria_lef()) == NULL) {
        printf("\033[0;31mERRO! [EVENTOS] Simulação abortada na inicialização :c\033[0;37m\n");
        return 1;
    };

    // Inicializa o MUNDO como um todo
    if (inicializar_realidade_virtual(&mundo_virtual, eventos_mundo)) {
        printf("\033[0;31mERRO! [MUNDO] Simulação abortada na inicialização :c\033[0;37m\n");
        finalizar_realidade_virtual(&mundo_virtual, eventos_mundo);
        return 1;
    };

    // Clock do MUNDO
    // Variaveis de CLOCK
    int aux;
    double temp;
    evento* evento_atual;

    // Roda todos os eventos do LEF
    while (!vazia_lef(eventos_mundo)) {

        if ((evento_atual = retirar_lef (eventos_mundo)) == NULL)
            return 1;

        switch (evento_atual->tipo) {
        
        // CHEGA
        case 0:
            if (evento_chega (  evento_atual->tempo,
                                &mundo_virtual.herois[evento_atual->dado1],
                                mundo_virtual.bases[evento_atual->dado2],
                                eventos_mundo))
                printf ("%6d: CHEGA\t HEROI %2d BASE %2d (%2d/%2d) ESPERA\n",
                        evento_atual->tempo,
                        evento_atual->dado1, 
                        evento_atual->dado2,
                        mundo_virtual.bases[evento_atual->dado2].num_presentes,
                        mundo_virtual.bases[evento_atual->dado2].lotacao
                        );
            else
                printf ("%6d: CHEGA\t HEROI %2d BASE %2d (%2d/%2d) DESISTE\n",
                    evento_atual->tempo,
                    evento_atual->dado1, 
                    evento_atual->dado2,
                    mundo_virtual.bases[evento_atual->dado2].num_presentes,
                    mundo_virtual.bases[evento_atual->dado2].lotacao);
            break;

        // ESPERA
        case 1:
            printf ("%6d: ESPERA\t HEROI %2d BASE %2d (%2d)\n",
                        evento_atual->tempo,
                        evento_atual->dado1, 
                        evento_atual->dado2,
                        mundo_virtual.bases[evento_atual->dado2].espera->tamanho);
            evento_espera ( evento_atual->tempo,
                            mundo_virtual.herois[evento_atual->dado1],
                            &mundo_virtual.bases[evento_atual->dado2], 
                            eventos_mundo);
            break;

        // DESISTE
        case 2:
            printf ("%6d: DESISTE\t HEROI %2d BASE %2d\n",
                        evento_atual->tempo,
                        evento_atual->dado1, 
                        evento_atual->dado2);
            evento_desiste (evento_atual->tempo,
                            mundo_virtual.herois[evento_atual->dado1],
                            mundo_virtual.bases[evento_atual->dado2],
                            eventos_mundo,
                            mundo_virtual);
            break;

        // AVISA
        case 3:
            printf ("%6d: AVISA\t PORTEIRO BASE %2d (%2d/%2d) FILA ",
                        evento_atual->tempo,
                        evento_atual->dado1, 
                        mundo_virtual.bases[evento_atual->dado1].num_presentes,
                        mundo_virtual.bases[evento_atual->dado1].lotacao);
            imprimir_fila (mundo_virtual.bases[evento_atual->dado1].espera);
            printf("\n");
            evento_avisa (evento_atual->tempo, &mundo_virtual.bases[evento_atual->dado1], eventos_mundo, &mundo_virtual);
            break;

        // ENTRA
        case 4:
            aux = evento_entra (evento_atual->tempo,
                                mundo_virtual.herois[evento_atual->dado1],
                                mundo_virtual.bases[evento_atual->dado2],
                                eventos_mundo);
            printf ("%6d: ENTRA\t HEROI %2d BASE %2d (%2d/%2d) SAI %d\n",
                        evento_atual->tempo,
                        evento_atual->dado1,
                        evento_atual->dado2, 
                        mundo_virtual.bases[evento_atual->dado2].num_presentes,
                        mundo_virtual.bases[evento_atual->dado2].lotacao,
                        aux);
            break;

        // SAI
        case 5:
            evento_sai (evento_atual->tempo,
                        mundo_virtual.herois[evento_atual->dado1],
                        &mundo_virtual.bases[evento_atual->dado2],
                        eventos_mundo,
                        mundo_virtual);
            printf ("%6d: SAI\t HEROI %2d BASE %2d (%2d/%2d)\n",
                        evento_atual->tempo,
                        evento_atual->dado1,
                        evento_atual->dado2, 
                        mundo_virtual.bases[evento_atual->dado2].num_presentes,
                        mundo_virtual.bases[evento_atual->dado2].lotacao);
            break;

        // VIAJA
        case 6:
            temp = (evento_viaja(evento_atual->tempo,
                                    &mundo_virtual.herois[evento_atual->dado1],
                                    &mundo_virtual.bases[evento_atual->dado2],
                                    eventos_mundo,
                                    mundo_virtual));
            aux = ceil (temp);
            printf ("%6d: VIAJA\t HEROI %2d BASE %2d BASE %2d DIST %d VEL %d CHEGA %d\n",
                        evento_atual->tempo,
                        evento_atual->dado1,
                        mundo_virtual.herois[evento_atual->dado1].base_atual,
                        evento_atual->dado2,
                        aux,
                        mundo_virtual.herois[evento_atual->dado1].velocidade,
                        (((aux/mundo_virtual.herois[evento_atual->dado1].velocidade))+evento_atual->tempo+1));
            break;

        // MISSAO
        case 7:
            tentativas++;
            concluidas += evento_missao(evento_atual->tempo, 
                                        mundo_virtual.missoes[evento_atual->dado1], 
                                        eventos_mundo, 
                                        mundo_virtual);
            break;

        // FINAL
        case 8:
            // Aqui é onde tudo acaba, e teremos os resultados :)
            evento_fim (evento_atual->tempo, mundo_virtual, tentativas, concluidas);
            // Liberação de tudo
            free (evento_atual);
            finalizar_realidade_virtual(&mundo_virtual, eventos_mundo);
            return 0;
            break;
        
        default:
            break;
        };

        // Libera memória do PONTEIRO de EVENTO retornado do RETIRAR_LEF
        free (evento_atual);
    };

    // Tudo aconteceu como esperado :)
    // EXIT_SUCCESS
    return 0;
}