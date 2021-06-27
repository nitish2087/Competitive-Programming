#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    vector<int>v;
	    int a;
	    for(int j=0;j<n-1;j++){
	        cin>>a;
	        v.push_back(a);
	    }
	    long long t=n*(n+1)/2;
	    long long p=0;
	    for(int j=0;j<n-1;j++){
	        p+=v[j];
	   }
	   cout<<t-p<<endl;
	}
	return 0;
}
