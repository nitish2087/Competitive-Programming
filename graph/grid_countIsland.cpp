#include<bits/stdc++.h>
using namespace std;

bool isValid(int **v,bool visited[][100],int i,int j,int n,int m){
	return (i>=0 && i<n && j>=0 && j<m && v[i][j] && !visited[i][j] );
}

void dfs(int **v,bool visited[][100],int i,int j,int n,int m){
	static int row_n[]={-1,-1,-1,0,0,1,1,1};
	static int col_n[]={-1,0,1,-1,1,-1,0,1};
	visited[i][j]=true;
	for(int k=0;k<8;k++){
		if(isValid(v,visited,i+row_n[k],j+col_n[k],n,m)){
			dfs(v,visited,i+row_n[k],j+col_n[k],n,m);
		}
	}
}

int countIsland(int **v,int n,int m){
	bool visited[100][100];
	int c=0;
	memset(visited,false,sizeof(visited));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]==1 && !visited[i][j]){
				dfs(v,visited,i,j,n,m);
				c++;
			}
		}
	}
	return c;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int **v;
		v = new int *[n];
		for(int i=0;i<n;i++){
			v[i] =new int[m];
			for(int j=0;j<m;j++){
				cin>>v[i][j];
			}
		}
		cout<<countIsland(v,n,m);
	}
	return 0;
}