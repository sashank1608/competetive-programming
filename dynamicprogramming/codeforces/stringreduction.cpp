#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

int main()
{
    int k;
    cin>>k;
    string s;
    cin>>s;
    stack<char> st;
    st.push(s[0]);
    for(int i=1;i<s.length();i++)
    {
        while(!st.empty()&&s[i]>st.top()&&k>0)
        {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    vector<char> ans;
    while(!st.empty())
    {
        ans.pb(st.top());
        st.pop();
    }
    
    reverse(ans.begin(),ans.end());
    while(k>0) {ans.pop_back();k--;}
    for(auto it : ans) cout<<it;
    cout<<"\n";
}