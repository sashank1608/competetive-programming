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
        int p,q,r;
        p=1;//insert
        q=1;//remove
        r=1;//replace
        int dp[n+1][m+1];
        for(int i=0;i<=m;i++) {dp[0][i]=p*i;}
         for(int i=0;i<=n;i++) {dp[i][0]=q*i;}
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1]) {dp[i][j]=dp[i-1][j-1];}
                else
                {
                    dp[i][j]=min(r+dp[i-1][j-1],min(p+dp[i][j-1],q+dp[i-1][j]));
                }
                
            }
        }
        cout<<dp[n][m]<<endl;

    }


}