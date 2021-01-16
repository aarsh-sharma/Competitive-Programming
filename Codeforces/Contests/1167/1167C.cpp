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
const ll N = 500010;

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

void union_set(int u, int v) {
	u = find_set(u);
	v = find_set(v);
	if (u != v) {
		if (strength[u] < strength[v]) {
			swap(u, v);
		}
		parent[v] = u;
		strength[u] += strength[v];
	}
}

int32_t main() {
	fast_io();

	int n, m; cin >> n >> m;
	f (i, 1, n+1) {
		make_set(i);
	}
	f (i, 0, m) {
		int k; cin >> k;
		int group[k]; f (j, 0, k) cin >> group[j];
		f (i, 1, k) {
			union_set(group[i], group[i-1]);
		}
	}
	f (i, 1, n+1) {
		int a = find_set(i);
		cout << strength[a] << " ";
	}

	return 0;
}