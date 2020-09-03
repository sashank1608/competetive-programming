#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    int cnta=0,cntb=0;
    int j=0;
    int ans=INT_MIN;
     int maxch=0;
    for(int i=0;i<n;i++)
    {
          
           while(j<n)
           {
               
                
                if(maxch>k){ 
                  
                   if(s[i]=='a') cnta--;
                   else cntb--;
                    maxch=min(cnta,cntb);
                 break;

               }
               if(s[j]=='a') cnta++;
               else cntb++;
              
              
               j++;
               maxch=min(cnta,cntb);
                if(maxch<=k) ans=max(ans,j-i);
               
           }
    }
    cout<<ans<<endl;



}