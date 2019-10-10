// aarsh01rsh@gmail.com
// Aarsh Sharma
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif
#define f(i, x, n) for (int i = x; i < n; i++)
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

int32_t main()
{
	fast_io();

	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		map<pair<double, double>, int> m1;
		f(i, 0, k) {
			pll temp; cin >> temp.first >> temp.second;
			m1[{temp.first - 0.5, temp.second}]++;
			m1[{temp.first + 0.5, temp.second}]++;
			m1[{temp.first, temp.second - 0.5}]++;
			m1[{temp.first, temp.second + 0.5}]++;
		}
		int ans = 0;
		for (auto it : m1) {
			if (it.second % 2 != 0) {
				ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}