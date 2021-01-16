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
#define F first
#define S second
#define pb push_back
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
		int n, m; cin >> n >> m;
		vector<string> grid(n);
		f (i, 0, n) {
			cin >> grid[i];
		}
		char last_char = '.';
		f (i, 0, n) {
			char l = *max_element(all(grid[i]));
			last_char = max(last_char, l);
		}
		// trace(last_char);
		if (last_char == '.') {
			cout << "YES\n0\n";
			continue;
		}
		int last = last_char - 'a';
		vector<int> ans[last+1];
		int ok = true;
		for (int i = last; i >= 0; i--) {
			int tlx = inf, tly = inf, brx = -inf, bry = -inf;
			char cur = 'a' + i;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (grid[i][j] == cur) {
						tlx = min(tlx, i);
						tly = min(tly, j);
						brx = max(brx, i);
						bry = max(bry, j);
					}
				}
			}
			// trace(cur, tlx, tly, brx, bry);
			if (tlx == inf) { // if char not in grid
				ans[i] = ans[i+1];
			} else { // if char in grid
				if (tlx != brx and tly != bry) { // if current char not in a line
					ok = false;
					// trace("current char not in a line");
					break;
				}
				// vector<int> temp = {tlx, tly, brx, bry};
				ans[i] = {tlx, tly, brx, bry};
				for (int r = tlx; r <= brx; r++) {
					for (int c = tly; c <= bry; c++) {
						if (grid[r][c] == cur or grid[r][c] == '*') {
							grid[r][c] = '*';
						} else {
							ok = false;
							// trace("line does not contain all chars", cur);
							break;
						}
					}
					if (!ok) {
						break;
					}
				}
			}
			if (!ok) {
				break;
			}
		}
		if (!ok) {
			cout << "NO\n";
		} else {
			cout << "YES\n" << last+1 << "\n";
			f (i, 0, last+1) {
				for (auto &it : ans[i]) {
					cout << it+1 << " ";
				} cout << "\n";
			}
		}
	}

	return 0;
}