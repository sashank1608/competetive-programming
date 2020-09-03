#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int n,m;
    cin>>n>>m;
     vector<vector<ll>> voters(m+1);
    // vector<pair<int,ll> > vec;
     vector<int > g;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        voters[x].pb(y);
        
        
    }
   
   int mx=0;
    for(int i=1;i<=m;i++)
    {
        mx=max(mx,(int)voters[i].size());
      sort(voters[i].begin(),voters[i].end());
    }
    ll ans=1e18;
    for(int fval=1;fval<=n;fval++)
    {
        int inval=voters[1].size();
        int req=max(0,fval-inval);
        vector<int > cost;
        int idx=0;
        ll sum=0;
        for(int j=2;j<=m;j++)
        {
            if(voters[j].size()>=fval)
            {
                int it=voters[j].size()-fval+1;
               // it=min(it,voters[j].size());
                for(int k=0;k<it;k++)
                {
                  //  cost.pb(voters[j][k]);
                   sum+=voters[j][k];
                }
                idx+=it;
                for(int k=it;k<voters[j].size();k++)
                {
                    cost.pb(voters[j][k]);
                }
            }
            else
            {
                for(int k=0;k<voters[j].size();k++)
                {
                    cost.pb(voters[j][k]);
                }
            }
            


        }
        // cout<<req<<" "<<idx<<" "<<sum<<endl;
        // for(auto u : cost ) cout<<u<<" ";
        // cout<<endl;
         if(req>=idx)
        {
            sort(cost.begin(),cost.end());
           // ll sum=0;
            for(int i=0;i<req-idx;i++)
            {
                sum+=cost[i];
            }
            ans=min(ans,sum);
        }
    }
    cout<<ans<<endl;
  
   
}