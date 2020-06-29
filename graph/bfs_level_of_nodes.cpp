#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int>v[],int s,int n){
    vector<bool>visited(n,false);
    queue<int>q;
    int level[n];
    q.push(s);
    level[s]=0;
    visited[s]=true;
    while(!q.empty()){
        int t=q.front();
        cout<<t<<" ";
        q.pop();
        for(auto i=v[t].begin();i<v[t].end();i++){
            if(!visited[*i]){
                q.push(*i);
                level[*i]=level[t]+1;
                visited[*i]=true;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<level[i]<<" ";
    }
}

int main() {
	int n,m,a,b;
	cin>>n>>m;
	vector<int>v[n];
	while(m--){
	    cin>>a>>b;
	    v[a].push_back(b);
	    v[b].push_back(a);
	}
	bfs(v,0,n);
	return 0;
}
/*
test input:
5 6
0 1
0 4
1 4
1 2
2 3
3 4
*/