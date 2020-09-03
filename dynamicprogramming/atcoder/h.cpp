#include<bits/stdc++.h>
using namespace std;
#define ll long long;
#define pb push_back
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > vec;
    for(int i=0;i<n;i++) cin>>vec[i].first;
    for(int i=0;i<n;i++) cin>>vec[i].second;
    sort(vec.begin(),vec.end());

    stack<int> st;
    st.push(0);
    vector<int> nxt(n);
    for(int i=1;i<n;i++)
    {
        while(!st.empty()&&vec[i].second<vec[st.top()].second)
        {
            nxt[st.top()]=i;
            st.pop();

        }
    }

    for(auto it : nxt) cout<<it<<" ";
    cout<<"\n";
    int ans=n;
    for(int i=0;i<n;i++)
    {
        if(nxt[i]!=-1 && (m-vec[i].first)/vec[i].second<(m-vec[nxt[i]].first)/vec[nxt[i]].second)
        {
            ans--;
        }
    }
    cout<<ans<<"\n ";




}
