#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
    int begin=0,deficit=0;
    int capacity=0;
    for(int i=0;i<n;i++){
        capacity+=p[i].petrol-p[i].distance;
        if(capacity<0){
           begin=i+1;
           deficit+=capacity;
           capacity=0;
        }
        //else {
        //    p[i]+=(p[i-1].petrol-p[i-1].distance);
        //}
    }
    if((capacity+deficit)>0){return begin;}
    else return -1;
}


