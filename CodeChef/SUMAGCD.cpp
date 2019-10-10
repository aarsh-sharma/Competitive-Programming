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
		vll a;
		set<int> s; f (i, 0, n) {
			int temp; cin >> temp;
			int t1 = s.size();
			s.insert(temp);
			if (t1 != s.size()) {
				a.push_back(temp);
			}
		}
		sort(all(a));
		int len = a.size();
		if (len == 1) {
			cout << 2*a[0] << "\n";
			continue;
		}
		int ans = 0;
		for (int i = len-1; i >= len-2; i--) {
			if (a[i] < a[len-1]/2) {
				break;
			}
			int tempAns = a[0];
			if (i == 0) {
				tempAns = a[1];
			}
			for (int j = 0; j < len; j++) {
				if (j == i) {
					continue;
				}
				tempAns = __gcd(a[j], tempAns);
				if (tempAns == 1) {
					break;
				}
			}
			trace(tempAns, a[i], ans);
			tempAns += a[i];
			if (tempAns > ans) {
				ans = tempAns;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}