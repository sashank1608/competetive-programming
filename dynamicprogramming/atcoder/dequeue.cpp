#include<bits/stdc++.h>
using namespace std;
long long dp[3001][3001];
int main()
{
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    //dp[i][j]=i-dp[i+1][j-1]||j-dp[]
    for(int gap=1;gap<=n;gap++)
    {
        for(int i=0;i<n;i++)
        {
            int j=i+gap-1;
            if(i==j) dp[i][j]=a[i];
            else if(j<n)
            {
                dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
            }

        }
    }
    cout<<dp[0][n-1]<<endl;
}