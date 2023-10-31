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
#include "mundo.h"

int main () {

    // Definindo a seed randomica do programa
    srand(0);
    
    // Variaveis
    mundo mundo_virtual;
    heroi heroi_virtual;

    // Incializacoes
    if (inicializar_mundo(&mundo_virtual)) {
        printf("\nOps! Deu um erro ao incializar o mundo!\n");
        return 1;
    };

    inicializar_heroi (&heroi_virtual, mundo_virtual, 1);

    // Mundo propriamente dito

    // Liberar memoria de tudo

    return 0;
}