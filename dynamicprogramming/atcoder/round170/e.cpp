#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define pb push_back
#define ll long long
#define ld double
int main()
{
    int n;
    cin>>n;
    int a[2*n],b[2*n];
    for(int i=0;i<2*n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+2*n);
    vector<ld> hi,lo;
    ld myrat=(ld)(a[0]+a[2*n-1])/2;
    ld myrat1=(ld)(a[0]+a[1])/2;
    lo.pb(myrat1);
    hi.pb(myrat);
    int i=1;
    int j=2*n-2;
    while(i<j)
    {
        if((ld)(a[i]+a[j])/2<=myrat)
        {
             hi.pb((ld)(a[i]+a[j])/2);
            i++;
            j--;
            

        }
        else
        {
             hi.pb((ld)(a[j-1]+a[j])/2);
             j-=2;
            
        }
        
       
    }
    sort(hi.begin(),hi.end());
    // auto k1=unique(hi.begin(),hi.end());
    // hi.resize(distance(hi.begin(),k1));
    for(auto j:hi) cout<<j<<" ";
    cout<<endl;
    auto it=upper_bound(hi.begin(),hi.end(),myrat);
    int ans1=hi.end()-it+1;
    i=2;
    j=2*n-1;
    while(i<j)
    {
         if((ld)(a[i]+a[j])/2>myrat1)
        {
             lo.pb((ld)(a[i]+a[j])/2);
            i++;
            j--;
            

        }
        else
        {
             lo.pb((ld)(a[i]+a[i+1])/2);
             i+=2;
            
        }

    }
     sort(lo.begin(),lo.end());
    // unique(lo.begin(),lo.end());
    // auto k2=unique(lo.begin(),lo.end());
    // lo.resize(distance(lo.begin(),k2));
    for(auto j:lo) cout<<j<<" ";
    cout<<endl;
    auto it1=upper_bound(lo.begin(),lo.end(),myrat1);
    int ans2=lo.end()-it1+1;
  cout<<ans1<<" "<<ans2<<endl;


}