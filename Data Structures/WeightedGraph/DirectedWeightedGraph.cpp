#include "DirectedWeightedGraph.h"
#include <queue> 


DirectedWeightedGraph::DirectedWeightedGraph()
{
	numberOfVertices = 0;
	maxVertices = 10;
	vertices = new VertexType[maxVertices]; 

}

DirectedWeightedGraph::DirectedWeightedGraph(int max)
{
	numberOfVertices = 0;
	maxVertices = max;

	vertices = new VertexType[maxVertices]; 

}

DirectedWeightedGraph::~DirectedWeightedGraph()
{
//	delete vertices;
	
}

bool DirectedWeightedGraph::IsEmpty() const
{
	return(numberOfVertices == 0);
}
bool DirectedWeightedGraph::IsFull() const
{
	return(numberOfVertices == maxVertices);
}

void DirectedWeightedGraph::AddVertex(VertexType v)
{
	vertices[numberOfVertices] = v;

	numberOfVertices++;
	

}
void DirectedWeightedGraph::AddEdge(VertexType v1, VertexType v2, int w)
{
	int r, c;

	r = IndexIs(v1);
	c = IndexIs(v2);
	edges[r][c] = w;
}
  
void DirectedWeightedGraph::DeleteVertex(VertexType v)
{

	int index = IndexIs(v);
	vertices[index] = vertices[numberOfVertices-1];

	for(int i = 0; i < numberOfVertices; i++)
	{
		edges[index][i] = 0;
		edges[i][index] = 0;

	}
	for(int i = 0; i < numberOfVertices; i++)
	{
		if(edges[numberOfVertices-1][i] > 0)
			edges[index][i] = edges[numberOfVertices-1][i];
		else if(edges[i][numberOfVertices-1] > 0)
			edges[i][index] = edges[i][numberOfVertices-1];
	}
	for(int i = 0; i < numberOfVertices; i++)
	{
		edges[numberOfVertices-1][i] = 0;
       		edges[i][numberOfVertices-1] = 0;
	}
	
	numberOfVertices--;
	

}
void DirectedWeightedGraph::DeleteEdge(VertexType v1, VertexType v2)
{
	int r, c;

	r = IndexIs(v1);
	c = IndexIs(v2);

	edges[r][c] = 0;

}

int DirectedWeightedGraph::GetWeight(VertexType v1, VertexType v2)
{
	int r, c;

	r = IndexIs(v1);
	c = IndexIs(v2);

	return edges[r][c];

}

bool DirectedWeightedGraph::EdgeExists(VertexType v1, VertexType v2)
{
	int r, c;

	r = IndexIs(v1);
	c = IndexIs(v2);

	return(edges[r][c] > 0);

}
bool DirectedWeightedGraph::VertexExists(VertexType v)
{
	return(IndexIs(v) != -1);
}

void DirectedWeightedGraph::Print()
{
	for(int i = 0; i < numberOfVertices; i++)
	{
		vertices[i].printValue();
		cout << " ";
	}
}


void DirectedWeightedGraph::QueueVertex(VertexType v)
{
	v.Queue();
}

void DirectedWeightedGraph::GetNeighbors(VertexType v, queue<VertexType>& neighbors)
{
	int index = IndexIs(v);
	for (int i = 0; i < numberOfVertices; i++)
	{

		if((edges[index][i] > 0) && vertices[i].getMark() != QUEUED)
		{
			(vertices[i]).setMark(QUEUED);

			neighbors.push(vertices[i]);
			(vertices[i]).setMark(QUEUED);
		}
	}
}

int DirectedWeightedGraph::IndexIs(VertexType v)
{
	int i = 0;
	while(vertices[i] != v)
	{
		if (i > maxVertices)
			return -1;
		i++;
	}
	return i;
}

void DirectedWeightedGraph::printNumVertices()
{

	cout << "There are " << numberOfVertices << " vertices in this graph" << endl;
}

void DirectedWeightedGraph::BreadthTraverse(VertexType v)
{
	for (int i = 0; i < numberOfVertices; i++)
	{
		vertices[i].setMark(DEFAULT);
	}
	MARK visit = VISITED;
	queue<VertexType> neighbors;

	v.setMark(QUEUED);

	neighbors.push(v);
	GetNeighbors(v, neighbors);

	while(!neighbors.empty())
	{
		neighbors.front().printValue();
		cout << " "; 
		neighbors.front().setMark(VISITED);
		GetNeighbors(neighbors.front(), neighbors);
		neighbors.pop();

	}
	
}
//mark whether the vertex has been visited or queued
void DirectedWeightedGraph::MarkVertex(VertexType v, MARK m)
{
	v.setMark(m);
}

void DirectedWeightedGraph::testPrintEdges()
{

	for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            std::cout << edges[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
