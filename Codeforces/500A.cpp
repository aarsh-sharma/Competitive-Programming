// aarsh01rsh@gmail.com
// Aarsh Sharma
#include<bits/stdc++.h>
using namespace std;

#define f(i, x, n) for (int i = x; i < n; i++)
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

int n, t;

void bfs(vll path[]) {
	queue<int> q;
	q.push(1);
	int p = q.front();
	int vis[n+1];
	memset(vis, 0, sizeof(vis));
	while(!q.empty()) {
		// debug(p);
		for (auto &it : path[p]) {
			if (vis[it] == 0) {
				q.push(it);
				vis[it] = 1;
			}
		}
		q.pop();
		p = q.front();
		if (p == t) {
			break;
		}
	}
	if (p == t) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}

int32_t main()
{
	fast_io();

	cin >> n >> t;
	int a[n-1]; f(i, 0, n-1) cin >> a[i];
	vll path[n+1];
	f(i, 0, n-1) {
		path[i+1].push_back(i+1+a[i]);
	}
	bfs(path);

	return 0;
}