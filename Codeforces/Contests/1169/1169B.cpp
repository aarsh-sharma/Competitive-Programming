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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const ll N = 300010;

int32_t main() {
	fast_io();

	int n, m; cin >> n >> m;
	vector<pll> pairs;
	f (i, 0, m) {
		int u, v; cin >> u >> v;
		pairs.push_back({u, v});
	}
	vll start = {pairs[0].first, pairs[0].second};
	for (auto x : start) {
		int all = 0;
		vll count(n+1);
		for (int i = 1; i < m; i++) {
			if (pairs[i].first != x and pairs[i].second != x) {
				count[pairs[i].first]++;
				count[pairs[i].second]++;
				all++;
			}
		}
		if (all == *max_element(all(count))) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO\n";

	return 0;
}