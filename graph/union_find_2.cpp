#include<bits/stdc++.h>
using namespace std;

int root(vector<int>&v,int i){
	while(v[i]!=i){
		i=v[i];
	}
	return i;
}

void Union(vector<int>&v,int a,int b){
	int root_a=root(v,a);
	int root_b=root(v,b);
	v[root_a]=root_b;
}
bool find(vector<int>&v,int a,int b){
	if(root(v,a)==root(v,b)) return true;
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