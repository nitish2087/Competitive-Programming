#include<bits/stdc++.h>
using namespace std;

int minCost(int **v,int a,int b){
	if(a<0||b<0) return INT_MAX;
	if(a==0&&b==0) return v[a][b];
	return v[a][b]+min(min(minCost(v,a-1,b),minCost(v,a,b-1)),minCost(v,a-1,b-1));
}

int main(){
	int n,m;
	cin>>n>>m;
	int **v=new int *[n];

	for(int i=0;i<n;i++){
		v[i]= new int[m];
		for(int j=0;j<m;j++)
			cin>>v[i][j];
	}
	int a,b;
	cin>>a>>b;
	cout<<minCost(v,a,b);
	return 0;
}