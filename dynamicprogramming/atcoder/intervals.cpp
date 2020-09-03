#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18L+5;
const int nax= 2e5+30;
vector<ll> dp(nax,0);
vector<ll> tree(4*nax);
vector<ll> lazy(4*nax);
void build(int v,int tl,int tr) 
{
    if(tl>tr) return;
    if(tl==tr)
    {
        tree[v]=dp[tl];
        return;
    }
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    tree[v]=min(tree[2*v],tree[2*v+1]);
}
void push(int v)
{
    tree[2*v]+=lazy[v];
    tree[2*v+1]+=lazy[v];
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    lazy[v]=0;
}
void add(int v,int tl,int tr,int l,int r,ll sum)
{
    int tm=(tl+tr)/2;
    if(l>r) return;
    if(tl>=l&&tr<=r)
    {
        lazy[v]+=sum;
        tree[v]+=sum;
        return;

    }
    else
    {
        push(v);
        add(2*v,tl,tm,l,min(tm,r),sum);
        add(2*v+1,tm+1,tr,max(l,tm+1),r,sum);
        tree[v]=min(tree[2*v],tree[2*v+1]);
    }
    

}
ll get_min(int v,int tl,int tr,int l,int r)
{
    if(l>r) return inf;
    if(tl>=l&&tr<=r)
    {
        return tree[v];
    }
    else
    {
        push(v);
        int tm=(tl+tr)/2;
        return(min(get_min(2*v,tl,tm,l,min(tm,r)),get_min(2*v+1,tm+1,tr,max(l,tm+1),r)));
    }
    
}
void update(int v,int tl,int tr,int pos,ll val)
{
    if(tl>tr) return;
    if(tl==tr)
    {
        tree[v]=val;
       // dp[tl]=val;
        return;
    }
    int tm=(tl+tr)/2;
     push(v);
    if(pos<=tm)
    {
       
        update(2*v,tl,tm,pos,val);
    }
    else update(2*v+1,tm+1,tr,pos,val);
    tree[v]=min(tree[2*v],tree[2*v+1]);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll>  > > vec(n+1);
    ll sum=0;
    for(int i=0;i<m;i++)
    {
        int l,r;ll a;
        cin>>l>>r>>a;
        sum+=a;
        vec[r].push_back({l,a});
    }
    dp[0]=0;
    build(1,0,n+1);
    for(int i=1;i<=n+1;i++)
    {
        for(auto it:vec[i-1])
        {
           // if(it.first>=1)
        //    if(it.first==1)
        //    {
        //        update(1,0,n+1,0,)
        //    }
            add(1,0,n+1,0,it.first-1,it.second);
            // for(int j=1;j<it.first;j++)
            // {
            //     dp[j]+=it.second;
            //     //dp[i]=max(dp[i],dp[j]+)
            // }
        }
        dp[i]=get_min(1,0,n+1,0,i-1);
       // add(1,0,n+1,i,i,(ll)(dp[i]-inf));
        update(1,0,n+1,i,dp[i]);



    }
    ll ans=sum-dp[n+1];
   // cout<<tree[0]<<endl;
   // for(auto it=0;it<=n+1;it++) cout<<dp[it]<<" ";
 //   cout<<endl;
    // for(int i=1;i<=n+1;i++)
    // {
    //     ans=min(ans,dp[i]);

    // }

    cout<<ans<<endl;

}