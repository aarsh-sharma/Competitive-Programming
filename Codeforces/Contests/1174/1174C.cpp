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
	vll ans(n+1); int pos = 1;
	vector<char> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		int flag = 0;
		if (is_prime[i]) {
			trace(i, pos);
			flag = 1;
			ans[i] = pos;
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
				ans[j] = pos;
			}
		}
		if (flag) {
			pos++;
		}
	}
	// f (i, 2, n+1) {
	// 	cout << ans[i] << ' ';
	// } cout << endl;
	for (int i = 2; i <= n; i++) {
		if (!ans[i]) {
			ans[i] = pos;
			pos++;
		}
	}
	f (i, 2, n+1) {
		cout << ans[i] << ' ';
	}

	return 0;
}