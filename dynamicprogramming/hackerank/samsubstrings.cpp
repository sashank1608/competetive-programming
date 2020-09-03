#include <bits/stdc++.h>
using namespace std;
#define pb push_back
//dp1 s,col,ally
//dp2 s,col,ally, idx
const int nmax=2e5+1;
const int mod=1e9+7;
long long dp[nmax];
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    dp[1]=s[0]-'0';
    for(int i=1;i<n;i++)
    {
        if(i)
        dp[i+1]+=((10*dp[i]%mod+i*(s[i]-'0'))+s[i]-'0');
      
        
        dp[i+1]%=mod;
    }
    long long sum=0;
    for(int i=0;i<=n;i++)
    {
        //cout<<dp[i]<<" ";
        sum+=dp[i];
        sum%=mod;
    }
    cout<<sum<<endl;
}