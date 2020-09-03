#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
void dfs1(int u,int p);
const int mod = 1000000007;
const int N = 2e5+1, M = N;
//=======================
 
vi g[N];
int a[N], p[N], v[N];
int sum[N], id[N];
map<int,int> cnt[N];//create map for every node
int ans = 0;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	cin >> n;
	Fo(i, 1, n+1){
		id[i] = i;
		cin >> p[i] >> v[i];
		if(p[i]>0)
			g[p[i]].pb(i);
	}
	dfs1(1, 0);
	cout << ans << endl;
	return 0;
} 
 

void dfs1(int u,int p)
{
   // int bigChild=-1;
    for(auto v:g[u])
    {
        if(v==p) continue;
        dfs1(v,u);
        if(cnt[id[v]].size()>cnt[id[u]].size()) {
            //cnt[u]=cnt[v];
          //  bigChild=v;
            swap(id[u],id[v]);
        };//finding bigChild and making map corresponding to node u as that one
    }
     int &cur=sum[id[u]];
//     if(bigChild!=-1)
//    cur+=sum[bigChild];

    for(auto v:g[u])
    {
        if(v==p) continue;
        //if(v==bigChild) continue;
        for(auto it : cnt[v])
        {
            int col=it.first;
            int qty=it.second;
            int &val=cnt[id[u]][col];
            cur-=val;
            	if(cur < 0) cur += mod;
            val=((val+1)*1LL*(qty+1))%mod;
            val-=1;
            if(val < 0) val += mod;
            cur+=val;
            if(cur >= mod) cur -= mod;



        }

    }
    ll add=cur;
    cnt[id[u]][v[u]] += 1+add;
    if(cnt[id[u]][v[u]] >= mod) cnt[id[u]][v[u]] -= mod;
    ans += 1+add;
    if(ans >= mod) ans -= mod;
    cur+= 1+add;
    if(cur >= mod) cur -= mod;


}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
		if(cnt[id[v]].size() > cnt[id[u]].size()) swap(id[u], id[v]);
	}
 
	int &cur = sum[id[u]];
	for(int v:g[u]){
		if (v == par) continue;
		for(auto it: cnt[id[v]]){
			int col = it.F, no = it.S;
			int &val = cnt[id[u]][col];
			cur -= val;
			if(cur < 0) cur += mod;
			val = ((val+1) *1LL* (no+1))%mod;
			val -= 1;
			if(val < 0) val += mod;
			cur += val;
			if(cur >= mod) cur -= mod;
		}
	}
	ll add = cur;
	cnt[id[u]][v[u]] += 1+add;
	if(cnt[id[u]][v[u]] >= mod) cnt[id[u]][v[u]] -= mod;
	ans += 1+add;
	if(ans >= mod) ans -= mod;
	cur += 1+add;
	if(cur >= mod) cur -= mod;
}