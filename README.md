# 👻 Simulação de Heróis

> [!NOTE]
> O projeto é uma simulação de eventos feito de forma automática e aleatória de heróis fazendo missões e transitando entre bases para adquirir experiẽncia usando suas habilidades. Totalmente feito em `C` como trabalho final de programação 1 na faculdade [^1]

## ☕ Info

- **ESPECIFICACAÇÂO**: https://wiki.inf.ufpr.br/maziero/doku.php?id=c:theboys [^2]
- **Matéria**: Programação 1 [^1]
- **Data**: segundo semestre de 2023
- **Linguagem**: `C`

## 🐛 Comandos

### Setup:
```bash
# Compilar o programa em um arquivo ./theboys
make

# Rodar o programa
./theboys
```

### Debug
```bash
# Verifica vazamentos de memoria
valgrind --leak-check=full --track-origins=yes -s ./theboys
```

### Limpeza
```bash
# Remove arquivos .o e executaveis
make clean
```

## 🚀 Arquivos

    .
    ├── conjuntos                   # funções de manipulação de conjuntos (lista)
    ├── entidades                   # funções de manipulação das entidades
    ├── eventos                     # funções somente de eventos
    ├── fila                        # TAD de fila (lista encadeada)
    ├── lef                         # TAD de lista de eventos futuros (lista)
    ├── mundo                       # funções de manipulação do mundo e incializações
    ├── principal                   # funções genéricas, que não tem uma categoria, como **gerarAleatorio()**
    ├── programa                    # função MAIN()
    |
    └── README.md                   

[^1]: Faculdade de **Informática Biomédica** na Universidade Federal do Paraná no ano de 2023 (segundo semestre), o curso se consiste em uma matriz de ciência da computação com matérias focadas as áreas biomédicas e aplicações da computação em áreas médicas, como genética.

[^2]: Quaisquer licenças ou direitos do trabalho e especificações dele são descritos no site dos professores, o código feito neste repositório é somente uma replicação e adapatação do trabalho em C.
