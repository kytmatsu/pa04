kytmatsu
pa04

This is my README for resubmission.
The purpose of this assignment is to implement both a Prim's spanning tree algorithm and a Dijkstra's Shortest Path algorithm.
I am submitting graph04.c loadWgtGraph.c loadWgtGraph.h minPQ.c minPQ.h
edgeList.c edgeList.h Makefile test0.in test01.in and README.txt.

I found the bug. It works now. 

LoadWgtGraph.c is contains parseEdges which essentially is just a combination of loadGraph and parse. This is where I seperate directed and undirected graphs.

graph04.c is the main function of the program. It contains happytree and updateFringe as well as the printing of everything.

All of my .h files are just header files that make everything work nicely.

minPQ.c contains the functionality of the priority queue. It is pretty much a direct translation of java to c from the book (like most of the program). 
To use Makefile type in: 
make graph04
and it will automatically compile all of the other files that are necessary for graph04 to run.
 
A CALL TO GRAPH04 MUST BE GIVEN 3 ARGS in the format:
graph04 -(D/P) (vertex start) fileName
		-Or-
graph04 -(D/P) (vertex start) -
for standard input.

This program was mainly just translating the java code to c. 
All functions necessary to the program were added after reading through them in the book.
My print function is probably a little unique, and not in the good way. It's copied over from pa01.
test0.in is a test file that I made to look like the undirected graph on the midterm review.
It was immensely helpful in helping me understand the program.
NOTE: THIS CANNOT BE GIVEN TO DIJKSTRA'S WITHOUT A VERTEX STARTING AT 1. 
It is normally unable to traverse the undirected graph at all, however, the
way I input the data allows it to run through Dijkstra's at vertex 1 of this
graph ONLY.
Dijkstra's only covers directed graphs in my program and when given an
undirected graph it does not correctly form the edges of the undirected graph.
This leads to the program being unable to run to many(if any) vertices.

test01.in is the directed graph for the shortest path's algorithm on the
midterm review.
This one shows that dijkstra's works with a directed graph when given the
directed graph
It'll still add the edges the same either way, but the
undirected graph will cause the program to display something funky.
If you start at a vertex other than 1 on this graph, there will be some unseen
nodes. 
You can't get to A other than by started at it so yea.
This one probably shouldn't be given to Prim's because it'll create a ton of
edges.
Hopefully. Otherwise I studied wrong for the midterm, because it was 
the same answer I came up with on my practice midterm.
This can be given to either program, but again, probably better to not
give it to Prim's algorithm.
