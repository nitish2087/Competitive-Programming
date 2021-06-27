#include<bits/stdc++.h>
using namespace std;

bool isValid(int **v,bool visited[][30],int i,int j,int n,int m){
	return (i>=0 && i<n && j>=0 && j<m && (v[i][j]==3 || v[i][j]==2) && !visited[i][j]);
}

void dfs(int **v,bool visited[][30],int i,int j,int n,int m){
	static int row_n[]={-1,0,1,0};
	static int col_n[]={0,1,0,-1};
	visited[i][j]=true;
	for(int k=0;k<4;k++){
		if(isValid(v,visited,i+row_n[k],j+col_n[k],n,m)){
			dfs(v,visited,i+row_n[k],j+col_n[k],n,m);
		}
	}
}

bool pathExists(int **v,int n,int m,int s_x,int s_y,int d_x,int d_y){
	bool visited[30][30];
	memset(visited,false,sizeof(visited));
	dfs(v,visited,s_x,s_y,n,m);
	return visited[d_x][d_y];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,s_i,s_j,d_i,d_j;
		cin>>n;
		int **v;
		v=new int *[n];
		for(int i=0;i<n;i++){
			v[i]=new int[n];
			for(int j=0;j<n;j++){
				cin>>v[i][j];
				if(v[i][j]==1){
					s_i=i;
					s_j=j;
				}
				if(v[i][j]==2){
					d_i=i;
					d_j=j;
				}
			}
		}
		cout<<pathExists(v,n,n,s_i,s_j,d_i,d_j)<<endl;
	}
	return 0;
}
/*
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0
*/