#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[101][101][2];
const int mod=1e8;
ll rec(int n1,int n2,int typ,int k1,int k2)
{
    ll add=0;
    if(n1==0&&n2<=k2) return (ll)1;
    else if(n1<=k1&&n2==0) return (ll)1;
    else if(n1==0&&n2>k2) return -10000;
    else if(n1>k1&&n2==0)  return -10000;
    if(dp[n1][n2][typ]!=-1) return dp[n1][n2][typ];
    if(typ==1)
    {
        for(int j=1;j<=min(k2,n2);j++)
        {
            ll chk=rec(n1,n2-j,0,k1,k2);
            if(chk>=0)
            add=(add+chk)%mod;
        }
       

    }
    else
    {
        for(int j=1;j<=min(k1,n1);j++)
        {
            ll chk=rec(n1-j,n2,1,k1,k2);
            if(chk>=0)
            add+=chk;
        }
        
    }
    return dp[n1][n2][typ]=add;
    
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;

    ll ans=rec(n1,n2,1,k1,k2)+rec(n1,n2,0,k1,k2);
    cout<<ans<<endl;


}