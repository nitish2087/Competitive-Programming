#include <bits/stdc++.h>
using namespace std;
int maxx(queue<int> q){
    int max=q.front();
    queue<int> temp;
    temp=q;
    temp.pop();
    while(!temp.empty()){
        if(max<temp.front()){
            max=temp.front();
        }
        temp.pop();
    }
    return max;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int v[n];
	    int i=0;
	    for(int i=0;i<n;i++) cin>>v[i];
	    queue<int> q;
	    int max=v[0];
	    for(int i=0;i<k;i++){
	        q.push(v[i]);
	        if(max<v[i]){max=v[i];}
	    }
	    cout<<max<<" ";
	    for(int i=k;i!=n;++i){
	        //cout<<max<<" ";
	        int s=q.front();
	        q.pop();
	        q.push(v[i]);
	        if(max==s){max=maxx(q);cout<<max<<" ";}
	        else{ if(max<v[i]){max=v[i];} cout<<max<<" ";}
	    }
	    while(!q.empty()) q.pop();
	    cout<<endl;
	}
	return 0;
}
