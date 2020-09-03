#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define pb push_back
#define ll long long
const int nax=1e5+5;
 vector<vector<ll> > bit(nax,vector<ll>(12));

int g(int i)
{
  return i&(i+1);
}
int h(int i)
{
    return i|(i+1);
}
ll getsum(int l,int len)
{
    ll ret=0;
    while(l>=0)
    {
        ret+=bit[l][len];
        l=g(l)-1;
    }
    return ret;

}
void update(int l,int len,ll x)
{
    for(;l<nax;l=l|(l+1))
    {
        bit[l][len]+=x;

    }

}
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    ll ans=0;
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i++)
    {
        for(int j=k+1;j>=2;j--)
        {
            ll k1=getsum(a[i]-1,j-1);
            if(k1>0)
            {
                if(j==k+1) ans+=k1;
                update(a[i],j,k1);
            }
        }
        update(a[i],1,1);
    }
    if(k==0) cout<<n<<endl;
    else if(k>=n) cout<<"0"<<endl;
    else
    cout<<ans<<endl;
   
}