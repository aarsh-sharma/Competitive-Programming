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

const ll mod = 998244353;
const ll inf = LLONG_MAX;
const ll N = 1e5 + 10;

int32_t main() {
	fast_io();

	int n; cin >> n;
	vll a(n), b(n);
	f (i, 0, n) cin >> a[i];
	f (i, 0, n) cin >> b[i];
	f (i, 0, n) {
		a[i] *= (i+1) * (n - i);
	}
	sort (a.begin(), a.end());
	sort (b.begin(), b.end());
	reverse(b.begin(), b.end());
	int ans = 0;
	f (i, 0, n) {
		int temp = ((a[i]%mod) * (b[i]%mod))%mod;
		ans = ((ans%mod) + (temp%mod)) % mod;
	}
	cout << ans;

	return 0;
}