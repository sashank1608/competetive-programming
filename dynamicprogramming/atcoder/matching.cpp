#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int dp[1<<n]={};
    dp[0]=1;
    for(int i=0;i<1<<n;i++)
    {
        int x=__builtin_popcount(i);
        for(int j=0;j<n;j++)
        {
            if(a[x][j]&&!(i&1<<j))
            {
               
                    dp[i|1<<j]=(dp[i|1<<j]+dp[i])%mod;
                
            }
        }
    }
    cout<<dp[(1<<n)-1]%mod<<endl;
}