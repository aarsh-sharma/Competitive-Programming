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
const ll N = 1e5 + 10;

int32_t main() {
	fast_io();

	int n; cin >> n;
	vll a(n); f (i, 0, n) cin >> a[i];
	vll b = {4,8,15,16,23,42};
	map<int, int> m;
	m[4] = 0;
	m[8] = 0;
	m[15] = 0;
	m[16] = 0;
	m[23] = 0;
	m[42] = 0;
	if (n < 6) {
		cout << n;
		return 0;
	}
	int ans = 0;
	f (i, 0, n) {
		m[a[i]]++;
		if (m[42]>m[23] or m[23]>m[16] or m[16]>m[15] or m[15]>m[8] or m[8]>m[4]) {
			ans++;
			m[a[i]]--;
		}
	}
	int minm = inf;
	for (auto it : m) {
		if (it.second < minm) {
			minm = it.second;
		}
	}
	trace(ans, minm);
	for (auto it : m) {
		ans += it.second - minm;
	}
	trace(ans);
	n -= ans;
	ans += n%6;
	cout << ans;


	return 0;
}