#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int x){
	node* temp=new node;
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node* buildTree(string s){
	if(s.size()==0 || s[0]=='n'){return NULL;}
	vector<string>v;
	
	istringstream iss(s);
	for(string s;iss>>s;){
	    v.push_back(s);
	}
	node* root=newNode(stoi(v[0]));
	queue<node*> q;
	q.push(root);

	int i=1;
	while(!q.empty() && i<v.size()){
		node* temp1=q.front();
		q.pop();
		string val=v[i];
		if(val!="n"){
			temp1->left=newNode(stoi(val));
			q.push(temp1->left);
		}
		i++;
		if(i>=v.size()){break;}
		val=v[i];
		if(val!="n"){
			temp1->right=newNode(stoi(val));
			q.push(temp1->right);
		}
		i++;
	}
	return root;
}

int countLeaves(node *root){
	if(!root){return 0;}
	if(!root->left && !root->right){cout<<root->data<<endl;return 1;}
	return (countLeaves(root->left)+countLeaves(root->right));
}

int main(){
	string s;
	getline(cin,s);
	node* root =buildTree(s);
	cout<<countLeaves(root);
	return 0;
}