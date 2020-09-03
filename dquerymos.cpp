#include<bits/stdc++.h>
using namespace std;
 struct Q
{
  int l,r,id;
};
const int nax=1e6+10;
vector<int> cnt(nax);
int ans;
int main()
{
    int n,qu;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int blk=sqrt(n);
    cin>>qu;
    vector<struct Q> q(qu);
    vector<int> res(qu);
   for(int i=0;i<qu;i++)
    {
        int x,y;
        cin>>x>>y;
        q[i].id=i;
        q[i].l=x-1;
        q[i].r=y-1;


    }
    sort(q.begin(),q.end(),[&](Q a1,Q b1){
        int x= a1.l/blk;
        int y=b1.l/blk;
        if(x==y) return a1.r<b1.r;
        else return x<y;
    });
    // for(auto it : q)
    // {
    //     cout<<it.l<<" "<<it.r<<endl;
    // }
    auto add=[&](int i){
        cnt[a[i]]++;
        if(cnt[a[i]]==1) ans++;
        

    };
    auto rem=[&](int i){
        cnt[a[i]]--;
        if(cnt[a[i]]==0) ans--;
        //else if(cnt[a[i]]==1) ans++;


    };
    int left=0,right=-1;
    for(int i=0;i<qu;i++)
    {

         while(right<q[i].r)
         {++right;add(right);}

          while(left<q[i].l)
        rem(left),left++;

        while(left>q[i].l)
        --left,add(left);

       

       

        while(right>q[i].r)
        rem(right),right--;
  //cout<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
        res[q[i].id]=ans;

    }
    
    for(auto it:res)
    {
        cout<<it<<endl;
    }

}