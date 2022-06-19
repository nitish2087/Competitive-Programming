#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,w;
	    cin>>n>>w;
	    vector<int>v(n);
	    vector<int>wt(n);
	    vector<vector<int>>dp(n+1,vector<int>(w+1));
	    for(int i=0;i<n;i++)cin>>v[i];
	    for(int i=0;i<n;i++)cin>>wt[i];
	    cout<<knapsack(v,wt,w,n,dp)<<endl;
	}
	return 0;
}