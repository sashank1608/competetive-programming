#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int find_min(int a[],int i,int sum_c,int sum_tot )
{
    if(i==0) {return abs(sum_tot-2*sum_c);}
    return min(find_min(a,i-1,sum_c+a[i-1],sum_tot),find_min(a,i-1,sum_c,sum_tot));
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int sum_tot=0;
        for(int i=0;i<n;i++) {cin>>a[i]; sum_tot+=abs(a[i]);}
        // int sum_tot=accumulate(a,a+n,0);
        int ans=find_min(a,n,0,sum_tot);
        cout<<ans<<endl;
        int dp[n+1][sum_tot+1]={};
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum_tot;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=a[i-1]) dp[i][j]|=dp[i-1][j-a[i-1]];
            }
        }
        int ans1=INT_MAX;
        for(int i=0;i<=sum_tot;i++)
        {
          //  cout<<i<<" "<<dp[n][i]<<endl;
            if(dp[n][i]) ans1=min(ans1,abs(sum_tot-2*i));
        }
        cout<<ans1<<endl;

    }



}