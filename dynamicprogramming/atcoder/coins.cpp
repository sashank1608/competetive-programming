#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
  double dp[3000][3000];
int main()
{
    int n;
   // cin>>n;
   scanf("%d",&n);
    double p[n+1];
    for(int i=1;i<=n;i++) cin>>p[i];
   
    dp[0][0]=1.0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i][j]+=(j>0)? p[i]*dp[i-1][j-1]:0;
            dp[i][j]+=(j<i)? (1-p[i])*dp[i-1][j]:0;
        }


    }
   double sum=0.0;
    
        for(int j=0;j<=n;j++)
        {
           // cout<<dp[n][j]<<" ";
            if(j>n-j) sum+=dp[n][j];

        }
      //  printf("%lf\n",sum);
        cout<<setprecision(10)<<sum<<endl;

    
}
