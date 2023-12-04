OBJS	= programa.o principal.o entidades.o lef.o conjuntos.o fila.o mundo.o eventos.o
SOURCE	= programa.c principal.c entidades.c lef.c conjuntos.c fila.c mundo.c eventos.c
HEADER	= principal.h entidades.h lef.h conjuntos.h fila.h mundo.h eventos.h
OUT	= theboys
CC	 = gcc
FLAGS	 = -g3 -c -Wall
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

programa.o: programa.c
	$(CC) $(FLAGS) programa.c 

principal.o: principal.c
	$(CC) $(FLAGS) principal.c 

entidades.o: entidades.c
	$(CC) $(FLAGS) entidades.c 

lef.o: lef.c
	$(CC) $(FLAGS) lef.c 

conjuntos.o: conjuntos.c
	$(CC) $(FLAGS) conjuntos.c 

fila.o: fila.c
	$(CC) $(FLAGS) fila.c 

mundo.o: mundo.c
	$(CC) $(FLAGS) mundo.c 

eventos.o: eventos.c
	$(CC) $(FLAGS) eventos.c 


clean:
	rm -f $(OBJS) $(OUT)

debug: $(OUT)
	valgrind $(OUT)

valgrind: $(OUT)
	valgrind $(OUT)

valgrind_leakcheck: $(OUT)
	valgrind --leak-check=full $(OUT)

valgrind_extreme: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT)
