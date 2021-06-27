#include <bits/stdc++.h>
using namespace std;

long maxSum(long a[],long n){
    long max_sum=INT_MIN,max_end=0;
    for(long i=0;i<n;i++){
        max_end+=a[i];
        if(max_sum<max_end){max_sum=max_end;}
        if(max_end<0){max_end=0;}
    }
    return max_sum;
}

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    long n;
	    cin>>n;
	    long a[n];
	    for(long j=0;j<n;j++){
	        cin>>a[j];
	    }
	    long sum=maxSum(a,n);
	    cout<<sum<<endl;
	}
	return 0;
}
