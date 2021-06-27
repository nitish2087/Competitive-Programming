#include<bits/stdc++.h>
using namespace std;

void Union(vector<int>&v,int a,int b){
	int temp1,temp2;
	if(a<b){temp1=v[a];temp2=v[b];}
	else {temp1=v[b];temp2=v[a];}
	for(int i=0;i<v.size();i++){
		if(v[i]==temp2){
			v[i]=temp1;
		}
	}
}
bool find(vector<int>&v,int a,int b){
	if(v[a]==v[b]){
		return true;
	}
	else return false;
}

int main(){
	int n,m,a,b,t1,t2;
	cin>>n>>m;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		v[i]=i;
	}
	while(m--){
		cin>>a>>b;
		Union(v,a,b);

	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cin>>t1>>t2;
	cout<<find(v,t1,t2);
	return 0;
}