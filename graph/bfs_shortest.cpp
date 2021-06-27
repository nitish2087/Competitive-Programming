#include<bits/stdc++.h>
using namespace std;

void bfs_0_1(vector<pair<int,int>>v[],int s,int n){
	deque<int>q;
	q.push_back(s);
	vector<int>distance(n,10000);
	distance[s]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop_front();
		for(int i=0;i<v[t].size();i++){
			if(distance[v[t][i].second]>distance[t]+v[t][i].first){
				distance[v[t][i].second]=distance[t]+v[t][i].first;
				if(v[t][i].first==1){
					q.push_front(v[t][i].second);
				}
				else
					q.push_back(v[t][i].second);
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<distance[i] <<" ";
	}
}

int main(){
	int n,m,a,b;
	cin>>n>>m;
	vector<pair<int,int>>v[n];
	while(m--){
		cin>>a>>b;
		v[a].push_back(make_pair(1,b));
		v[b].push_back(make_pair(1,a));
	}
	bfs_0_1(v,0,n);
	return 0;
}
/*
5 6
0 1
0 4
1 4
1 2
2 3
3 4
*/