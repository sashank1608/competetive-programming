#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int dp[n][2]={{}};
        for(int i=1;i<n;i++)
        {
            dp[i][1]=max(dp[i-1][1]+abs(a[i]-a[i-1]),dp[i-1][0]+abs(a[i]-1));
            dp[i][0]=max(dp[i-1][1]+abs(a[i-1]-1),dp[i-1][0]);
        }
        cout<<max(dp[n-1][1],dp[n-1][0])<<endl;


    }
}