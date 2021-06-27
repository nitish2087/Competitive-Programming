#include <bits/stdc++.h>
using namespace std;

bool valid(int r,int c, int i, int j){
    if(i>=0 && i<r && j>=0 && j<c){return true;}
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int r,c;
	    cin>>r>>c;
	    int n=r*c,a[r][c],count=0;
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            cin>>a[i][j];
	        }
	    }
	    queue<pair<int,int>>q;
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            if(a[i][j]==2){
	                q.push(make_pair(i,j));
	            }
	        }
	    }
	    bool temp=false;
	    
	    while(!q.empty()){
	        int size=q.size();
	        while(size--){
	            int i=q.front().first, j=q.front().second;
	            q.pop();
	            if(valid(r,c,i-1,j) && a[i-1][j]==1){
	                a[i-1][j]=2;
	                q.push(make_pair(i-1,j));
	            }
	            if(valid(r,c,i+1,j) && a[i+1][j]==1){
	                a[i+1][j]=2;
	                q.push(make_pair(i+1,j));
	            }
	            if(valid(r,c,i,j-1) && a[i][j-1]==1){
	                a[i][j-1]=2;
	                q.push(make_pair(i,j-1));
	            }
	            if(valid(r,c,i,j+1) && a[i][j+1]==1){
	                a[i][j+1]=2;
	                q.push(make_pair(i,j+1));
	                }
	            }
	        count++;
	    }
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            if(a[i][j]==1){
	                temp=true;
	            }
	        }
	    }
	    if(temp==true){cout<<"-1"<<endl;}
	    else cout<<count-1<<endl;
	    while(!q.empty()) q.pop();
	}
	return 0;
}
