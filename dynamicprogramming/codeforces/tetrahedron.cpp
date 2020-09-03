#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    ll MOD=1e9+7;
    ll dp[n+1][2];
    dp[0][0]=1;
    dp[0][1]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=(3LL*dp[i-1][1])%MOD;
        dp[i][1]=(dp[i-1][0]+(2LL*dp[i-1][1])%MOD);

    }
    cout<<dp[n][0];


}
