#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    set<char>longest;
	    int length=0,temp=0;
	    for(int i=0;i<s.size();i++){
	        longest.insert(s[i]);
	        if(longest.size()<i-temp+1){
	           longest.clear();
	           i=temp++;
	        }
	        length=max(length,int(longest.size()));
	    }
	    cout<<length<<endl;
	}
	return 0;
}
