#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int top=-1;
char a[MAX];

void push(char x){
	a[top++]=x;
}
int pop(){
	return a[top--];
}
char findd(char x){
	map<char,char> m;
	m.insert(pair<char,char>('}','{'));
	m.insert(pair<char,char>(']','['));
	m.insert(pair<char,char>(')','('));
	auto itr=m.find(x);
	return itr->second;
}
bool last(char x){
	if(top!=-1 || top !=0){
		int p=top-1;
		if(a[p]==findd(x)){return true;}
	}
	return false;
}
int main(){
	int n=6;
	char x;
	while(n--){
	cin>>x;
	if(last(x)){pop();}
	else push(x);
	}
	if(top==-1){
	cout<<"balanced"<<endl;
	}
	else cout<<"unbalanced"<<endl;
	return 0;
}
