#include <bits/stdc++.h>
using namespace std;

string longestString(vector<string>&v,string s){
	vector<pair<int,string>>m(v.size());
	for(int i=0;i<v.size();i++){
		m[i].first=0;
		m[i].second=v[i];
	}
	for(int i=0;i<v.size();i++){
		int k=0;
		for(int j=0;j<v[i].size();){
			if(v[i][j]==s[k] && k<s.size()){
				j++;
				k++;
				m[i].first++;
			}
			else if(k<s.size()) k++;
			else break;
		}
	}
	sort(m.begin(),m.end());
	for(int i=m.size()-1;i>0;i--){
		if(m[i].first==m[i-1].first){continue;}
		else return m[i].second;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string>v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		string s;
		cin>>s;
		cout<<longestString(v,s)<<endl;
	}
	return 0;
}