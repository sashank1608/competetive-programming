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
        string a,b;
         cin>>a>>b;
         int n=a.length();
         int m=b.length();
         int dp[n+1][m+1]={};
         //dp[0][0]=1;
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=m;j++)
             {
                   if(a[i-1]==b[j-1])
                   {
                       dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);

                   }
                   else dp[i][j] =max(dp[i-1][j],dp[i][j-1]);
             }
         }
       //  cout<<dp[n][m];
         for(auto i=0;i<=n;i++)
         {
             for(int j=0;j<=m;j++)
             {
                 cout<<dp[i][j]<<" ";
             }
             cout<<endl;
         }
         string ans;
         int i=n,j=m;
         while(i>=1&&j>=1)
         {
            
             if(a[i-1]==b[j-1]) {ans+=a[i-1];i--;j--;}
             else
             {
                if(dp[i][j-1]<dp[i-1][j]) 
                {
                    i--;
                }
                else j--;
             }
              cout<<i<<" "<<j<<endl;

         }
         reverse(ans.begin(),ans.end());
         cout<<ans<<endl;

    }


}