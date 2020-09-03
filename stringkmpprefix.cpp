class Solution {
public:
    int solve(string s,map<string,int> &m)
    {
        cout<<s<<endl;
        int n=s.length();
        vector<int> dp(n);
        dp[0]=0;
        if(s[0]==s[1]) dp[1]=1;
        for(int i=2;i<n;i++)
        {
           
                int j=i-1;
                while(j>=0)
                {
                    if((dp[j]<=(i-1)/2))
                    {if(s[i]==s[dp[j]]) { dp[i]=dp[j]+1; break;    }
                    else j=dp[j]-1;
                    }
                    else {
                        int f=0;
                        j=dp[j]-1;
                        while(j>=0)
                            {
                            if(s[i]==s[j]) {dp[i]=j+1;f=1;break;}
                            //if(j==0) break;
                            j=dp[j];
                            
                        
                             }
                        if(f==1||j<=0) break;
                         }
                }
            
            
        }
        // for(auto it: dp) cout<<it<<" ";
        // cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(2*dp[i]==i+1) 
            {
                string t;
                for(int j=0;j<=i;j++) t+=s[j];
                if(t!="")
                m[t]++;
            }
//             if(2*dp[i]==i+1) {
//                 ans++;
//                 string t;
//                 for(int j=0;j<=i;j++ )
//                 {
//                     t+=s[j];
//                 }
//                  if(t!="")
//                 m[t]++;
                
//             } 
//             else  if(dp[i]==i)
//             {
//                 if((i+1)%2==0)
//                 {
//                  string t;
//                  for(int j=0;j<=i;j++ )
//                   {
//                     t+=s[j];
//                   }
//                     if(t!="")
//                  m[t]++;
                    
//                 }
               
                
       //     }
        }
      //  cout<<ans<<endl;
        return ans;
    }
    int distinctEchoSubstrings(string s) {
        int n=s.length();
        int ans=0;
        map<string,int> m;
        for(int i=0;i<n;i++)
        {
            ans+=solve(s.substr(i,n-i),m);
            
        }
        cout<<"**********\n";
        for(auto it:m)
            cout<<it.first<<" "<<it.second<<endl;
        return m.size();
        
    }
};