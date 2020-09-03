#include <bits/stdc++.h>
using namespace std;
int solve(int n,int k,int x)
{
       if(n==1) return 1;
    return (k-1)*solve(n-1,k,(x+1)%k);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x;
        cin>>n>>k>>x;
        //cout<<solve(n,k,x)<<endl;
        int a[n+1]={},b[n+1]={};
        if(x==1) a[1]=1;
        else b[1]=1;
      
        for(int i=2;i<=n;i++)
        {
            a[i]=b[i-1];
            b[i]=a[i-1]*(k-1)+b[i-1]*(k-2);

        }
        cout<<a[n];
    }

}