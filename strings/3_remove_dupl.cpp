#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	cin>>ws;
	int asc[256]={0};
	while(t--){
	    string a;
	    getline(cin,a);
	    cin>>ws;
	    for(int i=0;i<a.size();i++){
	        if(asc[int(a[i])]==0){
	            asc[int(a[i])]=-1;
	            cout<<a[i];
	        }
	    }
	    cout<<endl;
	    fill_n(asc, 256, 0);
	}
	return 0;
}
