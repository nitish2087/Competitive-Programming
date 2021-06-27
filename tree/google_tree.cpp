#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node* newNode(int x){
	node *temp=new node;
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node* buildTree(string s){
	if(s.length()==0 || s[0]=='n'){return NULL;}
	vector<string>v;
	queue<node*>q;
	istringstream iss(s);
	for(string s;iss>>s;){
		v.push_back(s);
	}
	node* root=newNode(stoi(v[0]));
	q.push(root);
	int i=1;
	while(!q.empty() && i<v.size()){
		node* temp=q.front();
		q.pop();
		string val=v[i];
		if(val!="n"){
			temp->left=newNode(stoi(val));
			q.push(temp->left);
		}
		i++;
		if(i>=v.size()) break;
		val=v[i];
		if(val!="n"){
			temp->right=newNode(stoi(val));
			q.push(temp->right);
		}
		i++;
	}
	return root;
}

int maxPathSum(node *root,int u,int v){
	int ans=INT_MIN;
	if(!root) return 0;
	if(root->data ==u||root->data==v) {ans+=root->data; return ans;}
	root->left=maxPathSum(root->left,u,v);
	root->right=maxPathSum(root->right,u,v);
	if(!root->left &&!root->right) return root->data;
	else return (root->left->data>root->right->data)?root->left->data:root->right->data;
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		getline(cin,s);
		node *root=buildTree(s);
		int u,v;
		cin>>u>>v;
		cout<<maxPathSum(root,u,v);
	}
	
	return 0;
}