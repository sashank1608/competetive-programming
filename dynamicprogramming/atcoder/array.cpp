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
ll suff[n];
suff[n-1]=a[n-1];
for(int i=n-2;i>=0;i--)
{
    suff[i]=max(suff[i+1],a[i]);
}
ll ans=0;
for(int i=0;i<n-1;i++)
{
    ans=max(ans,suff[i+1]-a[i]);

}
cout<<ans<<endl;

}