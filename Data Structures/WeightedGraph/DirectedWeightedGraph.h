#ifndef DIRECTEDWEIGHTEDGRAPH_H
#define DIRECTEDWEIGHTEDGRAPH_H

#include <iostream>
using namespace std;

#include <queue>

//#include "ItemType.h"
#include "VertexType.h"

//enum  MARK { DEFAULT, VISITED, QUEUED };

/*
struct VertexType{
   
       ItemType item;
       MARK mark;        //default mark = DEFAULT; if visited, mark= VISITED; 
                        //if queued, mark = QUEUED;
     
};
*/

class DirectedWeightedGraph{

   public:

        DirectedWeightedGraph();
        DirectedWeightedGraph(int max);

        ~DirectedWeightedGraph();

        bool IsEmpty() const;
        bool IsFull() const;

        void AddVertex(VertexType v);
        void AddEdge(VertexType v1, VertexType v2, int w);
  
        void DeleteVertex(VertexType v);
        void DeleteEdge(VertexType v1, VertexType v2);

        int GetWeight(VertexType v1, VertexType v2);

        bool EdgeExists(VertexType v1, VertexType v2);
        bool VertexExists(VertexType v);

        void Print();

        void MarkVertex(VertexType v, MARK m);//mark whether the vertex has been visited or queued
	void QueueVertex(VertexType v);

        void GetNeighbors(VertexType v, queue<VertexType>& nq);

	void printNumVertices();

	void BreadthTraverse(VertexType v);

	void testPrintEdges();

   private:

        int numberOfVertices;
        int maxVertices;
        
        VertexType * vertices; //save all the vertices

        int edges[25][25];   //save all the edges

        int IndexIs(VertexType v);

};

#endif
