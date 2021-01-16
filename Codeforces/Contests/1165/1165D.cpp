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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n); f (i, 0, n) cin >> a[i];
		sort(a.begin(), a.end());
		int ans = a[0]*a[n - 1];
		vector <int> temp;
		for (int i = 2; i <= sqrt(ans); ++i) {
			if (ans % i == 0) {
					temp.push_back(i);
					if (i * i != ans) {
						temp.push_back(ans / i);
					}
        }
		}
		sort(temp.begin(), temp.end());
		if (temp == a) {
			cout << ans << "\n";
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}