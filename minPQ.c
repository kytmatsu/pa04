//kytmatsu
//These are all functions given by the book.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "minPQ.h"

struct MinPQNode{
	int numVertices;
	int numPQ;
	int minVertex;
	double oo;
	int *status;
	int *parent;
	double *fringeWgt;
};
// Precondition: A priority Queue.
// Postcondition: an int
int isEmptyPQ(MinPQ pq){
	if(pq->numPQ == 0)
		return 1;
	else
		return 0;

}
// Precondition: A priority Queue.
// Postcondition: an int
int getMin(MinPQ pq){
	if(pq->minVertex == -1){
		double minWgt;
		minWgt = pq->oo;
		for(int x = 1; x <= pq->numVertices;x++)
		{
			if(pq->status[x] == FRINGE){
				if(pq->fringeWgt[x] < minWgt){
					pq->minVertex = x;
					minWgt = pq->fringeWgt[x];
				}
			}
		}
	}
	return pq->minVertex;
}
// Precondition: A priority Queue and an int.
// Postcondition: an int
int getStatus(MinPQ pq, int id){
	return pq->status[id];
}
// Precondition: A priority Queue and an int.
// Postcondition: an int
int getParent(MinPQ pq, int id){
	return pq->parent[id];
}
// Precondition: A priority Queue and an int.
// Postcondition: an int
double getPriority(MinPQ pq, int id){
	return pq->fringeWgt[id];
}
// Precondition: A priority Queue.
// Postcondition: returns nothing but deletes a value
void delMin(MinPQ pq){
if(isEmptyPQ(pq))
{
	printf("Nothing to Delete");
}
else {
	int oldMin = getMin(pq);
	pq->status[oldMin] = INTREE;
	pq->minVertex = -1;
	pq->numPQ --;
}
}
// Precondition: A priority Queue two ints and a double.
// Postcondition: nothing but inserts a value
void insertPQ(MinPQ pq, int id, double priority, int par){
	pq->parent[id] = par;
	pq->fringeWgt[id] = priority;
	pq->status[id] = FRINGE;
	pq->minVertex = -1;
	pq->numPQ ++;
}
// Precondition: A priority Queue two ints and a double.
// Postcondition: nothing
void decreaseKey(MinPQ pq, int id, double priority, int par){
	pq->parent[id] = par;
	pq->fringeWgt[id] = priority;
	pq->minVertex = -1;
}
// Precondition: An int, two int arrays, and a double array.
// Postcondition: a Priority Queue
MinPQ createPQ(int n, int status[], double priority[], int parent[]){
	MinPQ pq = calloc(n+1,sizeof(MinPQ));
	pq->parent = parent;
	pq->fringeWgt = priority;
	pq->status = status;
	for(int x = 1; x <= n+1; x++)
	{
		pq->status[x] = UNSEEN;
	}
	pq->numVertices = n;
	pq->numPQ = 0;
	pq->minVertex = -1;
	pq->oo = INFINITY;
	return pq;
}
