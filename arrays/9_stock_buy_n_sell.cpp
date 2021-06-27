#include <bits/stdc++.h>
using namespace std;


int main() {
	int t,c=0;
	cin>>t;
	for(int p=0;p<t;p++){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    int key,large;
        for(int i=0;i<n-1;){
            key=a[i];
            large=a[i];
            for(int j=i+1;j<n;j++){
                if(a[j]>=large){
                    large=a[j];
                    if(j==n-1){cout<<"("<<i<<" "<<j<<")"<<" ";c++;i=n;break;}
                }
                else if(a[j]<large){
                    if((j-i)>1){
                        cout<<"("<<i<<" "<<(j-1)<<")"<<" ";
                        c++;
                        i=j;
                        large=a[i];
                        break;
                    }
                    else
                        i=j;
                        break;
                }
            }
        }
        if(c==0){
            cout<<"No Profit\n";
        }
        else{cout<<"\n";}
        c=0;
	}
	return 0;
}
