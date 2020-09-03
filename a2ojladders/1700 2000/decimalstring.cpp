#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.length();
    vector<vector<int> > cnt(10,vector<int>(10));//,dp(11,vector<int>(11,INT_MAX));
    for(int i=0;i<n-1;i++)
    {
        cnt[s[i]-'0'][s[i+1]-'0']++;

    }
    if(s[0]!='0') cnt[0][s[0]-'0']++;
    for(int x=0;x<=9;x++)
    {
        for(int y=0;y<=9;y++)
        {
             vector<vector<int> > dp(10,vector<int>(10,INT_MAX));
            for(int frm=0;frm<=9;frm++)
            {
                for(int cntx=0;cntx<=10;cntx++)
                {
                    for(int cnty=0;cnty<=10;cnty++)
                    {
                        if(cntx+cnty==0) continue;
                        int to=(frm+(cntx*x)%10+(cnty*y)%10)%10;
                        dp[frm][to]=min(dp[frm][to],cntx+cnty);
                    }
                }
            }
            long long ans=0;
            if(s[0]!='0') ans++;
            
            for(int frm=0;frm<=9;frm++)
            {
                for(int to=0;to<=9;to++)
                {
                    if(cnt[frm][to]>0&&dp[frm][to]==INT_MAX)
                    {
                        //cout<<"("<<frm<<to<<")";
                        ans=-1;
                        break;
                    }
                    if(dp[frm][to]>0)
                    ans+=(dp[frm][to]-1)*1LL*cnt[frm][to];

                }
                if(ans==-1) break;
            }
            cout<<ans<<" ";

        }
        cout<<endl;
    }

}