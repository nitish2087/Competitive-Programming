#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a,b,weight;
	cin>>n>>m;
	vector<vector<int>>distance(n,vector<int>(n,0));
	while(m--){
		cin>>a>>b>>weight;
		distance[a][b]=weight;
		distance[b][a]=weight;
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<distance[i][j]<<" ";
		}
		cout<<endl;
	}
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