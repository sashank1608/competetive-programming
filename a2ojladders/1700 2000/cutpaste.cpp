#include<bits/stdc++.h>
using namespace std;

#define ll long long
constexpr ll mod = 1'000'000'007;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        string s;
        cin>>s;
        int n=s.length();
        ll len=n;
        ll new_len=0;
        int f=1;
        for(int t=1;t<=x;t++)
        {
            len=(len+(len-t)*(s[t-1]-'1'))%mod;
            if(s.length()<x)
            {
                    string app(s.begin()+t,s.end());
                    for(int i=0;i<s[t-1]-'1';i++)
                    {
                        s+=app;
                    }
                    if(s.length()>x) f=0;
            }
           // cout<<len<<endl;
           // cout<<s<<endl;
            //len=new_len;


        }
        cout<<(len%mod+mod)%mod<<endl;
        //13332133333321333332133333321333332133333321333332133333321333
    }
}
