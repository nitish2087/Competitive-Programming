#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a,b,weight;
	cin>>n>>m;
	pair<int,pair<int,int>>p[m];
	for(int i=0;i<m;i++){
		cin>>a>>b>>weight;
		p[i]=make_pair(weight,make_pair(a,b));
	}
	vector<int>distance(n,10000);
	distance[0]=0;
	int t=n-1;
	while(t--){
		for(int i=0;i<m;i++){
			int x=p[i].second.first;
			int y=p[i].second.second;
			int w=p[i].first;
			if(distance[x]+w<distance[y]){
				distance[y]=distance[x]+w;
			}
		}
	}
	for(int i=0;i<n;i++){cout<<distance[i]<<" ";}
	return 0;
}
/*
5 6
0 1 1
0 2 2
1 3 2
2 3 1
2 4 4
3 4 3
*/