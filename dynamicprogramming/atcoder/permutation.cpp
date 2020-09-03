#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
int dp[3001][3001],pref[3001][3001];
int add_self(int &a,int b)
{
    a=(a+b)%mod;
}
int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    //dp[i][last_no]
   // int dp[]
   dp[0][1]=1;
    for(int i=1;i<n;i++)
    {
       for(int k=1;k<=i;k++)
       {
           pref[i-1][k]=(pref[i-1][k-1]+dp[i-1][k])%mod;
       }
       
        for(int k=1;k<=i+1;k++)
        {
            int L,R;
            if(s[i-1]=='<')
            {
                 L=1;
                 R=k-1;

            }
            else
            {
                L=k;
                R=i;
            }
            if(L<=R)
            add_self(dp[i][k],(pref[i-1][R]-pref[i-1][L-1]+mod)%mod);
            // for(int j=L;j<=R;j++)
            // {
            //     add_self(dp[i][k],dp[i-1][j]);
            // }
            
        //      for(int j=1;j<=i;j++)
        // {
        //     if(check(k,s[i-1],j))
        //     {
        //         dp[i][k]+=dp[i-1][j];
        //     }

        // }

        }

    }
    int sum=0;
    for(int j=1;j<=n;j++)
    {
        add_self(sum,dp[n-1][j]);
    }
    cout<<sum<<endl;
}