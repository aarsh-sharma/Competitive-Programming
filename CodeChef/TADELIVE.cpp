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

	int n, x, y; cin >> n >> x >> y;
	vector<pair <int, int>> a(n); f (i, 0, n) {cin >> a[i].first; a[i].second = i;}
	vector<pair <int, int>> b(n); f (i, 0, n) {cin >> b[i].first; b[i].second = i;}
	vector<pair <int, int>> diff(n);
	f (i, 0, n) {
		diff[i].first = abs(a[i].first - b[i].first);
		diff[i].second = i;
	}
	sort(diff.begin(), diff.end(), greater<>());
	int i = 0, ans = 0, idx[n] = {0};
	while ((x != 0 and y != 0) and i < n) {
		int index = diff[i].second;
		if (a[index] >= b[index]) {
			ans += a[index].first;
			x--;
		} else {
			ans += b[index].first;
			y--;
		}
		idx[index] = 1;
		i++;
	}
	trace(i);
	if (x != 0 and i < n) {
		sort(a.begin(), a.end(), greater<>());
		i = 0;
		while (x != 0 and i < n) {
			if (idx[a[i].second] == 0) {
				trace(i, a[i].first, idx[a[i].second]);
				idx[a[i].second] = 1;
				ans += a[i].first;
				x--;
			}
			i++;
		}
	}
	if (y != 0 and i < n) {
		sort(b.begin(), b.end(), greater<>());
		i = 0;
		while (y != 0 and i < n) {
			if (idx[b[i].second] == 0) {
				idx[b[i].second] = 1;
				ans += b[i].first;
				y--;
			}
			i++;
		}
	}
	trace(ans);
	cout << ans;

	return 0;
}