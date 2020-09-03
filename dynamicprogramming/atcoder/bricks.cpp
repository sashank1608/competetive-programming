#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define ll long long

int main()
{
int t;
cin>>t;
ll m=1e9;
while(t--)
{

int n;
cin>>n;
//vector<int> fake(m+1);
set<pair<ll,ll> > s;
for(int i=0;i<n;i++)
{
    ll l,r;
    cin>>l>>r;
    s.insert(make_pair(l,r));
}
 pair<ll,ll> cur=*s.begin();
 ll ans=0;
while(!s.empty())
{
   
    s.erase(s.begin());
    if(s.empty()) {
        ans+=(cur.second-cur.first+1);
        break;
    }
    pair<ll,ll> it=*s.begin();
    if(it.first<=cur.second&&it.second>=cur.second)
    {
        cur.second=it.second;
    }
    else
    {
        ans+=(cur.second-cur.first+1);
        cur.first=it.first;
        cur.second=it.second;
        
    }
    

}
cout<<ans<<endl;

}
}