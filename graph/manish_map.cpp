#include<bits/stdc++.h>
using namespace std;
int main(){
	int l[]={1,2,5,15};
	int r[]={5,8,7,18};
	int i,j;
	int map[20];
	memset(map,0,sizeof(map));
	for(i=0,j=0;i<4,j<4;i++,j++){
		for(int p=l[i];p<=r[j];p++){
			map[p]++;
		}
	}
	int max=0;
	for(int i=0;i<20;i++){
		if(map[i]>max) max=i;
	}
	cout<<max<<endl;
	return 0;
}