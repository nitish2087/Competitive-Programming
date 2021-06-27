#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;

int prims(vector<PI>v[],vector<bool>&visited,int s){
	PI p;
	priority_queue<PI,vector<PI>,greater<PI>> q;
	p=make_pair(0,s);
	q.push(p);
	int min_cost=0;
	while(!q.empty()){
		p=q.top();
		q.pop();
		s=p.second;
		if(visited[s]==true) continue;
		min_cost+=p.first;
		visited[s]=true;
		for(auto i=v[s].begin();i<v[s].end();i++){
			if(!visited[(*i).second]){
				q.push(make_pair((*i).first,(*i).second));
			}
		}
	}
	return min_cost;
}

int main(){
	int n,m,a,b,weight;
	cin>>n>>m;
	vector<PI>v[n];
	while(m--){
		cin>>a>>b>>weight;
		v[a].push_back(make_pair(weight,b));
		v[b].push_back(make_pair(weight,a));
	}
	vector<bool>visited={false};
	cout<<prims(v,visited,0);
	return 0;
}