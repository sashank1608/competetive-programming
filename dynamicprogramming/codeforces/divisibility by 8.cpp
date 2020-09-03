#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s;
   getline(cin, s);
   int n=s.length();

   bool dp[n][8]={{}};
   int prev[n][8]={{}};
   memset(prev, -1, sizeof(prev));
 
  // for(int i=0;i<8;i++) prev[0][i]=-1;
//for(int i=0;i<8;i++)
   dp[0][(s[0]-'0')%8]=true;
  // dp[0][0]=1;
   for(int i=1;i<n;i++)
   {
      dp[i][(s[i]-'0')%8]=true;
  // dp[0][0]=1;
       for(int j=0;j<8;j++)
       {

          if(dp[i-1][j])
          {
           

            dp[i][(10*j+s[i]-'0')%8]=true;
           
             prev[i][(10*j+s[i]-'0')%8]=j;
              dp[i][j]=true;
            
             prev[i][j]=j;
          }


       }
   }
   int f=1;
  
   for(int i=0;i<n;i++)
   {
       if(dp[i][0])
       {
   int it=i;
   int j=0;
   string ans="";
   while(true)
   {

       //cout<<prev[i][0]<<endl;
       if(prev[it][j]!=j||prev[it][j]==-1) ans+=s[it];
       if(prev[it][j]==-1) break;
        j=prev[it][j];
       it--;
      
   }
   reverse(ans.begin(),ans.end());
   cout<<"YES"<<endl;
   cout<<ans<<endl;
   f=0;
   break;
       }
  
    
   }
   if(f)
   cout<<"NO"<<endl;


}
