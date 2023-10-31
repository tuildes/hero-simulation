OBJS	= entidades.o fila.o lef.o lista.o mundo.o principal.o eventos.o programa.o
SOURCE	= entidades.c, fila.c, lef.c, lista.c, mundo.c, principal.c, eventos.c, programa.c
HEADER	= entidades.h, fila.h, lef.h, lista.h, mundo.h, principal.h, eventos.h,
OUT	= programa
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

entidades.o: entidades.c,
	$(CC) $(FLAGS) entidades.c, 

fila.o: fila.c,
	$(CC) $(FLAGS) fila.c, 

lef.o: lef.c,
	$(CC) $(FLAGS) lef.c, 

lista.o: lista.c,
	$(CC) $(FLAGS) lista.c, 

mundo.o: mundo.c,
	$(CC) $(FLAGS) mundo.c, 

principal.o: principal.c,
	$(CC) $(FLAGS) principal.c,

eventos.o: eventos.c,
	$(CC) $(FLAGS) eventos.c, 

programa.o: programa.c
	$(CC) $(FLAGS) programa.c 

clean:
	rm -f $(OBJS) $(OUT)