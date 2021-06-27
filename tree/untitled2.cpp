#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int x){
	node* temp= new node;
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node* buildTree(string s){
	if(s.size()==0 || s[0]=='n'){return NULL;}
	vector<string>v;
	vector<int>w;
	queue<node*>q;
	istringstream iss(s);
	for(string s;iss>>s;){
		v.push_back(s);
	}
	node* root=newNode(stoi(v[0]));
	cout<<root->data<<" ";
	q.push(root);
	int i=1,c=0;
	while(!q.empty() && i<v.size()){
		node* temp=q.front();
		q.pop();
		string val=v[i];
		if(val!="n"){
			temp->left=newNode(stoi(val));
			if(c%2==0) cout<<temp->left->data<<" ";
			else w.push_back(temp->left->data);
			q.push(temp->left);
		}
		i++;
		if(i>=v.size()){break;}
		val=v[i];
		if(val!="n"){
			temp->right=newNode(stoi(val));
			if(c%2==0) cout<<temp->right->data<<" ";
			else w.push_back(temp->right->data);
			q.push(temp->right);
		}
		if(c%2!=0){
			for(auto i:w) cout<<i<<" ";
			w.clear();
		}
		i++;
		c++;

	}
	return root;
}



int main(){
	string s;
	getline(cin,s);
	node* root=buildTree(s);
	return 0;
}
