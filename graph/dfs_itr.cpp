#include<bits/stdc++.h>
using namespace std;
//--------iterative--------
/*void dfs(vector<int>v[],int n,int st){
	stack<int>s;
	vector<bool>visited(n,false);
	s.push(st);
	visited[st]=true;
	while(!s.empty()){
		int t=s.top();
		cout<<s.top()<<" ";
		s.pop();
		for(auto i=v[t].begin();i<v[t].end();i++){
			if(!visited[*i]){
				s.push(*i);
				visited[*i]=true;
			}
		}
	}
}*/
//-------recursive--------
void dfs(vector<int>v[],int s,vector<bool>&visited){
	visited[s]=true;
	cout<<s<<" ";
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
	vector<bool>visited(n,false);
	dfs(v,0,visited);
	return 0;
}