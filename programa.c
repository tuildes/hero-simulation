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
#include "lef.h"

int main () {

    // Definindo a seed randomica do programa
    srand(time(NULL));
    
    // Variaveis
    // mundo mundo_virtual;
    // heroi heroi_virtual;
    // base base_virtual;
    // missao missao_virtual;

    // Incializacoes
    evento *evento1;
    evento *evento2;
    evento *evento3;
    evento *evento4;
    lef *lef_virtual;

    if ((evento1 = cria_evento(0, 1, 1, 1)) == NULL)
        return 1;
    if ((evento2 = cria_evento(50, 2, 2, 2)) == NULL)
        return 1;
    if ((evento3 = cria_evento(8330, 3, 3, 3)) == NULL)
        return 1;
    if ((evento4 = cria_evento(360, 4, 4, 4)) == NULL)
        return 1;

    if ((lef_virtual = cria_lef()) == NULL)
        return 1;

    // Liberar memoria de tudo
    inserir_lef (lef_virtual, evento1);
    inserir_lef (lef_virtual, evento2);
    inserir_lef (lef_virtual, evento3);
    inserir_lef (lef_virtual, evento4);
    
    printf("\nLef:\n");
    imprime_lef (lef_virtual);

    retirar_lef (lef_virtual);

    printf("\nLef 2:\n");
    imprime_lef (lef_virtual);

    destruir_evento(evento1);
    destruir_evento(evento2);
    destruir_evento(evento3);
    destruir_evento(evento4);
    destruir_lef(lef_virtual);

    return 0;
}