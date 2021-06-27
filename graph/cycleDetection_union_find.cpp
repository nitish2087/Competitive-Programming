#include<bits/stdc++.h>
using namespace std;

int root(vector<int>&v,int i){
    while(v[i]!=i){
        i=v[i];
    }
    return i;
}

void Union(vector<int>&v,int a,int b){
    int root_a=root(v,a);
    int root_b=root(v,b);
    v[root_a]=root_b;
}


int main(){
    int n,m,a,b,c=0;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        v[i]=i;
    }
    while(m--){
        cin>>a>>b;
        if(root(v,a)==root(v,b)){
            cout<<"cycle present";
            c++;
            break;
        }
        else Union(v,a,b);
    }
    if(c==0){
        cout<<"no cycle present";
    }
    return 0;
}
/*
5 5
0 1
0 4
1 2
2 3
3 2 
*/