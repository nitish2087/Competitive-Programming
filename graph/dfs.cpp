#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>w[],int u,int v){
	w[u].push_back(v);
	//w[v].push_back(u);
}

void DFSUtil(int i, vector<int> v[],vector<bool> &visited){
	visited[i]=true;
	cout<<i<<" ";
	for(int j=0;j<v[i].size();j++){
		if(visited[v[i][j]]==false){
			DFSUtil(v[i][j],v,visited);
		}
	}
}

void DFS(vector<int> v[],int V){
	vector<bool> visited(V,false);
	for(int i=0;i<V;i++){
		if(visited[i]==false){
			DFSUtil(i,v,visited);
		}
	}
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e,u,v;
		cin>>n>>e;
		vector<int>graph[n];
		for(int i=0;i<e;i++){
			cin>>u>>v;
			addEdge(graph,u,v);

		}
		DFS(graph,n);
		cout<<endl;
	}
	return 0;
}