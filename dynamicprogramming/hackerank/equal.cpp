#include <bits/stdc++.h>
using namespace std;
int calc(int k)
{
    int ans=k/5;
    k=k%5;
    ans+=k/2;
    k=k%2;
    ans+=k;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int min1=INT_MAX,ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            min1=min(min1,a[i]);
        }
        for(int j=0;j<5;j++)
        {
             int sum=0;
         for(int i=0;i<n;i++)
         {
            
            sum+=calc(abs(a[i]-(min1-j)));
         }
         ans=min(ans,sum);

        }
        cout<<ans<<endl;


    }
}