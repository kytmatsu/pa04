//kytmatsu
#include <stdlib.h>
#include "edgeList.h"

const EdgeList edgeNil = NULL;

struct EdgeListNode{
	EdgeInfo node;
	EdgeList next;
};

EdgeInfo edgeFirst(EdgeList oldL){
	return oldL->node;
}

EdgeList edgeRest(EdgeList oldL){
	return oldL->next;
}

EdgeList edgeCons(EdgeInfo newE, EdgeList oldL){
	EdgeList x = malloc(sizeof(EdgeList));
	x->node = newE;
	x->next = oldL;
	return x;
}
