#include<bits/stdc++.h>
using namespace std;
int main()
{
   vector<string> vec;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>vec[i];
   }
   int dp[n][n][n][n];
   //dp[i][j][k][r] max apples collected till row y till cols i j k
   /*  dp[i][j][k][r]=max(dp[i][j][k][r-1]+mat[r][i]+mat[r][j]+mat[r][k],) */
   for(int i=0;i<n-2;i++)
   for(int j=i+1;j<n-1;j++)
   for(int k=j+1;k<n;k++)
   {
       int p=(i>0)?
   }
}