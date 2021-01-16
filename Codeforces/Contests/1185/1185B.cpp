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
		string s1, s2; cin >> s1 >> s2;
		vector<pair<char, int>> one, two;
		f (i, 0, s1.size()) {
			if (one.size() > 0 and (*one.rbegin()).first == s1[i]) {
				(*one.rbegin()).second++;
			} else {
				one.push_back({s1[i], 1});
			}
		}
		f (i, 0, s2.size()) {
			if (two.size() > 0 and (*two.rbegin()).first == s2[i]) {
				(*two.rbegin()).second++;
			} else {
				two.push_back({s2[i], 1});
			}
		}
		int flag = 0;
		if (one.size() != two.size()) {
			flag = 1;
		}
		if (flag) {
			cout << "NO\n";
			continue;
		}
		f (i, 0, one.size()) {
			if (one[i].first != two[i].first) {
				flag = 1;
				break;
			}
			if (one[i].second > two[i].second) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}

	return 0;
}