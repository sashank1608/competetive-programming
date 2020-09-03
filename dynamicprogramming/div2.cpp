#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        map<char,int> m;
        for(int i=0;i<n;i++) m[s[i]]++;
        string ans;
        int fill=0,flag1=0;
        for(auto it =m.begin();it!=m.end();it++)
        {
            
            if(it->second>=k) {
                if(next(it,1)==m.end()||fill==0)
                {
                for(int i=0;i<it->second/k+it->second%k;i++) ans+=it->first;
                fill=1;
                }
                else
                {
                
                    if(!flag1)
                    {
                        k=1;
                      for(int i=0;i<it->second/k+it->second%k;i++) ans+=it->first;
                    }

                }
                
            
            
            }
            else {k=k-it->second;flag1=1;}
        }
        cout<<ans<<endl;

    }


}