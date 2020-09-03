#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
vector< vector<int> > adj(20,vector<int>(20));


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int mask=0;
     vector< vector<ll> > dp(1<<20,vector<ll>(20));
    vector<int> first(1<<20,-1);
    for(int i=0;i<n;i++)
    {
        first[1<<i]=i;
        dp[1<<i][i]=1;
    }
   
    for(mask=0;mask<(1<<n);mask++)
    {
        for(int k=0;k<n;k++)
        {
            if(mask&(1<<k)) 
            {
                first[mask]=k;
                break;
            }
        }
        vector<int> vec;
          for(int u=0;u<n;u++)
          {
              
              if(mask & 1<<u)
              {
                  vec.pb(u);
              }
          }
          for(auto i : vec)
          {
              for(auto j : vec)
              {
                  if(i==j||adj[i][j]==0) continue;
                 
                  if(first[mask]!=j) 
                  dp[mask][j]+=dp[mask^(1<<j)][i];
                
                  
                  
              }
          }
    }
    ll sum=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int j=0;j<n;j++)
        {
             if( __builtin_popcount(mask)>=3 && adj[first[mask]][j]==1 ) sum+=dp[mask][j];
        }
    }

    cout<<sum/2<<"\n";

    


}