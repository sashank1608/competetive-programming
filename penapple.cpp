// Author : Apaar
// Built  : 18-10-2019 18:30:39

// SOS dp tells number of i<=n with i&n==i
// number of fully covered subsets
// remeber i=0101 and n=0100
// this will not be included
// for such case take n^(N-1) and count all of its subsets
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}


const int N = (1 << 20), M = 20;
const int K = (1 << 20) - 1;

int dp[N];

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, sum = 0, cnt = 0;
		cin >> n >> m;
		string t;
		cin >> t;
		for (i = 0; i < m; i++) {
			string s;
			cin >> s;
			k = s.size();
			int mask = 0;
			for (int ii = 0; ii < k; ii++) {
				mask |= (1 << (s[ii] - 'a'));
			}
			dp[mask] = i + 1;
		}
        for (i = 0; i < M; i++) 
		for (j = N - 1; j >= 0; j--) {
			if (!dp[j]) continue;
			
				if ((1 << i) & j) {
					dp[(1 << i)^j] = dp[j];
				}
			
		}
		int mask = 0;
		i = 0, j = 0;
		for (i = 0; i < n; i++) {
			j = i;
			mask = 0;
			while (j < n) {
				mask |= (1 << (t[j] - 'a'));
				// db(mask, dp[mask]);
				if (!dp[mask]) {
					for (int ii = 0; ii < j - i; ii++) {
						cout << sum << " ";
					}
					i = j - 1;
					break;
				}
				else {
					sum = dp[mask];
				}
				j++;
			}
			if (j == n) {
				for (int ii = 0; ii < j - i; ii++) {
					cout << sum << " ";
				}
				break;
			}
		}
		for (i = 0; i < N; i++) {
			dp[i] = 0;
		}
		cout << '\n';
	}
}