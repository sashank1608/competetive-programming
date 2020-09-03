#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int nax=2e5+5;
ll dp[nax];
int main()
{
    int n;

    cin>>n;
    int h[n];
    for(int i=0;i<n;i++) cin>>h[i];
    ll a[n];
     for(int i=0;i<n;i++) cin>>a[i];
    // max possible beauty having h[i] as last element
    int base=1;
    while(base<=n)
    {
        base*=2;
    }
    vector<ll > tree(2*base);

  
    for(int i=0;i<n;i++)
    {
        // for(int j=0;j<h[i];j++)
        // {
        //     dp[h[i]]=max(dp[h[i]],dp[j]+a[i]);
        // }
        //find max from 0 to h[i]-1
        int node=base+h[i]-1;
        ll ans=tree[node];
        while(node>=1)
        {
            if(node%2)
            {
                ans=max(ans,tree[node-1]);
            }
            node/=2;
        }
        dp[h[i]]=max(dp[h[i]],ans+a[i]);
        int x=base+h[i];
        while(x>=1)
        {
            tree[x]=max(dp[h[i]],tree[x]);
            x/=2;
        }


    }
    ll ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp[h[i]]);

    }
    cout<<ans;
}