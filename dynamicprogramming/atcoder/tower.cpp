#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18L+5;
struct block{
int w,s;ll v;
};
int main()
{
    int n;
    cin>>n;
    vector<block> vec(n);
    int max_w=0;
    for(int i=0;i<n;i++)
    {
        cin>>vec[i].w>>vec[i].s>>vec[i].v;
        max_w+=vec[i].w;
    }
    sort(vec.begin(),vec.end(),[](block a,block b){
        return a.w+a.s<b.w+b.s;
    });
    //dp[i] max value with total weight i so far
    vector<ll> dp(max_w+5);
   // dp[n-1]=vec[n-1].v;
    for(int i=0;i<n;i++)
    {
        for(int j=min(vec[i].s,max_w-vec[i].w);j>=0;j--)
        {
            // if(j<=vec[i].s)
            
                dp[j+vec[i].w]=max(dp[j+vec[i].w],dp[j]+vec[i].v);
            

        }
    }
    ll ans=-1;
    for(int j=max_w;j>=0;j--)
    {
        ans=max(ans,dp[j]);
    }
    cout<<ans<<endl;

}