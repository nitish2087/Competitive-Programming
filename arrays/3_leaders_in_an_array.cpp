#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,a;
	    cin>>n;
	    vector<int>v,w;
	    for(int j=0;j<n;j++){
	        cin>>a;
	        v.push_back(a);
	    }
	    int leader;
	    leader=v[n-1];
	    w.push_back(leader);
	    for(int j=n-2;j>=0;j--){
	        if(v[j]>=leader){
	            leader=v[j];
	            w.push_back(leader);
	        }
	    }
	    
	    for(int j=w.size()-1;j>=0;j--){
	        cout<<w[j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
