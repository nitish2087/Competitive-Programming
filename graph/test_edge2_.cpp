#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>v[],int a,int b){
    v[a].push_back(b);
    v[b].push_back(a);
}

void printGraph(vector<int> v[], int n){
    for(int i=1;i<n+1;i++){
        cout<<"node "<<i<< ": ";
        for(auto j:v[i]){cout<<j<<" ";}
        cout<<endl; 
    }
}

int main(){
    int n,m,a,b,q,a_,b_,c=0;
    cin>>n>>m;
    vector<int> v[n+1];
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        addEdge(v,a,b);
    }
    printGraph(v,n);
    cin>>q;
    while(q--){
        cin>>a_>>b_;

        for(auto i=v[a_].begin();i<=v[a_].end();i++){
            if(*i==b_){
                cout<<"YES"<<endl;
                c=1;
                break;
            }
        }
        if(c==0){
            cout<<"NO"<<endl;
        }
        else c=0;
    }
}