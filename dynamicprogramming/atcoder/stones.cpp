#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    bool dp[k+1]={};
    dp[0]=0;
    for(int sum=0;sum<=k;sum++)
    {
        for(int j=0;j<n;j++)
        {
            if(sum-a[j]>=0) dp[sum]|=!dp[sum-a[j]];
             
        }
    }
    if(dp[k]) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}