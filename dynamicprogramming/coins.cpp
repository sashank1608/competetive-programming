#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
      int n,q;
      cin>>n>>q;
      int cur=0;
      int s=0;
              int a,b;

      for(int i=0;i<q;i++)
      {
        cin>>a>>b;
        s+=(abs(cur-a)+abs(b-a));
      //  cout<<s<<endl;
        cur=b;
      }
       
       cout<<s<<endl;
       
       
     }
        
       
        
    
}