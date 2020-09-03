#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x[n];
    int h[n];
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>h[i];
    int dp1[n],dp2[n],dp3[n];
    //dp1[i] maxtrres if i cut to left
    //dp2[i] max trees if i cut to right
    //dp3[i] max trees if i was not cut
    /*
        dp1[i]=max(dp1[i],dp1[i-1]&&x[i-1]<x[i]-h[i],dp2[i-1]&&x[i]-h[i]>x[i-1]+h[i-1],dp3[i-1]&&x[i-1]<x[i]-h[i]);
        dp2[i]=i<n-1&&x[i]+h[i]<x[i+1]&&max(dp2[i],dp1[i],dp2[i-1],dp3[i]);
        dp3[i]=max(dp3[i],dp1[i-1],dp2[i-1],dp3[i-1]);


    */



}