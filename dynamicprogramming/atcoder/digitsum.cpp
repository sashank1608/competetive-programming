#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define ll long long
//int dp[100][2],dp1[100][2];
void add_self(int &a,int b)
{
    a=(a+b)%mod;
}
int main()
{
    string s;
    int d;
    cin>>s;
   // cout<<s<<endl;
    cin>>d;
     vector<vector<int> > dp(100,vector<int>(2));
    dp[0][0]=1;
   
    //dp[0][1]=0;
    for(int i=0;i<s.length();i++)
    {
        vector<vector<int> > dp1(100,vector<int>(2));
        for(int j=0;j<d;j++)
        {
           add_self( dp1[(j+(int)(s[i]-'0'))%d][0],dp[j][0]);
            for(int k=0;k<=9;k++)
            {
                add_self(dp1[(j+k)%d][1],dp[j][1]);
                if(k<(int)(s[i]-'0'))
                {
                     add_self( dp1[(j+k)%d][1],dp[j][0]);
                   //   cout<< dp[0][1]<<endl;

                }
            }
        }
       // memcpy(dp,dp1,sizeof(dp));
        dp=dp1;
    }
    ll ans=(dp[0][0]+dp[0][1]-1);
    if(ans<0) ans+=mod;
    cout<<ans%mod;
    // for(int i=0;i<d;i++)
    // {
    //     for(int j=0;j<2;j++)
    //     {
    //         cout<<dp[i][j]<<" ";

    //     }
    //     cout<<endl;
    // }
    

}