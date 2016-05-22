//kytmatsu
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "edgeList.h"
#include "loadWgtGraph.h"


//This is a file from the Professor that I modified to check if the
//the the number was greater than the size we were given.
//It combines two of the files we were given.
//precondition: give it a char pointer, edgelist, integer,and a char.
//postcoditions: It'll spit out the edgelists all formed 
void parseEdges(char *line, EdgeList aVert[], int arrSize, char task) {
	EdgeInfo newE;
	int numFields;
	int from;
	numFields = sscanf(line, "%d %d %lf %*s", &from, &(newE.to), &(newE.wgt));
	if (numFields < 2 || numFields > 3) {
		printf("Bad Edge: %s\n", line);
		exit(1);
	}

	if (from > arrSize) {
		printf("Number exceeds n, Number is too large: %s\n", line);
		from = 0;
		newE.to = 0;
	}

	if (numFields == 3) {
		// make a case for each graph, undirected or directed.
		if(task == 'P'){
		// Prim's will be an undirected graph so we add the 
		// edge given then reverse that edge and add it the opposite way
		// This ensures that the edge can go both ways.
			EdgeInfo holder;
			aVert[from] = edgeCons(newE, aVert[from]);
			holder.wgt = newE.wgt;
			holder.to = from;
			aVert[newE.to] = edgeCons(holder,aVert[newE.to]);
		}
		else if (task == 'D')
		// Dijkstra's wo;; be a directed graph so just add whatever edge
		// it is given. This is all we need to do since we are given 
		// the data as a directed graph.
			aVert[from] = edgeCons(newE,aVert[from]);
	}
}
