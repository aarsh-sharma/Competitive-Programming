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

	int r, c; cin >> r >> c;
	string s[r]; f (i, 0, r) cin >> s[i];
	int flag = 0;
	for (int i = 1; i < r-1; i++) {
		for (int j = 1; j < c-1; j++) {
			if (s[i][j] == '*' and s[i+1][j] == '*' and s[i-1][j] == '*' and s[i][j-1] == '*' and s[i][j+1] == '*') {
				trace(i, j);
				for (int k = i; k < r; k++) {
					if (s[k][j] == '.') {
						break;
					}
					s[k][j] = '.';
				}
				for (int k = i-1; k >= 0; k--) {
					if (s[k][j] == '.') {
						break;
					}
					s[k][j] = '.';
				}
				for (int k = j+1; k < c; k++) {
					if (s[i][k] == '.') {
						break;
					}
					s[i][k] = '.';
				}
				for (int k = j-1; k >= 0; k--) {
					if (s[i][k] == '.') {
						break;
					}
					s[i][k] = '.';
				}
				flag = 1;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (!flag) {
		cout << "NO";
		return 0;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (s[i][j] == '*') {
				trace(i, j);
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";

	return 0;
}