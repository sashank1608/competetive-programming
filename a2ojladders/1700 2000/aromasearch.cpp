#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x0,y0,ax,bx,ay,by,xs,ys,t;
    cin>>x0>>y0>>ax>>ay>>bx>>by;
    cin>>xs>>ys>>t;
     
     ll lim=(1LL<<55)-1;
     vector<ll> x(1,x0),y(1,y0);

     while((lim-bx)/ax>=x.back()&&(lim-by)/ay>=y.back())
     {
         x.pb(ax*x.back()+bx);
         y.pb(ay*y.back()+by);
     }
     int n=x.size();
     int ans=0;
     for(int i=0;i<n;i++)
     {
         for(int j=i;j<n;j++)
         {
             ll dist=abs(x[i]-x[j])+abs(y[i]-y[j]);
             ll dist_left=abs(xs-x[i])+abs(ys-y[i]);
             ll dist_right=abs(xs-x[j])+abs(ys-y[j]);
             if(t-dist_left>=dist||t-dist_right>=dist) ans=max(ans,j-i+1);

         }
     }
     cout<<ans<<endl;

    

}