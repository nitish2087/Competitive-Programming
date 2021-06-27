#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>v[],int a,int b){
    v[a].push_back(b);
    v[b].push_back(a);
}
void countDfs(vector<int>v[],int s,vector<bool>&visited){
    visited[s]=true;
    for(auto i=v[s].begin();i<v[s].end();i++){
        if(!visited[*i]){
            countDfs(v,*i,visited);
        }
    }
}

int main(){
    int n,m,a,b,x,c=0;
    cin>>n>>m;
    vector<int>v[n+1];
    vector<bool>visited(n+1,false);
    while(m--){
        cin>>a>>b;
        addEdge(v,a,b);
    }
    cin>>x;
    countDfs(v,x,visited);
    for(auto i=visited.begin()+1;i<visited.end();i++){
        if(*i==true){
            c++;
        }
    }
    cout<<(n-c);
    return 0;
}