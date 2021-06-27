#include<bits/stdc++.h>
using namespace std;

bool isValid(int **v,bool visited[][100],int i,int j,int n,int m){
	return (i>=0 && i<n && j>=0 && j<m && v[i][j] && !visited[i][j]);
}

void dfs(int **v,bool visited[][100],int i,int j,int n,int m){
	static int row_n[]={-1,0,1,0};
	static int col_n[]={0,1,0,-1};
	visited[i][j]=true;
	for(int k=0;k<4;k++){
		if(isValid(v,visited,i+row_n[k],j+col_n[k],n,m) && v[i][j]==v[i+row_n[k]][j+col_n[k]]){
			dfs(v,visited,i+row_n[k],j+col_n[k],n,m);
		}
	}
}

void color(int **v,int n,int m,int i,int j,int k){
	bool visited[100][100];
	memset(visited,false,sizeof(visited));
	if(!visited[i][j]){
		dfs(v,visited,i,j,n,m);
	}
	for(int p=0;p<n;p++){
		for(int q=0;q<m;q++){
			if(visited[p][q]==true){
				v[p][q]=k;
			}
		}
	}
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
		int x,y,k;
		cin>>x>>y>>k;
		color(v,n,m,x,y,k);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<v[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}