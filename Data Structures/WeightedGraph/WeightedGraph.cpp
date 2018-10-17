#include "DirectedWeightedGraph.h"
#include "VertexType.h"

using namespace std;

int main()
{

	cout << endl;

	DirectedWeightedGraph g;

	VertexType portland("Portland");
	VertexType austin("Austin");
	VertexType chicago("Chicago");
	VertexType dc("DC");
	VertexType houston("Houston");
	VertexType atlanta("Atlanta");
	VertexType nyc("NYC");
	
	g.AddVertex(portland);
	g.AddVertex(austin);
	g.AddVertex(chicago);
	g.AddVertex(dc);
	g.AddVertex(houston);
	g.AddVertex(atlanta);
	g.AddVertex(nyc);

	cout << "Adding vertices to graph..." << endl;
	cout << "1) Portland 2) Austin 3) Chicago 4) DC 5) Houston 6) Atlanta 7) NYC" << endl;

	cout << endl;
	g.printNumVertices();

	g.AddEdge(portland, austin, 100);
	g.AddEdge(portland, chicago, 50);
	g.AddEdge(portland, dc, 150);
	g.AddEdge(dc, houston, 200);
	g.AddEdge(dc, atlanta, 100);
	g.AddEdge(houston, atlanta, 100);
	g.AddEdge(chicago, nyc, 50);
	g.AddEdge(nyc, atlanta, 30);


	cout << endl << "Adding edges between vertices... (see assignment pdf for values)" << endl;

	cout << endl << "Breadth traversal, starting at Portland:" << endl;
	g.BreadthTraverse(portland);
	cout << endl;

	cout << endl << "Deleting DC..." << endl;
	g.DeleteVertex(dc);

	cout << endl;
	g.printNumVertices();

	cout << endl <<  "Breadth traversal, starting at Portland:" << endl;
	g.BreadthTraverse(portland);
	cout << endl << endl;

	
}
