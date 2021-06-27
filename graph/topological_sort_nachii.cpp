#include<bits/stdc++.h>
using namespace std;
//void level_bfs(vector<int>&g ,int start){
//	int n=g.size();
//	cout<<n;
//	bool visited[n];
//}

void topological( vector<int> adj[],int n ){
	vector<int>in_degree(n,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<adj[i].size();j++)
		in_degree[adj[i][j]]++;
	}
	vector<int>result;
	queue<int>q;
	for(int i=0;i<n;i++){
		if(in_degree[i]==0)
			q.push(i);
	}
	while(!q.empty()){
		int v=q.front();
		q.pop();
		//cout<<v<<" ";
		result.push_back(v);
		for(int i=0;i<adj[v].size();i++){
			int neigh=adj[v][i];
			//decrease indegree of neighbors by 1
			in_degree[neigh]--;
			if(in_degree[neigh]==0)
				q.push(adj[v][i]);
		}

	}
	for(int i=0;i<n;i++){
		cout<<result[i]<<" ";
	}
	
	  
}

int main(){
	int n;
	cin>>n;
	vector<int>adj[n];
	int edges;
	cin>>edges;
	for(int i=0;i<edges;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	 
	topological(adj,n);
	return 0;

}