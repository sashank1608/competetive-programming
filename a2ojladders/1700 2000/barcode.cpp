#include<bits/stdc++.h.>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<string > vec(n+1);
    for(int i=1;i<=n;i++)
    {
       cin>>vec[i];
       vec[i]=' '+vec[i];
    }
    vector<int > black(m+1),white(m+1);
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(vec[i][j]=='#') black[j]++;
            else if(vec[i][j]=='.') white[j]++;
            
        }
    }
    // for(auto it : black)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it : white)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    int dp[m+1][2][y+1];
    for(int i=0;i<=m;i++)
    {
        
            for(int k=0;k<=y;k++)
            {
                dp[i][0][k]=INT_MAX;
                 dp[i][1][k]=INT_MAX;
            }
       
    }
     dp[1][0][1]=black[1];
     dp[1][1][1]=white[1];
     // 0 white
     // 1 black
     for(int i=2;i<=m;i++)
    {
       
      for(int k=2;k<=y;k++)
      {
                if(dp[i-1][0][k-1]<INT_MAX)
          dp[i][0][k]=min(dp[i][0][k],dp[i-1][0][k-1]+black[i]);
          if(dp[i-1][1][k-1]<INT_MAX)
          dp[i][1][k]=min(dp[i][1][k],dp[i-1][1][k-1]+white[i]);
 
        }

         for(int j=x;j<=y;j++)
        {
            
                 if(dp[i-1][1][j]<INT_MAX)
             dp[i][0][1]=min(dp[i][0][1],dp[i-1][1][j]+black[i]);

                if(dp[i-1][0][j]<INT_MAX)
             dp[i][1][1]=min(dp[i][1][1],dp[i-1][0][j]+white[i]);

            
        }
    }
//    for(int i=1;i<=m;i++)
//    {
//        for(int j=1;j<=y;j++)
//        {
//             cout<<"{"<<dp[i][0][j]<<" "<<dp[i][1][j]<<"} ";
//        }
//        cout<<endl;
//    }
        int ans=INT_MAX;
        for(int k=x;k<=y;k++)
        {
           // cout<<dp[m][0][k]<<" "<<dp[n][1][k]<<endl;
            ans=min({ans,dp[m][0][k],dp[m][1][k]});

        }
        cout<<ans<<endl;
   

}


