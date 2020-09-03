#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[n];
        map<ll ,ll> m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]++;

        }
       
        vector<pair<ll,ll> >vec;
        int sz=m.size();
        int chk[sz]={};
        for(auto it : m)
        {
          vec.pb({it.first,it.second});

        }
      
     
 
 ll dp[sz+1]={};
 dp[0]=vec[0].first*vec[0].second;
 for(int i=1;i<sz;i++)
 {
     dp[i]=max(dp[i-1],dp[i]);
     if(vec[i-1].first+1==vec[i].first) dp[i]=max(dp[i],(i>1)? dp[i-2]+vec[i].first*vec[i].second:vec[i].first*vec[i].second);
     else dp[i]=max(dp[i],dp[i-1]+vec[i].first*vec[i].second);
 }
 cout<<dp[sz-1]<<endl;;
//  for(auto i:dp)
//  {
//      cout<<i<<" ";
//  }

 

    }



}