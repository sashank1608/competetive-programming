#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int t1=0,t2=0;
    int n=s.length();
    auto check=[](string s,char ch)
    {
        if(ch=='A')
        {
            int t1=0;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='A'&&(i+1<s.length()&&s[i+1]=='B')) 
                return 1;
            }
        }
        else
        {
             int t1=0;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='B'&&(i+1<s.length()&&s[i+1]=='A')) 
                return 1;
            }
           
        }
        return 0;
        

    };
    for(int i=0;i<s.length();i++)
    {
        if(i!=s.length()-1&&s[i]=='A'&&s[i+1]=='B'&&!t1) 
        {
           // i++;
            if(!t2)
            {
                int bol=0;;
                if(i+2<n) bol=check(s.substr(i+2,n-i-2),'B');
                else t1=1;
                if(bol) 
                {
                        cout<<"YES"<<endl;
                         t2=1;t1=1;
                        break;
                }
               
            }
          
        }
          if(i!=s.length()-1&&s[i]=='B'&&s[i+1]=='A'&&!t2) 
          {
             // i++;
              if(!t1)
            {
                int bol=0;;
                if(i+2<n) bol=check(s.substr(i+2,n-i-2),'A');
                else t2=1;
                if(bol) 
                {
                        cout<<"YES"<<endl;
                        t2=1;t1=1;
                        break;
                }
               
            }
          
          }

    }
    if(!t1||!t2) cout<<"NO"<<endl;
   

}