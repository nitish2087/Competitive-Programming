#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t,c;
    cin>>n>>m>>t>>c;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bool visited[n+1]={false};
    vector<pair<int,int> >cost(n+1,pair<int,int>(0,0));
    
    int x,y;
    cin>>x>>y;

    queue<int >q;
    q.push(x);
    visited[x]=true;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        vector<int>arr;
        for(int i=0;i<adj[v].size();i++){
                arr.push_back(adj[v][i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<adj[v].size();i++){
            int neighbor=arr[i];
            if(!visited[neighbor]){
                visited[neighbor]=true;
                int waiting=cost[v].first%t;
                if(waiting!=0){
                    waiting=(t-waiting)%t;
                }
                
                cost[neighbor].first=cost[v].first+waiting +c;
                q.push(neighbor);
                cost[neighbor].second=v;
            }
        }
    }
    vector<int>ans;
    int i=y;
    ans.push_back(i);
    while(i!=x){
        i=cost[i].second;
        ans.push_back(i);
    }
     
    int s=ans.size();
    cout<<s<<endl;
    for(int i=s-1;i>=0;i--)
    cout<<ans[i]<<" ";
    return 0;
}