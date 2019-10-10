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

vll visited(26), adj[26];
vector<pll> ans;

void bfs (int s) {
	queue<int> q;
	int p = s;
	visited[s] = 1;
	q.push(s);
	while (!q.empty()) {
		s = q.front();
		q.pop();
		for (auto &it : adj[s]) {
			if (!visited[it]) {
				ans.push_back({p, it});
				visited[it] = 1;
				q.push(it);
			}
		}
	}
}

int32_t main() {
	fast_io();

	int n; cin >> n;
	string s1, s2; cin >> s1 >> s2;
	f (i, 0, n) {
		adj[s1[i] - 'a'].push_back(s2[i] - 'a');
		adj[s2[i] - 'a'].push_back(s1[i] - 'a');
		trace(s1[i], s2[i]);
	}
	f (i, 0, 26) {
		if (!visited[i]) {
			bfs(i);
		}
	}
	cout << ans.size() << "\n";
	for (auto it : ans) {
		cout << char(it.first+'a') << " " << char(it.second+'a') << "\n";
	}

	return 0;
}