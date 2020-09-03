#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mod=1e9+7;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int h,w;
        cin>>h>>w;
        char a[h][w];
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin>>a[i][j];
            }
        }
        vector<vector<int> > dist(h,vector<int>(w));
        deque<pair<int,int> > q;
        
    }
}