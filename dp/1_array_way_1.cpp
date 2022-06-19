/*Given 3 numbers {1, 3, 5}, we need to tell
the total number of ways we can form a number 'N' 
using the sum of the given three numbers.
(allowing repetitions and different arrangements).*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>&soln){
	if(n<0) return 0;
	if(n<=1) return 1;
	if(soln[n]!=-1) return soln[n];
	return soln[n]=solve(n-1,soln)+solve(n-3,soln)+solve(n-5,soln);
}

int main(){
	int n=7;
	vector<int>soln(n+1,-1);
	cout<<solve(n,soln);
	return 0;
}