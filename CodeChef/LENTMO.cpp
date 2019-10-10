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
		vll a(n); f (i, 0, n) cin >> a[i];
		int k, x; cin >> k >> x;
		vll xo(n);
		f (i, 0, n) {
			xo[i] = a[i]^x;
		}
		if (n == k) {
			if (accumulate(all(a), 0ll) > accumulate(all(xo), 0ll)) {
				cout << accumulate(all(a), 0ll) << "\n";
			} else {
				cout << accumulate(all(xo), 0ll) << "\n";
			}
			continue;
		}
		if (k%2 == 1) {
			vll c(n);
			f (i, 0, n) {
				c[i] = max(a[i], xo[i]);
			}
			cout << accumulate(all(c), 0ll) << "\n";
		} else {
			vll c(n);
			f (i, 0, n) {
				c[i] = xo[i] - a[i];
			}
			sort(rall(c));
			int ss = 0;
			for (int i = 0; i < n-1; i+=2) {
				if (c[i] + c[i+1] > 0) {
					ss += c[i] + c[i+1];
				} else {
					break;
				}
			}
			cout << accumulate(all(a), 0ll) + ss << "\n";
		}
	}

	return 0;
}