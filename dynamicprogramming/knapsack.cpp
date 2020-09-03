/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
 how many ways can we make the change? The order of coins doesn’t matter.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  int a[m];
  for(int i=0;i<m;i++)
  {
      cin>>a[i];
  }
  //dp[i][j] no of ways to make sum i using frst j coins
  int dp[n+1][m];
  for(int i=0;i<=n;i++)
  {
      for(int j=0;j<m;j++)
      {
          if(i==0) dp[i][j]=1;
          else
          dp[i][j]=0;
      }
  }
  //push
//   for(int i=0;i<=n;i++)
//   {
//       for(int j=0;j<m;j++)
//       {
//           if(i+a[j]<=n)
//           dp[i+a[j]][j]+=dp[i][j];
//           if(i!=0&&j+1<m)
//           dp[i][j+1]+=dp[i][j];
//       }
//   }

  for(int i=0;i<=n;i++)
  {
      for(int j=0;j<m;j++)
      {
          dp[i][j]+=(i-a[j]>=0)? dp[i-a[j]][j]:0;
          if(i!=0)
          dp[i][j]+=(j-1>=0)? dp[i][j-1]:0;
      }
  }
    cout<<endl;
  for(int i=0;i<=n;i++)
  {
      for(int j=0;j<m;j++)
      {
          cout<<dp[i][j]<<" ";
      }
      cout<<endl;
  }
  cout<<dp[n][m-1]<<endl;
}