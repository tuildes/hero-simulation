#!/bin/bash

echo "Deletando os arquivo .o e o executavel"

clear;
cd ..;
gcc -Wall -o programa programa.c mundo.c entidades.c fila.c principal.c;
cd gcc-shell;