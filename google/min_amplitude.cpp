#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define TEST int t=1; while(t--) solve();
void solve(){
	int n;
	vector<int>v;
	while(cin>>n) v.pb(n);
	sort(v.begin(),v.end());
	int s=v.size();
	cout<<min((v[s-4]-v[s-5]),min(v[s-1]-v[3],min(v[s-3]-v[1],v[s-2]-v[2])))<<endl;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	TEST;
	return 0;
}