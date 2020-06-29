#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>v[],int s,vector<bool>&visited){
	visited[s]=true;
	for(auto i=v[s].begin();i<v[s].end();i++){
		if(!visited[*i]){
			dfs(v,*i,visited);
		}
	}
}


int main(){
	int n,m,a,b;
	cin>>n>>m;
	vector<int>v[n];
	while(m--){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int c=0;
	vector<bool>visited(n,false);
	for(int i=1;i<=n;i++){
		if(visited[i]==false){
			dfs(v,i,visited);
			c++;
		}
	}
	cout<<"components: "<<c;
	return 0;
}