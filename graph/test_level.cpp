#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>v[],int a,int b){
	v[a].push_back(b);
	v[b].push_back(a);
}

void bfsLevel(vector<int>v[],int s,int p,int n){
	vector<bool>visited(n,false);
	int c=0;
	int level[n];
	queue<int>q;
	q.push(s);
	level[s]=1;
	visited[s]=true;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(auto i=v[t].begin();i<v[t].end();i++){
			if(!visited[*i]){
				level[*i]=level[t]+1;
				if(level[*i]==p){c++;}
				q.push(*i);
				visited[*i]=true;
			}
		}
	}
	cout<<c;
}
int main(){
	int n,a,b,q;
	cin>>n;
	vector<int>v[n+1];
	int t=n-1;
	while(t--){
		cin>>a>>b;
		addEdge(v,a,b);
	}
	cin>>q;
	bfsLevel(v,1,q,n+1);
	return 0;
}