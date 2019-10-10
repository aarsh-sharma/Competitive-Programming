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

vll parent(N), strength(N);

void make_set(int v) {
	parent[v] = v;
	strength[v] = 1;
}

int find_set(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (strength[a] < strength[b]) {
			swap(a, b);
		}
		parent[b] = a;
		strength[a] += strength[b];
	}
}

int32_t main() {
	fast_io();

	int n, m; cin >> n >> m;
	int ans = 0;
	f (i, 0, n) {
		int k; cin >> k;
		if (!k) {
			ans++;
			continue;
		}
		int a[k]; f(j, 0, k) {
			cin >> a[j];
			if (strength[a[j]] == 0) {
				make_set(a[j]);
			}
		}
		f (j, 0, k) {
			f(l, j+1, k) {
				union_set(a[j], a[l]);
			}
		}
	}
	set<int> s;
	f (i, 1, m+1) {
		if (parent[i] != 0) {
			s.insert(find_set(i));
			trace(i, find_set(i));
		}
	}
	trace(ans);
	if (s.size()) {
		ans += s.size() - 1;
	}
	cout << ans;

	return 0;
}