#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define pb push_back
#define ll long long
int main()
{
    int n,x;
    cin>>x>>n;
    int a[n];
    int mi=INT_MAX,val=0;
    vector<int> ans,mark(106,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mark[a[i]]++;
       // mi=max(mi,a[i]);
    }
    
    if(x<=0) {cout<<x<<endl;return 0;}
        for(int i=0;i<=106;i++)
    {
        if(mark[i]==0)
        {
            if(abs(i-x)<mi)
            {
                val=i;
                mi=abs(i-x);
            }
            // mi=min(mi,abs(i-x));

        }
    }
    cout<<val<<endl;
        
    
    
    
}