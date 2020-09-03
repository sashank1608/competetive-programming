#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
     long long  mod=1e9+7;
    while(t--)
    {
        int a;
     cin>>n>>a;
     long long rem=1;
      long long  sum=0;
   
     
     
     for(int i=1;i<=n;i++)
     {
      
        //  for(int y=1;y<=2*i-1;y++)
        //  {
        //        base*=a;
        //  }
          long long p1=1,p2=1;;
         for(int j=1;j<=i-1;j++)
         {
            
            p1*=(a*rem);
            p1=p1%mod;

         }
         for(int k=n-i+1;k<=n;k++)
         {
              
             p2*=(a*rem);
             p2=p2%mod;
         }
         sum+=((p1*p2));
         sum=sum%mod;
         rem*=(p1*p2);
         rem=rem%mod;
        //  cout<<"sum rem "<<sum<<" "<<rem<<endl;




     }
     cout<<sum<<endl;

     }
        
       
      
        
    
}