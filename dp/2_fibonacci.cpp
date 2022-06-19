#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int>&memo){
	if(memo[n]!=-1){
		return memo[n];
	}
	memo[n]=fib(n-2,memo)+fib(n-1,memo);
	return memo[n];
}
int main(){
	int n;
	cin>>n;
	vector<int>memo(n,-1);
	memo[0]=0;
	memo[1]=1;
	int t=fib(n-1,memo);
	for(int i=0;i<n;i++){
		cout<<memo[i]<<" ";
	}
	return 0;
}
