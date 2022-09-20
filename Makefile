OBJS	= geo.o id.o structure.o fileout.o distance.o outils.o graphe.o kruskal.o main.o
SOURCE	= geo.c id.c structure.c fileout.c distance.c outils.c graphe.c kruskal.c main.c
HEADER	= geo.h id.h structure.h fileout.h distance.h outils.h graphe.h kruskal.h
OUT	= main
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

geo.o: geo.c
	$(CC) $(FLAGS) geo.c 

id.o: id.c
	$(CC) $(FLAGS) id.c 

structure.o: structure.c
	$(CC) $(FLAGS) structure.c 

fileout.o: fileout.c
	$(CC) $(FLAGS) fileout.c 

distance.o: distance.c
	$(CC) $(FLAGS) distance.c 

outils.o: outils.c
	$(CC) $(FLAGS) outils.c 

graphe.o: graphe.c
	$(CC) $(FLAGS) graphe.c 

kruskal.o: kruskal.c
	$(CC) $(FLAGS) kruskal.c 

main.o: main.c
	$(CC) $(FLAGS) main.c 


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)
