#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int t=1;
   // cin>>t;
    while(t--)
    {
       
     int n;
    // cin>>n;
     int a[]={374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244};
   //  for(int i=0;i<n;i++) cin>>a[i];
   n=sizeof(a)/sizeof(a[0]);
     int inf=1e9+7;
     vector<int> dp1(n,-inf),dp2(n,-inf);
     dp1[0]=dp2[0]=1;
     for(int i=0;i<n;i++)
     {
         for(int j=i-1;j>=0;j--)
         {
              if(a[j]>a[i]) {
                  dp2[i]=max(dp2[i],1+dp1[j]);
              }
              else if(a[j]<a[i])
              {
                   dp1[i]=max(dp1[i],1+dp2[j]);
              }
              
         }
     }
     int ans=INT_MIN;
     for(int i=0;i<n;i++)
     {
         ans=max(ans,max(dp1[i],dp2[i]));
     }
     cout<<ans<<endl;


    }


}