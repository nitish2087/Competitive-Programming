#include <bits/stdc++.h>
using namespace std;

string process(string s, int& cnt, string ans){
	cnt = 0;
	stack<char> st;
	for(int i = 0; i < s.size(); i++){
		if( st.empty() == true ){
			st.push(s[i]);
		}else if( s[i] == ans[1] && st.top() == ans[0] ){
			cnt++;
			st.pop();
		}else{
			st.push(s[i]);
		}
	}
	vector<char> res;
	while( st.empty() == false )
		res.push_back(st.top()), st.pop();

	reverse(res.begin(), res.end());
	string rs(res.begin(), res.end());

	return rs;
}

int main(){
	
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int x, y;
		cin >> x >> y;
		int ans = 0;
		if( x > y ){
			int cnt;
			string rs = process(s, cnt, "pr");
			ans = ans + x*cnt;
			process(rs, cnt, "rp");
			ans = ans + y*cnt;
		}else{
			int cnt;
			string rs = process(s, cnt, "rp");
			ans = ans + y*cnt;
			process(rs, cnt, "pr");
			ans = ans + x*cnt;
		}

		cout << ans << endl;
	}	
	return 0;
}