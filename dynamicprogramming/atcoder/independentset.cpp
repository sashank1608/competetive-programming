#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int nax=1e5+5;
vector<vector<int> > adj(nax);
int mul(int a,int b)
{
    return ((1LL)*a*b)%mod;
}
pair<int,int > dfs(int u,int p)
{
    pair<int,int> ans={1,1};
    if(adj[u].size()==1&&adj[u][0]==p) return ans;//if leaf
    for(auto v: adj[u])
    {
        pair<int,int> cur;
        if(v==p) continue;
       cur= dfs(v,u);
       ans.first=mul(ans.first,((cur.first+cur.second)%mod));
       ans.second=mul(ans.second,cur.first);
    }
  //  cout<<ans.first<<" "<<ans.second<<endl;
    return ans;
}
int main()
{

int n;
cin>>n;
for(int i=0;i<n-1;i++)
{
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);

}
pair<int,int >ans=dfs(1,-1);
cout<<(ans.first+ans.second)%mod;


}