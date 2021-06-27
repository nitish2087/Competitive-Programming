#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,sum,a,total=0;
	    cin>>n>>sum;
	    vector<int>v;
	    for(int j=0;j<n;j++){
	        cin>>a;
	        v.push_back(a);
	    }
	    int p=sum;
	    bool flag=false;
	    for(int j=0;j<n;j++){total+=v[i];}
	    for(int j=0;j<n;j++){
	        sum=p;
	        for(int k=j;k<n;k++){
	            sum-=v[k];
	            if(sum==0){
	                cout<<(j+1)<<" "<<(k+1)<<endl;
	                flag=true;
	                break;
	            }
	            if(sum<0){break;}
	        }
	        if(flag==true){break;}
	    }
	    if(sum!=0){cout<<"-1"<<endl;}
	}
	return 0;
}
