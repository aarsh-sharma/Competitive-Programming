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

	int n; cin >> n;
	string s; cin >> s;
	int a[9]; f(i, 0, 9) cin >> a[i];
	int flag = 0;
	f(i, 0, n) {
		trace(s[i] - '0' <= a[s[i] - '1'], flag);
		if (s[i] - '0' <= a[s[i] - '1']) {
			if (s[i] - '0' < a[s[i] - '1']) {
				flag = 1;
			}
			s[i] = a[s[i] - '1'] + '0';
		} else if (flag == 1) {
			break;
		}
	}
	cout << s;

	return 0;
}