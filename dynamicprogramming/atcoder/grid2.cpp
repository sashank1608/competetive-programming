#include<bits/stdc++.h>
using namespace  std;
#define ll long long
const int mod=1e9+7;
const int nmax=2e5+5;
int fact[nmax],inv_fact[nmax];
int mul(int a,int b)
{
    return (ll) a* b %mod;
}
int pow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b%2) ans=mul(ans,a);
        a=mul(a,a);
        b/=2;
    }
   // cout<<ans%mod<<endl;
    return ans%mod;
}
int inverse(int a)
{
    return pow(a,mod-2);
}
int binomial(int a,int b)
{
    if(a<b||a<0||b<0) return 0;
    // cout<<fact[a]<<" ";
    // cout<<inverse(fact[b])<<endl;

    return mul(fact[a],mul(inverse(fact[b]),inverse(fact[a-b])))%mod;
}
int f(int a,int b)
{
    return binomial(a+b,b);
}
//int dp[3002];
int main()
{
     fact[0]=inv_fact[0]=1;
     for(int i=1;i<nmax;i++)
     {
         fact[i]=mul(i,fact[i-1]);
         inv_fact[i]=inverse(fact[i]);
     }
   //  cout<<(pow(2,4));
    //  cout<<binomial(23,10);
    int h,w,n;
    cin>>h>>w>>n;
    vector<pair<int,int> > points;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        points.push_back({a,b});

    }
    sort(points.begin(),points.end(),[](pair<int,int> a,pair<int,int> b){return a.first+a.second<b.first+b.second;});
    //dp[i] no of paths to this wall forr forst time not including pevious walls
    points.emplace_back(h,w);
    vector<int> dp(n+1);
    for(int i=0;i<=n;i++)
    {
        //dp[i]=binomial(points[i].first+points[i].second-2,points[i].first-1);
        int tmp=f(points[i].first-1,points[i].second-1);
        for(int j=0;j<i;j++)
        {
            if(points[j].first<=points[i].first&&points[j].second<=points[i].second)
            {
                tmp=(tmp-mul(dp[j],f(points[i].first-points[j].first,points[i].second-points[j].second))+mod)%mod;
            }
        }
        dp[i]=tmp%mod;
    }
    cout<<dp[n];
   


}