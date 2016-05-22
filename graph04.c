// This is the functionality of the program.
// It does everything required  of it. Except code was changed to add directed 
// and undirected graphs 
// kytmatsu
// Kyle Matsumoto
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "edgeList.h"
#include "loadWgtGraph.h"
#include "minPQ.h"
#define maxSIZE 1024
#define strEq(s1,s2) (!strcmp((s1),(s2)))

// code I wrote according to the script in the book
// Preconditions: a priority queue, an edgelist, and int for the weight, and a task to signify which
// we use Prim or Dijkstra
// Postconditions: it won't return anything but it'll update our vertex's.
void updateFringe(MinPQ pq, EdgeList adjInfoOfV, int id, char task){
	if(task == 'D')
	{
		double myDist;
		myDist = getPriority(pq,id);
		EdgeList remAdj;
		remAdj = adjInfoOfV;
		while (remAdj != edgeNil)
		{
			EdgeInfo wInfo;
			wInfo = edgeFirst(remAdj);
			int w = wInfo.to;
			double newDist = (myDist + wInfo.wgt);
			if(getStatus(pq,w) == UNSEEN){
				insertPQ(pq, w, newDist, id);
			}
			else if(getStatus(pq,w) == FRINGE){
				if(newDist < getPriority(pq,w)){
					decreaseKey(pq, w, newDist, id);
				}
			}
			remAdj = edgeRest(remAdj);
		}
	}
	else if(task == 'P'){
		EdgeList remAdj;
		remAdj = adjInfoOfV;
		while (remAdj != edgeNil)
		{
			EdgeInfo wInfo = edgeFirst(remAdj);
			double nWgt = wInfo.wgt;
			int w = wInfo.to;
			if(getStatus(pq,w) == UNSEEN){
				insertPQ(pq, w, nWgt, id);
			}
			else if(getStatus(pq,w) == FRINGE){
				if(nWgt < getPriority(pq,w)){
					decreaseKey(pq, w, nWgt, id);
				}
			}
			remAdj = edgeRest(remAdj);
		}
	}
}

// code I wrote according to the script in the book
// Precondition: Needs an edgelist pointerm two ints n and s, a int pointer, a double pointer and a char
// Postcondition: It'll update our graph's status when done.
void greedyTree(EdgeList *adjInfo, int n, int s, int *status, int *parent, double *fringeWgt, char task){
	MinPQ pq = createPQ(n, status,fringeWgt,parent);
	insertPQ(pq,s,0,-1);
	while(!isEmptyPQ(pq)){
		int v = getMin(pq);
		delMin(pq);
		updateFringe(pq,adjInfo[v],v,task);
	}

}
// Prints out the output in a nice orderly fashion, regardless of size(hopefully
//precondition: an int, pointer to an edgelist, char, another int, pointer to an
//int, pointer to a double, and another pointer to an int.
//postcondition: It'll have printed out in nice format all of the information
//for the graph and a message saying which algorithm was used.
void printOutput(int n, EdgeList *adjInfo, char task, int s, int *status, int * parent, double *fringeWgt){
	int x;
	if(task == 'P'){
		printf("Prim's algorithm started at %d\n", s);
	}
	else if (task == 'D'){
		printf("Dijkstra's algorithm started at %d\n", s);
	}
	printf(" %10s %10s %10s %10s\n","Vertex", "Status", "Priority", "Parent");
	for(x = 1; x <=n; x++){
		printf(" %10d %10c %10lf %10d\n", x, status[x], fringeWgt[x], parent[x]);
	}
}

int main(int argc, char* argv[]) {
	FILE* input;
	char task;
	int s = 0;
	if (argc < 4){
		printf("Must be at least 3 arguments\n");
		return 1;
	}

	if(strEq(argv[1], "-D"))
		task = 'D';

	else if(strEq(argv[1], "-P"))
		task = 'P';

	if (argc > 1) {
		if(!strcmp(argv[3],"-")) {
			input = stdin;
		}
		else{
			//Open File
			char *myFile = argv[3];
			input = fopen(myFile, "r");
			if (input == NULL) {
				fprintf(stderr, "ERROR: FILE DOES NOT EXIST\n");
				return(0);
			}
		}
	}
	else{
		input = stdin;
	}
	//Get the size of our index from the first line
	char line[maxSIZE];
	int index;
	fgets(line, sizeof(line), input); //Read in first line 
	sscanf(line, "%d %*s",  &index); //get the number n of index from first line
	sscanf(argv[2],"%d",&s); // get our starting vertex

	//Create the EdgeList that will have the data in it at the size of the index
	// Also initialize our variables for use later in the program in happyTree and printOutput.
	EdgeList *adjInfo = malloc(sizeof(EdgeList)*(index+1));
	double *fringeWgt = malloc(sizeof(double)*(index+1));
	int *status = malloc(sizeof(int)*(index+1));
	int *parent = malloc(sizeof(int)*(index+1));
	int start;
	for(start = 1; start <= index; start++) {
		adjInfo[start] = edgeNil;
	}
	// variable to count m
	int countIt = 0;

	//Read each line until the end of file and save it
	while (fgets(line, sizeof(line), input)) {
		countIt++;
		parseEdges(line, adjInfo, index, task);
	}
	// We've gotten the data now we print it.
	printf("n = %d\n", index);
	printf("m = %d\n", countIt);
	for(int count = 1; count <= index; count++) {
		bool start = true;
		EdgeList t = adjInfo[count];
		printf("%d  ", count);
		if(!t) {
			// If theres nothing in the file for that slot print a Null
			printf("Null\n");
		}
		// Start printing out the Lists. If more than one entry it
		// will print out a comma to seperate them
		while(t) {
			if(start == true) {
				printf("[");
			} else {
				printf(", ");
			}
			printf("%d", edgeFirst(t));
			t = edgeRest(t);
			start = false;
		}
		if(start == false) {
			printf("]\n");
		}
	}
	greedyTree(adjInfo, index, s, status, parent, fringeWgt, task);
	printOutput(index, adjInfo, task, s, status, parent, fringeWgt);
	fclose(input);
	return 0;
}
