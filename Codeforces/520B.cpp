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

int n, m;

bool checkred(int k) {
	return !(k > 2*m);
}
bool checkblue(int k) {
	return (k > 0);
}

void bfs(int n) {
	int vis[1000000], moves[1000000];
	memset(vis, 0, sizeof(vis));
	memset(moves, 0, sizeof(moves));
	queue<int> q;
	q.push(n);
	int p = q.front();
	vis[p] = 1;
	// f(i, 0, m+1) cout << vis[i] << ' '; cout << endl;
	while (p != m) {
		int red = p * 2;
		int blue = p - 1;
		// trace(p, red, blue, checkblue(blue), vis[blue]);
		if (checkred(red) and !vis[red]) {
			moves[red] = moves[p] + 1;
			vis[red] = 1;
			q.push(red);
		}
		if (checkblue(blue) and !vis[blue]) {
			moves[blue] = moves[p] + 1;
			vis[blue] = 1;
			q.push(blue);
		}
		q.pop();
		if (q.empty()) break;
		p = q.front();
	}
	cout << moves[m];

}

int32_t main()
{
	fast_io();

	cin >> n >> m;
	bfs(n);

	return 0;
}