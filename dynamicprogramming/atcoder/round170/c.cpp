#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define pb push_back
#define ll long long
int main()
{
    int n;
    cin>>n;
    int a[n];
   multiset<int> s;
    for(int i=0;i<n;i++) {cin>>a[i];s.insert(a[i]);}
  int ans=0;
     for(int i=0;i<n;i++)
     {
         int f=1;
         for(int j=1;j<=sqrt(a[i]);j++)
         {
            
              if(a[i]%j==0)
             {
                 if(j!=1)
                 {
                     if(s.count(j)>0||s.count(a[i]/j)>0){
                         f=0;
                         break;
                         }
                 }
                  else if(j==1)
                    {
                 if(a[i]==1&&(s.count(1)>1)){
                     f=0;
                 break;
                 }
                 else if(s.count(1)>0||(s.count(a[i])>1))
                 {
                    // cout<<a[i]<<endl;
                     f=0;
                     break;
                     
                 }
                  
                 
                 //continue;
             }
     
             }
             

         }
         
         if(f){//cout<<i<<endl;
         ans++;} 
     }
     cout<<ans<<endl;

     
     

}