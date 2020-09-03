#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define ll long long
ll bsearch(ll A,vector<ll> &a,int st,int end)
{
    ll len=a[st-1];
    int lo=st;
    int hi=end;
    int ans=0;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(len*a[mid]<=A)
        {
            ans=mid;
            lo=mid+1;
        }
        else 
        hi=mid-1;
    }
 return ans;
}
int main()
{

int n;
cin>>n;
ll A;
vector<ll> a(n);
cin>>A;
for(int i=0;i<n;i++) cin>>a[i];
sort(a.begin(),a.end());
ll sum=0;
for(auto i=0;i<n;i++)
{
   ll it=bsearch(A,a,i+1,n-1)
   sum+=(it-i);


}
cout<<sum<<endl;

}