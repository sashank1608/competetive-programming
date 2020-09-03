#include<bits/stdc++.h>
using namespace std;
//int dp[3001][3001];
const int mod=1e9+7;
#define ll long long

int main()
{
int n,q;
cin>>n;
int a[n];
for(int i=0;i<n;i++) cin>>a[i];

// dp[0]=0;
// vector<int > fake(n);
// for(int i=1;i<n;i++)
// {
    
//     for(int j=1;j<a[i];j++)
//     {
//         dp[i+j]=min(dp[i+j],dp[i]+1);
//     }
// }


cin>>q;
vector<pair<int,int> > arr(q);
for(int i=0;i<q;i++)
{
   // int x;
    cin>>arr[i].first;
    arr[i].first-=1;
    arr[i].second=i;

}
sort(arr.begin(),arr.end());
vector<int > ans(q);
int jumps=0;
int start=0;
int end=0;
int qid=0;

while(1)
{
    if(start>=n-1) break;
    int max1=0;
    if(start+a[start]<n-1){
    for(int i=start+1;i<=min(start+a[start],n-1);i++)
    {
        if(min(i+a[i],n-1)>=max1)
        {
    end=i;
    max1=min(i+a[i],n-1);
        }
    }
  
    }
      jumps++;
    
      while((start+a[start])>=arr[qid].first&&qid<q)
      {
         // cout<<jumps<<endl;
          if(arr[qid].first!=start)
          ans[arr[qid].second]=jumps;
          else ans[arr[qid].second]=jumps-1;
          qid++;
      }

      if(qid>=q||start+a[start]>=n-1) break;

      start=end;
}
for(auto i:ans)
cout<<i<<endl;



}