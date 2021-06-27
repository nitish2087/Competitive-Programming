#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string a,b;
	    cin>>a>>b;
	    int first[26]={0},second[26]={0};
	    
	    for(int i=0;i<a.size();i++){
	        first[int(a[i])-97]++;
	    }
	    for(int i=0;i<b.size();i++){
	        second[int(b[i])-97]++;
	    }
	    bool flag=true;
	    for(int i=0,j=0;i<26,j<26;i++,j++){
	        if(first[i]==second[j]){
	            continue;
	        }
	        else{
	            flag=false;
	            cout<<"NO"<<endl;
	            break;
	        }
	    }
	    if(flag==true){cout<<"YES"<<endl;}
	    flag=true;
	}
	return 0;
}
