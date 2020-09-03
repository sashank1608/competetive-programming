#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,W;
    cin>>n>>W;
    int w[n],v[n];
    //dp[w] max value possible for given weight
    //dp_value[V] min possible weight for value V
    for(int i=0;i<n;i++) cin>>w[i];
     for(int i=0;i<n;i++) cin>>v[i];
  //  int W=accumulate(w,w+n,0);
  int V=accumulate(v,v+n,0);
  int dp_value[V+1];
    int dp[W+1];
    //  for(int i=0;i<=W;i++) dp[i]=-1;
    // dp[0]=0;
     for(int i=0;i<=V;i++) dp_value[i]=10000;
     dp_value[0]=0;
    
    // for(int j=0;j<n;j++)
    
    // {
    //     for(int i=V;i>=1;i--)
    //     {
    //        dp[i]=(i-w[j]>=0)?max(dp[i],dp[i-w[j]]+v[j]):dp[i];
    //     }
    // }
      for(int j=0;j<n;j++)
    
    {
        for(int i=V;i>=1;i--)
        {
           dp_value[i]=(i-v[j]>=0)?min(dp_value[i],dp_value[i-v[j]]+w[j]):dp_value[i];
           if(i==60||i==100||i==160||i==120||i==180||i==220)
           {
               cout<<i<<" "<<dp_value[i]<<" "<<v[j]<<endl;
           }
        }
    }
    int ans=0;
    for(int i=0;i<=V;i++)
    {
       // cout<<"("<<dp_value[i]<<" "<<i<<") ";
        if(dp_value[i]<=W) {ans=i;}
        
    }
    cout<<endl;
    cout<<ans<<endl;
}