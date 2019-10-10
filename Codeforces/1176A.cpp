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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int flag = 0, ans = 0;
		while (true) {
			if ((n%2 != 0 and n%3 != 0 and n%5 != 0) or (n == 1)) {
				break;
			}
			if (n%2 == 0) {
				ans++;
				n /= 2;
			} else if (n%3 == 0) {
				ans += 2;
				n /= 3;
			} else {
				ans += 3;
				n /= 5;
			}
		}
		if (n != 1) {
			cout << -1 << "\n";
		} else {
		cout << ans << "\n";
		}
	}

	return 0;
}