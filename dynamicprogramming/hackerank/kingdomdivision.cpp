#include <bits/stdc++.h>
using namespace std;
#define pb push_back
//dp1 s,col,ally
//dp2 s,col,ally, idx
const int nmax=1e5+1;
const int mod=1e9+7;
vector<vector<int> > g(nmax);
int done[nmax][2][2],memo[nmax][2][3];
long long dp2(int s,int p,int col,int ally,int idx);
 long long dp(int s,int p,int col,int ally)
{
    return dp2(s,p,col,ally,0);
}
 long long dp2(int s,int p,int col,int ally,int idx)
{
      if(idx==g[s].size())
      {
          return ally;
      }
      int t=g[s][idx];
      if(t==p) return dp2(s,p,col,ally,idx+1);
      if(done[t][col][ally]) return memo[t][col][ally];
      done[t][col][ally]=1;
      
      long long temp=dp(t,s,col,1)*dp2(s,p,col,1,idx+1);
       long long zing=dp(t,s,col^1,0)*dp2(s,p,col,ally,idx+1);
      // temp+zing;
      temp%=mod;
      temp+=(zing%mod);
       temp%=mod;
       return memo[t][col][ally]=temp;


}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[b].pb(a);
        g[a].pb(b);
    }
    int ans=dp(1,0,0,0)+dp(1,0,1,0);
    cout<<ans<<endl;
}