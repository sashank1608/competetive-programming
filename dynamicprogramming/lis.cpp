#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int dp[n+1]={};
        int ans[n+1]={};
       // ans[1]=0;
        dp[1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(a[i-1]>a[j-1])
                {
                    if(1+dp[j]>dp[i]) {dp[i]=1+dp[j];ans[i]=j;}
                }
               //  dp[i]=max(dp[i],1+dp[j])
                 
            }
        }
        vector<int>ans1;
        int len=0,idx;
         for(int i=1;i<=n;i++) if(dp[i]>len) {len=dp[i];idx=i;};
        int i=idx;
         while(i>=1)
         {
             ans1.pb(a[i-1]);
             i=ans[i];
         }
         reverse(ans1.begin(),ans1.end());
         for(auto i: ans1) cout<<i<<" ";
         cout<<endl;
         
       // cout<<dp[n]<<endl;

    }



}