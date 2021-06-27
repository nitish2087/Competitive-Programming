#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){ 
       return (a.second>b.second); 
} 

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    long long n,c,key,k=0;
	    cin>>n;
	    vector<long long>v;
	    vector<pair<long long,long long>>w;
	    long long a;
	    for(int j=0;j<n;j++){
	        cin>>a;
	        v.push_back(a);
	    }
	    sort(v.begin(),v.end());
	    for(int j=0;j<n;){
	        key=v[j];
	        c=1;
	        for(k=j+1;k<n;k++){
	            if(key==v[k]){c++;}
	            else break;
	        }
	        w.push_back(make_pair(key,c));
	        j=k;
	    }
	    
	    sort(w.begin(),w.end(),sortbysec);
	    if(w[0].second > (n/2)){cout<<w[0].first<<"\n";}
	    else cout<<"-1\n";
	}
	return 0;
}
