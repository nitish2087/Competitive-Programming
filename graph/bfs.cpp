#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>v[], int root){
	vector<bool> visited = {false}; // visited array to avoid cycle cases, not required in tree
 	queue<int> q; 
 	q.push(root);
 	visited[root] = true;
 	while (!q.empty()) {
 		int t = q.front();
 		cout << t << " ";
 		q.pop();
 		for (auto i = v[t].begin(); i < v[t].end(); i++){
 			if (!visited[*i]) {
 				q.push(*i);
 				visited[*i] = true;
 			}
 		}
 	}
}
 int main(){
 	int n, m, a, b;
 	cin >> n >> m;
 	vector<int> v[n];
 	while(m--) {
 		cin >> a >> b;
 		v[a].push_back(b);
 		v[b].push_back(a);
 	}
 	bfs(v, 0); // 0 -> root node
 	return 0;
 }
