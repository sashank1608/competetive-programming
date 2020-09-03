#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


const int nmax=1e5+5;
int mod;
int n;
pair<int,int> in[nmax];
vector<int> child[nmax];
vector<pair<int,int> > downs[nmax],pref[nmax],suf[nmax];
pair<int,int> out[nmax];
vector<vector<int> > adj(nmax);
int mul(int a,int b)
{
    return(((1LL)*a*b)%mod);
}
void dfs_two(int u,int par)
{
   // if(u==par) continue;
    

          int k=child[u].size();
          for(int i=0;i<k;i++)
          {
               pair<int,int> p={1,1};
              if(i>0)
              {
                  p.first=mul(p.first,pref[u][i-1].first);
                  p.second=mul(p.second,pref[u][i-1].second);

              }
              p.first%=mod;
              p.second%=mod;
              if(i!=k-1)
              {
                   p.first=mul(p.first,suf[u][i+1].first);
                  p.second=mul(p.second,suf[u][i+1].second);
              }
                p.first%=mod;
              p.second%=mod;
              if(u!=1)
              {
                   p.first=mul(p.first,out[u].first);
                  p.second=mul(p.second,out[u].second);
              }
              out[child[u][i]]={p.first,(p.first+p.second)%mod};
              dfs_two(child[u][i],u);
          }
}
void dfs_one(int u,int par)
{
    pair<int,int> p={1,1};
    for(auto v:adj[u])
    {
        if(v==par) continue;
        child[u].pb(v);
        dfs_one(v,u);
        downs[u].pb({in[v].first,in[v].second});
         p.first=mul(p.first,in[v].first);
         p.second=mul(p.second,(in[v].first+in[v].second)%mod);
    }
    in[u].first=p.first;
    in[u].second=(p.second);
   


}

int main()
{
    cin>>n>>mod;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs_one(1,-1);
    for(int i=1;i<=n;i++)
    {
        pair<int,int> p1={1,1};
          int k=child[i].size();
        for(int j=0;j<k;j++)
        {
                        int ch=child[i][j];
             p1.first=mul(p1.first,in[ch].first);
             p1.second=mul(p1.second,(in[ch].second+in[ch].first)%mod)%mod;
             pref[i].pb(p1);
            //pref[i][j]=pref[i][j-1]+in[i].first;
        }
      
         pair<int,int> p2={1,1};
        for(int j=k-1;j>=0;j--)
        {
            int ch=child[i][j];
             p2.first=mul(p2.first,in[ch].first);
            p2.second=mul(p2.second,(in[ch].second+in[ch].first)%mod)%mod;
            suf[i].pb(p2);

        }
        reverse(suf[i].begin(),suf[i].end());
        
    }
    dfs_two(1,-1);
   // cout<<child[1].size();
    // cout<<endl;
    //  for(int i=1;i<=n;i++)
    //  {
    //      for(auto v:pref[i])
    //      {
    //          cout<<v.first<<" "<<v.second<<endl;
    //      }
    //  }
    //  cout<<endl;
    //   cout<<endl;
    //   for(int i=1;i<=n;i++)
    //  {
    //      for(auto v:suf[i])
    //      {
    //          cout<<v.first<<" "<<v.second<<endl;
    //      }
    //  }
    //   cout<<endl;
    //    cout<<endl;
    //   for(int i=1;i<=n;i++)
    //   {
    //       cout<<in[i].first<<" "<<in[i].second<<endl;
    //   }
    //   cout<<"**************"<<endl;
    //    for(int i=1;i<=n;i++)
    //   {
    //       cout<<out[i].first<<" "<<out[i].second<<endl;
    //   }
    //    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        pair<int,int> p={1,1};

        if(!child[i].empty())
        {
            p.first=mul(p.first,pref[i].back().first);
            p.second=mul(p.second,pref[i].back().second);
            p.second%=mod;
            p.first%=mod;

        }
        if(i!=1)
        {
            p.first=mul(p.first,out[i].first);
            p.second=mul(p.second,out[i].second);
              p.second%=mod;
               p.first%=mod;
        }
        cout<<p.second%mod<<endl;

    }



}