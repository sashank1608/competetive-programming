#include<bits/stdc++.h>
using namespace std;
double dp[301][301][301];
double ev[301][301][301];
int main()
{
    int n;
    cin>>n;
    int a[n];
    vector<int> cnt(4);
    for(int i=0;i<n;i++) {cin>>a[i];cnt[a[i]]++;}
    //dp[ones][twos][threes]
    dp[cnt[1]][cnt[2]][cnt[3]]=1;
    for(int c=n;c>=0;c--)
    {
        for(int b=n;b>=0;b--)
        {
            for(int a=n;a>=0;a--)
            {
                if(!a&&!b&&!c) continue;
                int waste=n-(a+b+c);
                double pwaste=(double)waste/n;
                //1+S=S/pwaste
                double wasted_moves=((double)pwaste/(1-pwaste))+1;
                ev[a][b][c]+=wasted_moves*dp[a][b][c];

                if(c>0)
                {
                dp[a][b+1][c-1]+=dp[a][b][c]*((c*1.0)/(a+b+c));
                ev[a][b+1][c-1]+=ev[a][b][c]*((c*1.0)/(a+b+c));
                }
                if(b>0){
                dp[a+1][b-1][c]+=dp[a][b][c]*((1.0*b)/(a+b+c));
                 ev[a+1][b-1][c]+=ev[a][b][c]*((1.0*b)/(a+b+c));
                }
                if(a>0)
                {
                dp[a-1][b][c]+=dp[a][b][c]*((1.0*a)/(a+b+c));
                 ev[a-1][b][c]+=ev[a][b][c]*((1.0*a)/(a+b+c));
                }
            }
        }

    }
    cout<<setprecision(9)<<ev[0][0][0]<<endl;
}