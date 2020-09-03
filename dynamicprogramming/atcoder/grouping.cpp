#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int nax=17;
ll a[nax][nax];
ll dp[1<<nax];
ll pref[1<<nax];
void solve(int i,int mask,vector<int>&not_taken,ll score_so_far,int group)
{
    if(i==not_taken.size()) {
        dp[mask]=max(dp[mask],score_so_far+pref[group]);
        return;
    };
    solve(i+1,mask,not_taken,score_so_far,group);
    solve(i+1,mask|1<<not_taken[i],not_taken,score_so_far, group^(1<<not_taken[i]));


}
int main()
{
    int n;
    cin>>n;
    //int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    //dp[mask] total score obtained after grouping mask rabit
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if((i&1<<j)&&(i&1<<k))
                {
                    pref[i]+=a[j][k];
                }

            }
        }

    }
    for(int mask=0;mask<(1<<n);mask++)
    {
        vector<int> not_taken;
        for(int i=0;i<n;i++)
        {
            if(!(mask&1<<i))
            {
                not_taken.push_back(i);

            }
        }
        solve(0,mask,not_taken,dp[mask],0);


    }
    cout<<dp[(1<<n)-1]<<endl;
}