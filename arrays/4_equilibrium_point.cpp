#include <bits/stdc++.h>
using namespace std;

int sum_f(int i,int n,vector<int> v){
    int f=0;
    for(int t=i;t<n;t++){
        f+=v[t];
    }
    return f;
}


int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,c,a;
	    cin>>n;
	    vector<int>v;
	    for(int i=0;i<n;i++){
	        cin>>a;
	        v.push_back(a);
	    }
	    bool flag=false;
	    int r=sum_f(0,n,v),l=0;
	    for(int i=0;i<n;i++){
	        r=r-v[i];
	        if(l==r){
	            cout<<i+1<<endl;
	            flag=true;
	            break;
	        }
	        l=l+v[i];
	    }
	    if(flag==false){cout<<"-1"<<endl;}
	}
	return 0;
}
