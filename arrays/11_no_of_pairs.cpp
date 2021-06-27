#include<bits/stdc++.h> 
using namespace std;

long count(long x, long Y[], long n, long NoOfY[]) 
{ 
    if (x == 0) return 0;
    if (x == 1) return NoOfY[0];
    long* idx = upper_bound(Y, Y + n, x); 
    long ans = (Y + n) - idx;
    ans += (NoOfY[0] + NoOfY[1]); 
    if (x == 2)  ans -= (NoOfY[3] + NoOfY[4]);
    if (x == 3)  ans += NoOfY[2]; 
    return ans; 
} 

long countPairs(long X[], long Y[], long m, long n) 
{ 
    long NoOfY[5] = {0}; 
    for (long i = 0; i < n; i++) 
        if (Y[i] < 5) 
            NoOfY[Y[i]]++; 
    sort(Y, Y + n); 
    long total_pairs = 0;
    for (long i=0; i<m; i++) 
        total_pairs += count(X[i], Y, n, NoOfY); 
    return total_pairs; 
} 

int main() {
	long t;
	cin>>t;
	for(long i=0;i<t;i++){
	    long m,n;
	    cin>>m>>n;
	    long x[m],y[n];
	    for(long j=0;j<m;j++){
	        cin>>x[j];
	    }
	    for(long j=0;j<n;j++){
	        cin>>y[j];
	    }
	    cout<<countPairs(x,y,m,n)<<endl;
	}
	return 0;
}
