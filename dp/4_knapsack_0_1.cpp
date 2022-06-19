#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>&v,vector<int>&wt,int n,int w,vector<vector<int>>&dp){
    if(n==0||w==0) dp[n][w]=0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(wt[n-1]<=w){
        dp[n][w]=max(v[n-1]+knapsack(v,wt,n-1,w-wt[n-1],dp),knapsack(v,wt,n-1,w,dp));
    }
    else if(wt[n-1]>w) dp[n][w]=knapsack(v,wt,n-1,w,dp);
    return dp[n][w];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        vector<int>v(n);
        vector<int>wt(n);
        for(int i=0;i<n;i++)cin>>v[i];
        for(int i=0;i<n;i++)cin>>wt[i];
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        cout<<knapsack(v,wt,n,w,dp)<<endl;
    }
    return 0;
}
//test case:
// 2
// 3
// 4
// 1 2 3
// 4 5 1
// 3
// 3
// 1 2 3
// 4 5 6