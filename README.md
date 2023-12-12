# CABEÇALHO

### TRABALHO GRANDE - THE BOYS

-   **ESPECIFICACAÇÂO**: https://wiki.inf.ufpr.br/maziero/doku.php?id=c:theboys

-   **Matéria**: Programação 1 - 2023/2

-   **Curso/Semestre**: Informática Biomédica (2° semestre)

---

# ARQUIVOS

### Arquivos .C

-   conjuntos.c -> funções de manipulação de conjuntos (lista)

-   entidades.c -> funções de manipulação das entidades

-   eventos.c -> funções somente de eventos

-   fila.c -> TAD de fila (lista encadeada)

-   lef.c -> TAD de lista de eventos futuros (lista)

-   mundo.c -> funções de manipulação do mundo e incializações

-   principal.c -> funções genéricas, que não tem uma categoria, como **gerarAleatorio()**

-   programa.c -> função MAIN()

### Outros

-   MAKEFILE -> Makefile que compila TUDO

-   ./theboys -> Executavel do The Boys

### Comandos uteís

```
$ valgrind --leak-check=full --track-origins=yes -s ./programa > saida.txt

$ make

$ make clean
```
