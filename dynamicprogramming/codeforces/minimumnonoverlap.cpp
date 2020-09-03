#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int nax=1e5;
vector<int> bit(nax);
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > vec(n);
    vector<int> coords;
    for(int i=0;i<n;i++) 
    {
     cin>>vec[i].second>>vec[i].first;
     coords.pb(vec[i].first);
     coords.pb(vec[i].second);
    }
    sort(vec.begin(),vec.end(),[](pair<int,int> a,pair<int,int> b){
        if(a.first!=b.first) return a.first < b.first;
        else return a.second>b.second;

    });
    sort(coords.begin(),coords.end());
    coords.resize(unique(coords.begin(),coords.end())-coords.begin());
    int nax=coords.back()+1;
    for(int i=0;i<n;i++)
    {
        vec[i].first=lower_bound(coords.begin(),coords.end(),vec[i].first)-coords.begin();
        vec[i].second=lower_bound(coords.begin(),coords.end(),vec[i].second)-coords.begin();
    }
    vector<int> prev(n);
    prev[0]=-1;
    for(int i=1;i<n;i++)
    {
        auto it = upper_bound(vec.begin(),vec.end(),make_pair(vec[i].second-1,INT_MAX));
        if(it==vec.begin()) prev[i]=-1;
        else prev[i]=it-vec.begin()-1;
    }
  //  for(auto it : vec) cout<<it.second<<" "<<it.first<<"\n";
  //  cout<<"\n";
   // for(auto it : prev) cout<<it<<" ";
   // cout<<"\n";
    vector<int> dp(n);
    int base=1;
    while(base<nax) base*=2;
    vector<int> tree(2*base,INT_MAX);
    for(int i=0;i<n;i++)
    {
        if(prev[i]==-1)
        {
            tree[base+vec[i].first]=1;
            for(int j=(base+vec[i].first)/2;j>0;j=j/2)
            {
                tree[j]=min(tree[2*j],tree[2*j+1]);
            }
        }
        else
        {
            int ml=INT_MAX,mr=INT_MAX;
            int l=base+vec[prev[i]].second;
            int r=base+vec[prev[i]].first;
            ml=tree[l];
            mr=tree[r];
            while(r-l>1)
            {
                if(l%2==0)
                {
                    ml=min(ml,tree[l+1]);
                }
                if(r%2)
                {
                    mr=min(mr,tree[r-1]);
                }
                l/=2;
                r/=2;
            }
            int mi=min(ml,mr);
            dp[i]=mi+1;
            tree[base+vec[i].first]=dp[i];
            for(int j=(base+vec[i].first)/2;j>0;j=j/2)
            {
                tree[j]=min(tree[2*j],tree[2*j+1]);
            }
        }
        
    }
    //int ans;
  //  for(int i=1;i<2*base;i++) cout<<tree[i]<<" ";
  //  cout<<"\n";
    int ml=INT_MAX,mr=INT_MAX;
            int l=base+vec[n-1].second;
            int r=base+vec[n-1].first;
            ml=tree[l];
            mr=tree[r];
            while(r-l>1)
            {
                if(l%2==0)
                {
                    ml=min(ml,tree[l+1]);
                }
                if(r%2)
                {
                    mr=min(mr,tree[r-1]);
                }
                l/=2;
                r/=2;
            }
            int ans=min(ml,mr);
            cout<<ans<<"\n";




}