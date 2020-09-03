#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main()
{
    string s;
    cin>>s;
    int n=s.length();
   vector<pair<char,int> > vec;
   int cnt=0;
   char prev=s[0];
    for(int i=0;i<n;i++)
    {
       if(s[i]==prev) cnt++;
       else
       {
           vec.pb({prev,cnt});
           prev=s[i];
           cnt=1;
       }
       

    }
    vec.pb({prev,cnt});
    //for(auto it : vec) cout<<it.first<<" "<<it.second<<"\n";
    int flag=1;
    int ans=0;
    while(flag)
    {
         if(vec.size()<=1) break;
        vector<pair<char,int> > vec1;
        int c=INT_MAX;
        vector<int> idx;
        for(int i=0;i<vec.size();i++)
        {
            if(i!=0&&i!=vec.size()-1)
            {
                if((vec[i].second+1)/2<c)
                {
                    idx.clear();
                    c=(vec[i].second+1)/2;
                    idx.pb(i);
                }
                else if((vec[i].second+1)/2==c)
                {
                    idx.pb(i);
                }
            }
            else
            {
                if(vec[i].second<c)
                {
                    idx.clear();
                    c=vec[i].second;
                    idx.pb(i);
                }
                else  if(vec[i].second==c)
                {
                    idx.pb(i);
                }
                
            }
            
        }
       // c=min({c,vec[0].second,vec[n-1].second});
       ans+=c;
       int j=0;
       for(int i=0;i<vec.size();i++)
       {
       
           if(j<idx.size()&&i==idx[j]) {j++;continue;}
           if(vec1.size()!=0&&vec1.back().first==vec[i].first)
           {
                if(i!=0&&i!=vec.size()-1) vec[i].second-=2*c;
               else vec[i].second-=c;
               vec1.back().second+=vec[i].second;
           }
           else
           {
               if(i!=0&&i!=vec.size()-1) vec[i].second-=2*c;
               else vec[i].second-=c;

               vec1.pb(vec[i]);
           }
           


       }
       //ans++;
      
       vec=vec1;

    }
    cout<<ans<<endl;
    
   
}
