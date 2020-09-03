#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    //dp[i][b] nxt value of j such that it is reachables
    //and has bth bit set
    int dp[n+1][20];
    int recent[20];
    for(int i=0;i<19;i++) recent[i]=n+1;
    for(int i=0;i<=n;i++) for(int j=0;j<19;j++) dp[i][j]=n+1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<19;j++)
        {
            if(a[i]&1<<j)
            {
                if(recent[j]!=n+1){
                dp[i][j]=min(dp[i][j],recent[j] );
                for(int b2=0;b2<19;b2++)
                {
                    dp[i][b2]=min(dp[i][b2],dp[recent[j]][b2]);
                }
                }


                recent[j]=i;
            }
        }

    }

    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        int flag=0;
        for(int j=0;j<19;j++)
        {
            if(a[y]&1<<j)
            {
                if(dp[x][j]<=y)
                {
                  //  cout<<dp[x][j]<<" "<<y<<endl;
                        flag=1;
                        break;
                }
            }
            //if(flag) break;
        }
        if(flag) cout<<"Shi"<<endl;
        else cout<<"Fou"<<endl;   
         }
}