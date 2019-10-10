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
		int n; cin >> n;
		string s; char c; cin >> s >> c;
		vll v; int idx = 0;
		f(i, 0, n) {
			if (s[i] == c) {
				if (i == idx) {
					idx++;
					continue;
				}
				v.push_back(i - idx);
				idx = i+1;
			}
		}
		if (idx != n) {
			v.push_back(n-idx);
		}
		if (v.size() == 0) {
			cout << (n*(n+1)/2) << "\n";
			continue;
		}
		int ans, unreq = 0;
		for (auto &it : v) {
			unreq += (it * (it+1))/2;
		}
		// trace(unreq);
		ans = (n*(n+1))/2 - unreq;
		cout << ans << "\n";
	}

	return 0;
}