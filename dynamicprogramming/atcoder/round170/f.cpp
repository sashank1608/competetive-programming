#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define pb push_back
#define ll long long
int main()
{
    int n,k;
    cin>>n>>k;
    //int a[n];
   // for(int i=0;i<n;i++) cin>>a[i];
        string s,t;
        cin>>s;
        t=s;
    for(int i=0;i<n;i++)
    {
        if(i-k>=0) s[i]=s[i-k];

    }
    if(s<t)
    {
        if(s[k-1]=='9')
        {
            int j;
            for( j=k-2;j>=0;j--)
            {
                if(s[j]!='9') break;
            }
            s[j]=(char)(s[j]+1);
            j++;
            while(j<k) {s[j]='0';j++;}
            

        }
        else s[k-1]=(char)(s[k-1]+1);
        
        // int f=0;
        // for(int j=k-1;j>=0;j--)
        // {
        //     if(s[j]=='9') {
        //         f=1;
        //         if(j==0)
        //         {
        //             int k1=1;
        //             while(k1<k)
        //             {
        //                 if(s[k1]!='9') break;
        //                 k1++;
        //             }
        //             s[k1]=(char)(s[k1]+1);
                   
        //         }
        //         else
        //         {
        //            s[j]='0';
        //            s[j-1]=(char)(s[j-1]+1);
                  
        //         }
        //         break;
                
        //     }

        // }
        // if(!f)
        // {
        //     int idx=min(n-1,k-1);
        //     s[idx]=(char)(s[idx]+1);
        // }
        for(int j=0;j<n;j++)
        {
            if(j-k>=0) s[j]=s[j-k];
        }
        assert(s>=t);
        cout<<s.length()<<endl;
        cout<<s<<endl;
    }
    else { cout<<s.length()<<endl;cout<<s<<endl;}


}