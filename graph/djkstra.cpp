#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

void djkstra(vector<pi>v[],int n,int s){
	priority_queue<pi,vector<pi>,greater<pi>> q;
	q.push(make_pair(0,s));
	vector<int>distance(n,10000);
	distance[s]=0;
	while(!q.empty()){
		int t=q.top().second;
		q.pop();
		for(auto i=v[t].begin();i<v[t].end();i++){
			if(distance[(*i).first]>distance[t]+(*i).second){
				distance[(*i).first]=distance[t]+(*i).second;
				q.push(make_pair(distance[(*i).first],(*i).first));
			}
		}
	}
	for(auto i:distance){
		cout<<i<<" ";
	}
}

int main(){
	int n,m,a,b,weight;
	cin>>n>>m;
	vector<pi>v[n];
	while(m--){
		cin>>a>>b>>weight;
		v[a].push_back(make_pair(b,weight));
		v[b].push_back(make_pair(a,weight));
	}
	djkstra(v,n,0);
	return 0;
}
/*
5 6
0 1 1
0 2 2
1 3 1
2 3 1
2 4 3
3 4 1
*/