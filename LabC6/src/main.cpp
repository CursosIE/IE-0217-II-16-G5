#include <cstdlib>
#include "Node.h"
#include "Graph.h"
#include <queue>
#define NL cout << endl;
#define SP " "

using namespace std;

int main(int argc, char** argv) {

	int size=10;
    Node<int> _1;
    _1.D=1;
    Node<int> _2;
    _2.D=2;
    Node<int> _3;
    _3.D=3;
    Node<int> _4;
    _4.D=4;
    Node<int> _5;
    _5.D=5;
    Node<int> _6;
    _6.D=6;
    Node<int> _7;
    _7.D=7;
    Node<int> _9;
    _9.D=9;
    Node<int> _10;
    _10.D=10;
    Node<int> _11;
	_11.D=11;
	Node<int>* vert=new Node<int>[1];
	bool** edges = new bool*[size+1];
	for(int i=0; i<size; i++){
			edges[i] = new bool[size+1];
			}
	edges[0][0]=false;
	vert[0]=_1;
	Graph<int>* T = new Graph<int>();
	T->vertex=vert;
	T->size=1;
	T->edges=edges;
	T->addvert(_5);
	T->addvert(_7);
	T->addvert(_1);
	T->addvert(_4);
	T->addvert(_6);
	T->addedge(2,3);
	T->addedge(4,0);
	T->addedge(0,2);
	T->addedge(2,3);
	T->addedge(4,5);
	T->addedge(1,3);
	~*T;
	queue<int> cola;
	cola.push(2);
	cola.push(5);
	cola.pop();
	bool* g = new bool[4];
	g[0]=true;
	g[1]=false;
	g[2]=false;
	g[3]=false;
	//cout<<T->adjuv(3, g)<<endl;
	//cout<<T->adjuv(0, g)<<endl;
	T->dfs();
	T->bfs();
	//cout<<T->arist[1][1].D<<endl;
    return 0;
}

