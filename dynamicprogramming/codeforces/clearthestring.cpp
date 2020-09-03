#include<bits/stdc++.h>
using namespace std;
//int dp[501][501];
const int inf=600;
vector<vector<int> > dp(501,vector<int>(501,inf));
int main()
{
    int n;
    cin>>n;
    string p,s;
    cin>>p;
    for(int i=0;i<n;i++)
    {
        if(!s.empty())
        {
            if(s.back()!=p[i]) s+=p[i];

        }
        else s+=p[i];
    }
  //  cout<<s<<endl;
    int m=s.length();
   // int dp[m][m];//minimum no of removals req to make it empty
    for(int i=m-1;i>=0;i--)
    {
        for(int j=i;j<m;j++)
        {
            if(i==j) dp[i][j]=1;
            else{
                 if(s[i]==s[j]) {  dp[i][j]=min(dp[i][j],1+dp[i+1][j-1]);}
              

                for(int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                    if(s[i]==s[k+1]) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]-1);
                    

                }
            }
        }
    }
   cout<<dp[0][m-1]<<endl;

}