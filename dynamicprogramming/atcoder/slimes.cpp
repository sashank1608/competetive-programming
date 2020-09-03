#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define ll long long
ll dp[405][405];
int main()
{
int n;
cin>>n;
ll a[n];
for(int i=0;i<n;i++) cin>>a[i];
ll pref[n]={};
pref[0]=a[0];
for(int i=1;i<n;i++) pref[i]+=(pref[i-1]+a[i]);
// for(auto i : pref) cout<<i<<" ";
// cout<<endl;
for(int i=0;i<=n;i++)
for(int j=0;j<=n;j++)
{
    dp[i][j]=1e18L+5;;
}

for(int gap=1;gap<=n;gap++)
{
    for(int i=0;i<n;i++)
    {
        int j=i+gap-1;
        if(i==j) dp[i][j]=0;
        else if(j<n)
        {
        for(int k=i;k<j;k++)
        {
            // cout<<i<<" "<<k<<" "<<j<<" ";
            // cout<<(pref[k]-((i>0)?pref[i-1]:0))+(pref[j]-pref[k])<<endl;
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+(pref[j]-((i>0)?pref[i-1]:0)));
        }
        }
    }

    }
// for(int i=0;i<=n;i++)
// {
// for(int j=0;j<=n;j++)
// {
//    cout<< dp[i][j]<<" ";
// }
// cout<<endl;
// }

cout<<dp[0][n-1]<<endl;

}