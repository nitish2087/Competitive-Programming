#include<bits/stdc++.h>
using namespace std;

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

bool cycleDetect(vector<int>&v,pair<int,int>p[],int m){
	int x,y;
	for(int i=0;i<m;i++){
		x=p[i].first;
		y=p[i].second;
		if(root(v,x)==root(v,y)){
			return true;
		}
		else Union(v,x,y);
	}
	return false;
}
int main(){
	int n,m,a,b;
	cin>>n>>m;
	vector<int>v(n);
	pair<int,int>p[n];
	for(int i=0;i<n;i++){
		v[i]=i;
	}
	for(int i=0;i<m;i++){
		cin>>a>>b;
		p[i]=make_pair(a,b);
	}
	bool c=cycleDetect(v,p,m);
	if(c==true){
		cout<<"there's a cycle !!!";
	}
	else cout<<"there's no cycle";
	return 0;
}