#include<bits/stdc++.h>
using namespace  std;
#define ll long long
struct node{
int mx;
void init(int value)
{
    mx=value;

}
void merge(node a,node b)
{
    mx=max(a.max,b.max);
}
};
int main()
{
    int n;
    cin>>n;
    int max_end=INT_MIN;
    vector<pair<int,int> > vec(n);;
    for(int i=0;i<n;i++) 
    {
        cin>>vec[i].first>>vec[i].second;
        max_end=max(max_end,vec[i].second);
    }
    sort(vec.begin(),vec.end(),[](pair<int,int> a,pair<int,int> b)
    {
            return a.second<b.second;
    });
    int base=1;
    while(base<=max_end)
    {
        base*=2;
    }
    vector<node> tree(2*base);
    vector<int> dp(n);
    //dp[i] max no of activities considering last activity ended at time =ft[i] 
    //dp[i]= max dp[0 to st[i] ]
    for(int i=0;i<n;i++)
    {
        //find max in 0 to st[i]
        int x=base+vec[i].first;
        while(x>1)
        {
            if(x%2) dp[i]=max(dp[i],tree[x-1].mx);
            x/=2;
        }
        tree[base+vec[i].second].init(dp[i]+1);
        for(int z=(base+vec[i].second)/2;z>=1;z/=2)
        {
                tree[z].merge(tree[2*z],tree[2*z+1]);

        }
    }



}