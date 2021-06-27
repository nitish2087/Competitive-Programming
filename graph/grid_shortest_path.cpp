#include<bits/stdc++.h>
using namespace std;

bool isValid(char **v,bool visited[][100],int i,int j,int n,int m){
	return (i>=0 && i<n && j>=0 && j<m && (v[i][j]=='*' || v[i][j]=='d') && !visited[i][j]);
}

int shortestPath(char **v,int n,int m,int s_x,int s_y,int d_x,int d_y){
	queue<char>q;
	bool visited[100][100];
	memset(visited,false,sizeof(visited));
	
	vector<vector<int>>level(n,vector<int>(n,-1));

	q.push(v[s_x][s_y]);
	level[s_x][s_y]=0;

	static int row_n[]={-1,0,1,0};
	static int col_n[]={0,1,0,-1};
	visited[s_x][s_y]=true;
	int x=s_x;
	int y=s_y;
	while(!q.empty()){
		q.pop();
		for(int k=0;k<4;k++){
			if(isValid(v,visited,x+row_n[k],y+col_n[k],n,m)){
				level[x+row_n[k]][y+col_n[k]]=level[x][y]+1;
				x=x+row_n[k];
				y=y+col_n[k];
				q.push(v[x][y]);
				visited[x][y]=true;
			}
		}
	}
	return level[d_x][d_y];
}

int main(){
	int n,m;
	cin>>n>>m;
	char **v;
	int s_i,s_j,d_i,d_j;
	v=new char *[n];
	for(int i=0;i<n;i++){
		v[i]=new char[m];
		for(int j=0;j<m;j++){
			cin>>v[i][j];
			if(v[i][j]=='s'){
				s_i=i;
				s_j=j;
			}
			if(v[i][j]=='d'){
				d_i=i;
				d_j=j;
			}
		}
	}
	cout<<shortestPath(v,n,m,s_i,s_j,d_i,d_j);
	return 0;
}
/*
4 4
0 * 0 s
* 0 * *
0 * * *
d * * *

4 4
0 * 0 s
* 0 * *
0 * * *
d 0 0 0
*/