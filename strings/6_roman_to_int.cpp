
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	int number=0;
	map<char,int> ooo_bhai;
	ooo_bhai['I']=1;
	ooo_bhai['V']=5;
	ooo_bhai['X']=10;
	ooo_bhai['L']=50;
	ooo_bhai['C']=100;
	ooo_bhai['D']=500;
	ooo_bhai['M']=1000;
	while(t--){
	    string roman;
	    cin>>roman;
	    int number=ooo_bhai[roman[0]];
	    for(int i=1;i<roman.size();i++){
	        int t=ooo_bhai[roman[i]];
	        int p=ooo_bhai[roman[i-1]];
	        if(t<=p){
	            number+=t;
	        }
	        else if(t>p){
	            number-=p;
	            t-=p;
	            number+=t;
	        }
	    }
	    cout<<number<<endl;
	}
	return 0;
}
