#include<bits/stdc++.h>
using namespace std;
void printset(set<pair<int,int> > s1)
{
      set<pair<int,int> >::iterator it;
    for(it=s1.begin();it!=s1.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<"************************\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,r;
        cin>>s;
        cin>>r;
        int i=0,j=0;
        int n=s.length();
        set<pair<int,int> > s1;
        while(i<n)
        {
            int j=i;
           while(j<n&&s[j]!=r[j]) j++;
           if(j!=i)
           {
                 s1.insert(make_pair(i,j-i));
               i=j;
               
           }
           else i++;

            
        }
        //  set<pair<int,int> >::iterator it;
        // for(it=s1.begin();it!=s1.end();it++)
        // {
        //     cout<<it->first<<" "<<it->second<<endl;
        // }
        int cost=0;
        int cnt=0;
       while(!s1.empty())
       {
           pair<int,int> p1=*s1.begin();
            pair<int,int> p2;
           if(s1.size()>1)
              p2=*(++s1.begin());
           else if(s1.size()==1)
           {
                set<pair<int,int> >::iterator it=s1.begin();
                cost+=it->second;
                 s1.erase(it);
                 cnt++;
              continue;
           }
           if(p2.first-p1.first-p1.second<p2.second+p1.second)
           {
               s1.erase(s1.begin());
                set<pair<int,int> >::iterator it=++s1.begin();
               s1.erase(it);
               s1.insert(make_pair(p1.first,p2.first-p1.first+p2.second));
           }
           else
           {
                set<pair<int,int> >::iterator it=s1.begin();
                cost+=it->second;
                 s1.erase(it);
                 cnt++;
           }
           printset(s1);
           
       }
       
    //     set<pair<int,int> >::iterator it=s1.begin();
    //    for(it=s1.begin();it!=s1.end();it++)
    //    {
    //        cost+=it->second;
    //    }
       cost*=cnt;
       cout<<cost<<endl;
    }
}