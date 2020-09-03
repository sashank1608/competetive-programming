#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll m,d;
        cin>>d>>m;
        int highest_bit=log2(d);
        ll pro=1;
        for(int i=0;i<30;i++)
        {
            if(1LL<<i > d) break;
            pro=(pro*(min((1LL<<(i+1))-1,d)-(1LL<<i)+2))%m;
        }
    pro--;
   if(pro<0) pro+=m;
    cout<<pro<<endl;

    }
   

}