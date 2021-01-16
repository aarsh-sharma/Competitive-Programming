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
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

int n, m, cats[100005], ans = 0;
vll adj[100005];
int totcats[100005] = {0};
vector<bool> visited(100005);

bool isleaf(int v) {
	if (adj[v].size() == 1) {
		return true;
	}
	return false;
}

void dfs(int v) {
	visited[v] = true;
	for (auto u : adj[v]) {
		if (!visited[u]){
			if (cats[u]) {
				totcats[u] += totcats[v] + 1;
			}
			if (totcats[u] > m) {
				continue;
			}
			if (isleaf(u)) {
				ans++;
			}
			// trace(v, u, totcats[u], ans, isleaf(u));
			dfs(u);
		}
	}
}

int32_t main()
{
	fast_io();

	cin >> n >> m;
	f(i, 1, n+1) cin >> cats[i];
	f(i, 0, n-1) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (cats[1] == 1) {
		totcats[1] = 1;
	}
	dfs(1);
	cout << ans;


	return 0;
}