#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string a,b;
	    cin>>a>>b;
	    string c=a+a;
	    string d=b+b;
	    if(c.find(b)==2||d.find(a)==2){
	        cout<<"1"<<endl;
	    }
	    else cout<<"0"<<endl;
	}
	return 0;
}
