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

int main () {

    // Definindo a seed randomica do programa
    srand(time(NULL));

    // Incializacao
    mundo mundo_virtual;

    if (inicializar_realidade_virtual(&mundo_virtual)) {
        printf("\033[0;31mERRO! Simulação abortada na inicialização :c\033[0;37m\n");
        finalizar_realidade_virtual(&mundo_virtual);
        return 1;
    };

    finalizar_realidade_virtual(&mundo_virtual);

    return 0;
}