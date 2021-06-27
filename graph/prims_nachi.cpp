#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int >PI;
int prims(int x,int visited[],vector<PI>adj[]){
	PI p;
	//prioroty queue as <weight,neighbor>
	priority_queue<PI,vector<PI>,greater<PI> >Q;
	p=make_pair(0,x);
	Q.push(p);
	
	int min_cost=0;
	while(!Q.empty()){
		p=Q.top();
		Q.pop();
		x=p.second;
		if(visited[x]==true)
		continue;
		 
		min_cost+=p.first;
		visited[x]=true;
		//add unvisited neighbors to priority queue
		for(int i=0;i<adj[x].size();i++){
			int neighbor=adj[x][i].second;
			if(visited[neighbor]==false){
				Q.push(make_pair(adj[x][i].first,neighbor));
			}
		}
	}
	return min_cost;	
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	vector<PI>adj[nodes];
	int weight,x,y;
	for(int i=0;i<edges;i++){
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(weight,y));
		adj[y].push_back(make_pair(weight,x));
	}
	int start;
	cin>>start;
	int visited[nodes]={false};
	int cost=prims(start,visited,adj);
	cout<<cost;
	return 0;
}