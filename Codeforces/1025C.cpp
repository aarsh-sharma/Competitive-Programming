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

	string s; cin >> s;
	int n = s.size();
	int ans = 0;
	int i = 0;
	int flag = 0;
	int j = (i+1 == n) ? 0 : i+1;
	int temp = 1;
	char prev = s[j-1];
	while (true) {
		if (j == i and flag == 1) {
			break;
		}
		if (j == i) {
			flag = 1;
		}
		if (s[j] != prev) {
			temp++;
		} else {
			temp = 1;
		}
		if (temp > ans) {
			ans = temp;
		}
		prev = s[j];
		(j+1 == n) ? j=0 : j=j+1;
	}
	trace(ans, n);
	(ans > n) ? cout << n : cout << ans;

	return 0;
}