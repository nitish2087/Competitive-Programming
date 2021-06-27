#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>v[],vector<bool>&visited,int s){
	if(visited[s]) return true;
	visited[s]=true;
	bool t=false;
	for(auto i=v[s].begin();i<v[s].end();i++){
		if(visited[*i]){
			return true;
		}
		else 
			t=dfs(v,visited,*i);
	}
	visited[s]=false;
	return t;
}

bool isCyclic(vector<int>v[],int n){
	vector<bool>visited(n,false);
	bool cycle=false;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			cycle=dfs(v,visited,i);
			if(cycle){
				break;
			}
		}
	}
	return cycle;
}

int main(){
	int n,m,a,b;
	cin>>n>>m;
	vector<int>v[n];
	while(m--){
		cin>>a>>b;
		v[a].push_back(b);
	}
	cout<<isCyclic(v,n);
	return 0;
}
/*
2 2
0 1 0 0
4 3
0 1 1 2 2 3
4 3
0 1 2 3 3 2
*/