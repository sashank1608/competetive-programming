#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
  int h,w;
int valid(int x,int y)
{
    if((x>=0&&x<h)&&(y>=0&&y<w)) return 1;
    return 0;
}
void add_self(long long &x,long long &y)
{
    x=(x+y)%mod;
}
int main()
{
  
    cin>>h>>w;
    int grid[h][w];
    long long dp[h][w];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            dp[i][j]=0;
            char x;
            cin>>x;
            if(x=='#')
            grid[i][j]=0;
            else  grid[i][j]=1;
        }
    }
    
    dp[0][0]=1;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(valid(i-1,j)&&grid[i-1][j]!=0) add_self(dp[i][j],dp[i-1][j]);
            if(valid(i,j-1)&&grid[i][j-1]!=0) add_self(dp[i][j],dp[i][j-1]);
        }
    }
    cout<<dp[h-1][w-1]%mod;
    

}