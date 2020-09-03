#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define ll long long

int main()
{
int t;
cin>>t;
while(t--)
{
    ll x,a,b;
    cin>>x>>a>>b;
    ll lcm=(a*1LL*b)/(__gcd(a,b));
    cout<<x+lcm<<endl;
}
}