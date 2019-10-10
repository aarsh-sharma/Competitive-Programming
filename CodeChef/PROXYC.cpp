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
		int d; cin >> d;
		string s; cin >> s;
		int pre = 0, abs = 0, proxy = 0;
		f (i, 0, d) {
			if (s[i] == 'P') {
				pre++;
			} else {
				abs++;
			}
		}
		trace(double(pre)/double(abs+pre));
		if (double(pre)/double(abs+pre) >= .75) {
			cout << 0 << "\n";
			continue;
		}
		int req = ceil(0.75*(double(abs+pre))) - pre;
		int flag = 0;
		for (int i = 2; i < d-2; i++) {
			if (s[i] == 'A') {
				if ((s[i-1] == 'P' or s[i-2] == 'P') and (s[i+1] == 'P' or s[i+2] == 'P')) {
					proxy++;
				}
			}
			if (proxy == req) {
				flag = 1;
				break;
			}
		}
		trace(req, proxy);
		if (flag) {
			cout << proxy << "\n";
		} else {
			cout << -1 << "\n";
		}
	}

	return 0;
}