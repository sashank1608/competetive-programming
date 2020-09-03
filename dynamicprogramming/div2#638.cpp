#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
       int a[n];
       for(int i=0;i<n;i++) cin>>a[i];
       unordered_map<int,int> m;
       vector<int>ans;
        for(int i=0;i<k;i++){ m[a[i]]++;ans.pb(a[i]);}
        int flag=1;
        //cout<<
       for(int i=1;i<=n-k;i++)
       {
           
           
             if(m.count(a[i+k-1])<=0) { flag=0;break;}
            
          
           //if(!flag){break;}
       }
       if(flag)
       {
           if(n!=k){
           int c=0;
           int i=1;
           while(1)
           {
              if(ans[i-1]!=a[i+k-1-c]) { ans.pb(ans[i-1]);c++;}
              else{ 
                  ans.pb(ans[i-1]);
              if(i+k-c-1==n-1) break;
              }
              i++;
           }
           }
           cout<<ans.size()<<endl;
           for(auto j : ans) cout<<j<<" ";
           cout<<endl;
       }
       else cout<<"-1"<<endl;
          //  m.clear();
    }
}