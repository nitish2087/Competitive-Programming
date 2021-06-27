#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL merge_(LL a[],LL temp[],LL low1,LL up1,LL low2,LL up2) {
    LL i=low1,j=low2,k=low1;
    LL count=0;
    while((i<=up1)&&(j<=up2)){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
            count+=(low2-i);
        }
    }
    while(i<=up1){temp[k++]=a[i++];}
    while(j<=up2){temp[k++]=a[j++];}
    for(int t=low1;t<=up2;t++){
        a[t]=temp[t];
    }
    return count;
}

LL mergeSort(LL arr[],LL temp[], LL low, LL up) { 
    LL count=0;
    if (low < up) 
    { 
        LL mid = (low+up)/2;
        count+=mergeSort(arr,temp, low, mid); 
        count+=mergeSort(arr,temp, mid+1, up); 
        count+=merge_(arr,temp,low,mid, mid+1, up);
    } 
    return count;
} 

int main() {
	int t;
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>t;
	for(int m=0;m<t;m++){
	    long long n;
	    cin>>n;
	    LL v[n],temp[n];
	    for(LL j=0;j<n;j++){
	        cin>>v[j];
	    }
	    LL c=mergeSort(v,temp,0,n-1);
	    cout<<c<<endl;
	}
	return 0;
}
