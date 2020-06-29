#include<bits/stdc++.h>
using namespace std;
const int MAX=1e4+5;
pair<int,pair<int,int>>p[MAX];

int root(vector<int>&v,int i){
	while(v[i]!=i){
		i=v[i];
	}
	return i;
}

void Union(vector<int>&v,int a,int b){
	int root_a=root(v,a);
	int root_b=root(v,b);
	v[root_a]=root_b;
}


int kruskal(vector<int>&v,pair<int,pair<int,int>>p[],int m){
	int x,y,cost,min_cost=0;
	for(int i=0;i<m;i++){
		x=p[i].second.first;
		y=p[i].second.second;
		cost=p[i].first;
		if(root(v,x)!=root(v,y)){
			min_cost+=cost;
			Union(v,x,y);
		}
	}
	return min_cost;
}

int main(){
	int n,m,weight,a,b;
	cin>>n>>m;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		v[i]=i;
	}
	for(int i=0;i<m;i++){
		cin>>a>>b>>weight;
		p[i]=make_pair(weight,make_pair(a,b));
	}
	sort(p,p+m);
	cout<<kruskal(v,p,m);
	return 0;
}
/*
test input:
5 6
0 1 3
0 4 2
1 4 1
1 2 2
2 3 3
3 4 2
*/