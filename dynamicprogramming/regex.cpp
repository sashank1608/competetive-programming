#include "bits/stdc++.h"
using namespace std;
int main()
{
    string s,p;
    cin>>s>>p;
    int n=s.length();
    int m=p.length();
    int i=0,j=0;
    while(i<n&&j<n)
    {
        if(s[i]==p[j]||p[j]=='.') 
        {
            i++;
            j++;

        }
        else if(p[j]=='*')
        {
            if(p[j-1]=='.')
            {
                cout<<"1"<<endl;
                return 0;
            }
                if(s[i]==p[j-1])
                i++;
                else
                {
                    j++;
                }
                
        }
        else if(s[i]!=p[j])
        {
            assert(p[j]!='.'||p[j]!='*');

             cout<<"0"<<endl;
                return 0 ;
        }
    }
     cout<<"1"<<endl;
                return 0;
}