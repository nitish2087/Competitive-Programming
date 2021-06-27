#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m,a,b,q,a_,b_,c=0;
    cin>>n>>m;
    int v[n+1][n+1]={0};
    
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a][b]=1;
    }
    cin>>q;
    while(q--){
        cin>>a_>>b_;
        if(v[a_][b_]==1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}