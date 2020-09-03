#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ll long long
int main()
{
    ll r,b,k;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>r>>b>>k;
        if(r>b) swap(r,b);
        ll g=__gcd(r,b);
        r/=g;
        b/=g;
        if(r==b) cout<<"OBEY\n";
        else
        {
            if(((b-2)/r)+1<k) cout<<"OBEY\n";
            else cout<<"REBEL\n";
        }
        
       
       
    }

}