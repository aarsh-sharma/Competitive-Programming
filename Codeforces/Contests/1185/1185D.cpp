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

	int n; cin >> n;
	vector<pll> a(n+1);
	f (i, 1, n+1) {
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(a.begin()+1, a.end());
	int d[n+1];
	multiset<int> diff;
	f (i, 2, n+1) {
		d[i] = a[i].F - a[i-1].F;
		diff.insert(d[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			diff.erase(diff.find(d[2]));
			if (diff.empty() or *(diff.begin()) == *(diff.rbegin())) {
				cout << a[i].S;
				return 0;
			}
			diff.insert(d[2]);
		}
		else if (i == n) {
			diff.erase(diff.find(d[n]));
			if (diff.empty() or *(diff.begin()) == *(diff.rbegin())) {
				cout << a[i].S;
				return 0;
			}
			diff.insert(d[n]);
		} else {
			diff.erase(diff.find(d[i]));
			diff.erase(diff.find(d[i+1]));
			diff.insert(d[i] + d[i+1]);
			if (diff.empty() or *(diff.begin()) == *(diff.rbegin())) {
				cout << a[i].S;
				return 0;
			}
			diff.insert(d[i]);
			diff.insert(d[i+1]);
			diff.erase(diff.find(d[i] + d[i+1]));
		}
	}
	cout << -1;

	return 0;
}