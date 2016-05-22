# An Extremely basic Makefile that I made based off of the professors Makefile
# kytmatsu
# Kyle Matsumoto
CC = gcc
CFLAGS = -g -std=c99


graph04:	graph04.o edgeList.o minPQ.o loadWgtGraph.o 
		${CC} -o graph04 ${CFLAGS} graph04.o edgeList.o minPQ.o loadWgtGraph.o 

minPQ.o:	minPQ.c minPQ.h edgeList.h
		${CC} -c ${CFLAGS} minPQ.c

loadWgtGraph.o:	loadWgtGraph.c loadWgtGraph.h edgeList.h
		${CC} -c ${CFLAGS} loadWgtGraph.c

edgeList.o:	edgeList.c edgeList.h
		${CC} -c ${CFLAGS} edgeList.c

graph04.o:	graph04.c 
		${CC} -c ${CFLAGS} graph04.c

