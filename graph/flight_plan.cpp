#include<bits/stdc++.h>
using namespace std;
int child[1005];
void bfs(vector<int>v[],int x,int y,int n){
	queue<int>q;
	vector<bool>visited(n,false);
	q.push(x);
	visited[x]=true;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(auto i=v[t].begin();i<v[t].end();i++){
			if(!visited[*i]){
				visited[*i]=true;
				child[*i]=t;
				if(*i==y) return;
				q.push(*i);
			}
		}
	}
}

int main(){
	int n,m,t,c,a,b,level=0;
	cin>>n>>m>>t>>c;
	vector<int>v[n+1];
	vector<int>path;
	while(m--){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end());
	}
	int x,y;
	cin>>x>>y;
	bfs(v,x,y,n+1);
	int s=child[y];
	path.push_back(y);
	level++;
	while(s!=x){
		path.push_back(s);
		s=child[s];
		level++;
	}
	path.push_back(x);
	level++;
	cout<<level<<endl;
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i]<<" ";
	}
	return 0;
}
/*
5 5 3 5
1 2
1 3
2 4
1 4
2 5
1 5
*/