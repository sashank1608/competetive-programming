#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define ll long long
int main()
{
int n,k;
cin>>n>>k;
int a[n];
vector<ll> dp(k+1);
dp[0]=1;
for(int i=0;i<n;i++) cin>>a[i];
for(int i=0;i<n;i++)
{
   // int dp1[k+1]={};
   vector<ll> dp1(k+1);
   vector<ll> fake(k+1);
    for(int already=0;already<=k;already++)
    {
        fake[already]=(fake[already]+dp[already])%mod;
        fake[already]%=mod;
        if(already+a[i]<k)
        {fake[already+a[i]+1]=(fake[already+a[i]+1]-dp[already]); if(fake[already+a[i]+1]<0)fake[already+a[i]+1]+=mod;}

        // for(int j=0;j<=a[i];j++)
        // {
        //     if(already+j<=k) dp1[already+j]=(dp1[already+j]+dp[already])%mod;
        // }
    }
    for(int j=1;j<=k;j++)
    {
        fake[j]=(fake[j]+fake[j-1])%mod;
        fake[j]%=mod;
    }
    for(int j=0;j<=k;j++)
    {
        dp1[j]=(dp1[j]+fake[j])%mod;
        dp1[j]%=mod;
    }
    dp=dp1;
}
cout<<dp[k]%mod<<endl;

}
