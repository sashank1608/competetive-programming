#include<bits/stdc++.h>
#define pb push_back
#define ll long long
const int mod=998244353 ;
using namespace std;
const int nax=1e5+7;
const int B=300;
struct bucket{
int id;
int first=B*id;
int last=(B+1)*id-1;

};
int main()
{
    int n,k;
    cin>>n>>k;
    vector<ll> a(n+1),cnt(n+1),dp(n+1);
    vector<vector<int>> occurences(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        occurences[i].pb(0);//fake
    
    }
    //dp[R] no of ways to partition till R
    auto add=[&](int a,int b,int ad){
        for(int i=a;i<=b;i++)
        {
            cnt[i]+=ad;
        }
    };
    dp[0]=1;
    for(int R=1;R<=n;R++)
    {
        if(occurences[a[R]].size()>1)
        add(occurences[a[R]].end()[-2]+1,occurences[a[R]].back(),-1);
        occurences[a[R]].pb(R);
        add(occurences[a[R]].end()[-2]+1,occurences[a[R]].back(),1);
        for(int L=0;L<R;L++)
        {
            if(cnt[L+1]<=k)
            {
                dp[R]+=dp[L];
                if(dp[R]>=mod) dp[R]-=mod;
            }
        }


    }
 //   for(auto it : dp) cout<<it<<" ";
  //  cout<<endl;
    cout<<dp[n]<<endl;

}