#include<bits/stdc++.h>
using namespace std;
int solve(string s,string &t)
{
    if(s=="") return 0;
    int n=s.length();
    string s2=s;
    reverse(s2.begin(),s2.end());
    string s1=s+'#'+s2;
   // cout<<s1<<endl;
    //int dp[n];
    vector<int> dp(s1.length()+1);
    dp[0]=0;
    for(int i=1;i<s1.length();i++)
    {
        if(s1[i]==s1[dp[i-1]]) dp[i]=dp[i-1]+1;
        else
        {
            int j=i-1;
            while(j>=0)
            {
                if(s1[dp[j]]==s1[i]){dp[i]=dp[j]+1;break;}
                 j=dp[j]-1;
            }
        }
        

    }
    // for(auto it : dp) cout<<it<<" ";
    // cout<<endl;
            for(int i=0;i<dp[s1.length()-1];i++)
            {
                t+=s1[i];

            } //dp[s1.length()-1];

           if(dp[s1.length()-1]==0) t+=s1[0];
           return dp[s1.length()-1];

}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {

    //   cout<<solve("abcabcdefabc","")<<endl;;
    //   cout<<solve("abccababg","")<<endl;
      string s,t,p,ans;
      cin>>s;
      int n=s.length();
      int i;
      for( i=0;i<n;i++)
      {
            if(i<=n-1-i){
          if(s[i]!=s[n-1-i]) break;
          else  {ans+=s[i];
          if(i!=n-1-i) t+=s[i];}
            }
      }
    
      string s1="",s2="",s3;
      s3=s.substr(i,n-2*i);
     // cout<<s3<<endl;

      int n1=solve(s3,s1);

      reverse(s3.begin(),s3.end());

      int n2=solve(s3,s2);
    //    cout<<n1<<endl;
    //    cout<<s1<<endl;

    //   cout<<n2<<endl;
    //   cout<<s2<<endl;
      if(n1>n2)
      {
         // if(p==""&&s1=="") cout<<s[0];
         // cout<<s1;
         ans+=s1;

      }
      else { //if(p==""&&s2=="") cout<<s[0];
     // cout<<s2;
     ans+=s2;
      }
        reverse(t.begin(),t.end());
      ans+=t;
      //cout<<t;
     
    //cout<<"\n**********\n";
      cout<<ans<<endl;


  }
}