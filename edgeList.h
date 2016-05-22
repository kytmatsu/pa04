/* edgeList.h
 * The purpose of this file is to denote the programs used in edgeList.c.
 */

#ifndef C101EdgeList
#define C101EdgeList
/* Multiple typedefs for the same type are an error in C. */

typedef struct EdgeListNode * EdgeList;

typedef struct EdgeInfoStruct
    {
    int to;
    double wgt;
    }
    EdgeInfo;

/** edgeNil denotes the empty EdgeList */
extern const EdgeList edgeNil;

/* Access functions
 * (what are the preconditions?)
 */

/** first
 * The preconditions are a previous EdgeList that will be passed to it.
*/
EdgeInfo edgeFirst(EdgeList oldL);

/** rest
 * The preconditions are the same as edgeFirst, that a previous EdgeList 
 * will be passed to it.
*/
EdgeList edgeRest(EdgeList oldL);

/* Constructors
 * (what are the preconditions and postconditions?)
 */

/** cons
 * The preconditions are an EdgeInfo new edge, and an EdgeList old List.
 * The postconditions are that it returns a new EdgeList.
*/
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL);

#endif

