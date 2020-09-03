#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+1;
int dp[nmax];
int indegree[nmax];
int visit[nmax];
void dfs(int u,vector<vector<int> > &adj)
{
    for(auto v :adj[u])
    {
        dp[v]=max(dp[v],dp[u]+1);
        indegree[v]--;
        if(indegree[v]==0&&!visit[v]) 
        {
            visit[v]=1;
            dfs(v,adj);
        }
    }



   // visit[u]=1;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> >adj(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
       // adj[y].push_back(x);
    } 
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0&&!visit[i]) dfs(i,adj);
    }
    int ans=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;

    

}