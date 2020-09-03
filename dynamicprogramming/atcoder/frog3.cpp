#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct line
{
   ll  m;
   ll c;
   ll eval(int x)
   {
       return (1LL*m*x+c);

   }
   long double insertX(line l)
   {
       return (long double)(c-l.c)/(l.m-m);

   }

};
int main()
{
    int n;
    ll C;
    cin>>n>>C;
    ll h[n];
    deque<line> hull;
    hull.push_back({0,0});
    for(int i=0;i<n;i++) cin>>h[i];
    vector<ll> dp(n);
    ll ans;
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        while(hull.size()>=2&&(hull.back().eval(h[i])>hull[hull.size()-2].eval(h[i]))) hull.pop_back();
        ll best=hull.back().eval(h[i])+1LL*h[i]*h[i]+C;
         if(i==0) best=0;
        dp[i]=best;
       
        ll intercept=best+1LL*h[i]*h[i] ;   
        if(i==n-1){ans=intercept;}
        line l1={-2*1LL*h[i],intercept};
        while(hull.size()>=2&&hull[1].insertX(l1)<hull[0].insertX(hull[1]))
        {
            hull.pop_front();

        }
        hull.push_front(l1);

    }
    cout<<dp[n-1]<<endl;

}