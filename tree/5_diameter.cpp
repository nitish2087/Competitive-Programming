#include<bits/stdc++.h>
using namespace std;
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

int height(node* root){
	if(!root){return 0;}
	if(!root->left && !root->right){return 1;}
	int l=height((root->left));
	int r=height((root->right));
	return (1+(l>r?l:r));
}

int diameter(node* root){
	if(root==NULL) return 0;
	int l_r=height(root->left);
	int r_r=height(root->right);
	int h1=l_r+r_r+1;

	int l_w=diameter(root->left);
	int r_w=diameter(root->right);
	int h2=max(l_w,r_w);
	return max(h1,h2);
}

int main(){
	string s;
	getline(cin,s);
	node *root=buildTree(s);
	cout<<diameter(root);
	//cout<<root->left->data<<endl;
	//int l=height(root->left);
	//int r=height(root->right);
	//cout<<(l+r+1);
	return 0;
}