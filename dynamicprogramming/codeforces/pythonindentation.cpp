#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int mod=1e9+7;
const int nax=5001;
vector<vector<int> > dp(5001,vector<int>(5001,-1));
vector<vector<int> > pref(5001,vector<int>(5001,-1));
 vector<char> s(5001);
int n;
int rec(int i,int ind,char prev)
{
    if(i==n) return 1;
    if(dp[i][ind]!=-1) return dp[i][ind];
    
    if(prev=='f')
    {
        return dp[i][ind]=rec(i+1,ind+1,s[i]);
    }
    else
    {
        if(pref[i+1][ind]==-1)
        {
           // pref[i+1][ind]=(pref[i+1][ind-1]+rec(i+1,ind,s[i]));
           int j;
           for( j=ind;j>=0;j--)
           {
               if(pref[i+1][j]!=-1) break;
           }
           j++;
          // cout<<i+1<<" "<<ind<<" "<<j<<"\n";
           for(int k=j;k<=ind;k++)
           {
               if(k>0)
               pref[i+1][k]=(pref[i+1][k-1]+rec(i+1,k,s[i]))%mod;
               else   pref[i+1][k]=(rec(i+1,k,s[i]))%mod;
           }
        }
        
        int l=pref[i+1][ind];
        // for(int in=0;in<=ind;in++)
        // {
        //     l=(l+rec(i+1,in,s[i]))%mod;
        // }
        return dp[i][ind]=l%mod;
    }
    

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d",&n);
   //s.resize(n);
   // dp.resize(n,vector<int>(n+1,-1));
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&s[i]);
    }

    printf("%d\n",rec(0,0,'s'));


}