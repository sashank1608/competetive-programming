#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int t=1;
   // cin>>t;
    while(t--)
    {
        int n,mp;
        cin>>n>>mp;
       // unordered_map<int,int> m;
       if(n%2==0) n--;
        int l=(n-1)/2;
        int start=1;
        int it=1;
        //n++;
        while(mp>0)
        {
            cout<<start<<" "<<(start+l)<<endl;
            start=(start+l+it)%n;
            l--;
            it++;
        
            mp--;


        }
    }

}