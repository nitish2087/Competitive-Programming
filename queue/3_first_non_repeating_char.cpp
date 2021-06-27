#include<bits/stdc++.h>
using namespace std;

char find(deque<char> q, char c){
    
    try{
        const auto it = find(q.begin(), q.end(), c);
        const auto position = distance(q.begin(), it);
        return q.at(position);
    }
    catch(const out_of_range& e){
        return '\0';
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    char c;
	    deque<char> q;
	    int f[26]={0};
	    for(int i=0;i<n;i++){
	        cin>>c;
	        f[c-'a']++;
	        if(c==find(q,c)){
	            q.erase(remove(q.begin(), q.end(), c), q.end());
	            if(q.empty()){
	                cout<<"-1 ";
	            }
	            else cout<<q.front()<<" ";
	        }
	        else {
	            if(f[c-'a']<2){
	                q.push_back(c);
	            }
	            if(!q.empty()){cout<<q.front()<<" ";}
	            else cout<<"-1 ";
	        }
	    }
	    cout<<endl;
	    q.clear();
	    fill_n(f,26,0);
	}
}
