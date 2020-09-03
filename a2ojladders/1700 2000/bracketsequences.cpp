#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define pb push_back
#define ll long long
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') a[i]=1;
        else a[i]=-1;
        if(i>0)
        a[i]+=a[i-1];
    }

    int mi=INT_MAX,min2;
    for(int i=0;i<n;i++)
    {
        if(a[i]<mi)
        {
            mi=a[i];
        }
    }
    //cout<<mi<<endl;
    for(auto it: a) cout<<it<<" ";
    cout<<endl;
    vector<int> mi2p,mi2n,mi1;
    mi1.pb(-1);
    mi2p.pb(-1);

    for(int i=0;i<n;i++)
    {
        if(a[i]==mi) mi1.pb(i);
        if(a[i] == mi+1) mi2p.pb(i);
        // if(a[i] == mi-2) mi2n.pb(i);


    }
     mi1.pb(n-1);
    mi2p.pb(n-1);
    for(auto it: mi1) cout<<it<<" ";
    cout<<endl;
    for(auto it: mi2p) cout<<it<<" ";
    cout<<endl;
    
    int ans=mi1.size();
    // if min is mi-1
   // int st=-1,fi=-1;
    for(int i=0;i<mi1.size();i++)
    {
        if(i<mi1.size())
        {
            int it1=mi1[i]+1;
            int it2=mi1[i+1];
            int cnt=0;
            while(it1<it2)
            {
                if(s[it1]=='(') break;
                it1++;

            }
            while(it2>it1)
            {
                if(s[it2]==')') break;
                it2--;
            }
            for(int j=it1;j<it2;j++)
            {
                if(a[j]==mi+1) cnt++;
            }
            ans=max(ans,cnt);

        }

    }



    //if min is mi itself
    for(int i=0;i<mi2p.size();i++)
    {
       if(i<mi2p.size())
        {
            int it1=mi2p[i]+1;
            int it2=mi2p[i+1];
            int cnt=0;
            while(it1<it2)
            {
                if(s[it1]=='(') break;
                it1++;

            }
            while(it2>it1)
            {
                if(s[it2]==')') break;
                it2--;
            }
            for(int j=it1;j<it2;j++)
            {
                if(a[j]==mi+2) cnt++;
            }
            ans=max(ans,cnt);

        }

    }

    // min is mi+2
    int it1=mi2p[1];
    int it2=mi2p.end()[-2]+1;
    int cnt=0;
   // if(s[it1]==')'&&s[it2]==')'){
       int f=0,f1=0;
       while(it2<n)
       {
           if(s[it2]=='(') {f=1;break;}
       }
       while(it1>=0)
       {
           if(s[it1]==')') {f1=1;break;}

       }
       if(f&&f1){
    for(int i=it1;i<it2;i++)
    {
        if(a[i]==mi) cnt++;
    }
    for(int i=0;i<it1;i++) if(a[i]==mi+2) cnt++;
    for(int i=it2;i<n;i++) if(a[i]==mi+2) cnt++;
    ans=max(ans,cnt);
    }

 // min is mi+1
    it1=mi1[1];
    it2=mi1.end()[-2]+1;
    cnt=0;
      f=0,f1=0;
       while(it2<n)
       {
           if(s[it2]=='(') {f=1;break;}
       }
       while(it1>=0)
       {
           if(s[it1]==')') {f1=1;break;}

       }
    if(f&&f1){
    for(int i=0;i<n;i++) if(a[i]==mi+1) cnt++;
    for(int i=it1;i<it2;i++)
    {
        if(a[i]==mi+1) cnt--;
    }
    ans=max(ans,cnt);
    }


    cout<<ans<<endl;
}