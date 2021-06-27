#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int e;
	cin>>e;
	vector<pair<int,int>>edges[n];
	while(e--){
		int a,b;
		cin>>a>>b;
		edges[a].push_back(make_pair(b,1));
		edges[b].push_back(make_pair(a,1));
	}
	int start;
	cin>>start;
 	vector<int>distance(n,10000);
	distance[start]=0;
	deque<int>q;
	q.push_back(start);
	while(!q.empty()){
		int v=q.front();
		q.pop_front();
		for(int i=0;i<edges[v].size();i++){
			int neighbour=edges[v][i].first;
			int neighbour_distance=distance[neighbour];

			if(neighbour_distance>distance[v]+edges[v][i].second){
				distance[edges[v][i].first]=distance[v]+edges[v][i].second;
				if(edges[v][i].second==1){
					q.push_front(edges[v][i].first);
    			}
    			else{
    				q.push_back(edges[v][i].first);
    			}
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<distance[i] <<" ";
	}
	return 0;
}
/*
5 6
0 1 1
0 4 1
1 4 1
1 2 1
2 3 1
3 4 1
*/