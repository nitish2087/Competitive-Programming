#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> w[], int u, int v) {
	// undirected graph: add edges u->v & v->u 
	w[u].push_back(v);
	w[v].push_back(u);
}

void printGraph(vector<int> v[], int n) {
	for (int i = 0; i < n; i++) {
		cout<<"node "<<i<< ": ";
		for (auto j : v[i]) { cout<<j<<" "; }
		cout<<endl;	
	}
}

int main()
{
	int n = 5; //nodes
	vector<int> v[n];
	addEdge(v, 0, 1);
	addEdge(v, 1, 2);
	addEdge(v, 2, 3);
	addEdge(v, 3, 4);
	addEdge(v, 4, 0);
	addEdge(v, 0, 2);
	printGraph(v, n);
	return 0;
}
