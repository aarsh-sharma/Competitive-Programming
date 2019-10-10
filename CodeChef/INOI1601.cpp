/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef long long int ll;
#define int ll
typedef pair < ll, ll > pll;
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	bool vis[n+1] = {false};
	int mx[n+1];
	int a[n+1];
	int p[n+1];
	vector < int > adj[n+1];
	int root;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if(p[i] == -1) {
			root = i;
			continue;
		}
		adj[p[i]].push_back(i);
	}

	queue<int> q;
	q.push(root);
	vis[root] = true;
	mx[root] = a[root];

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++) {
			int x = adj[v][i];
			if(!vis[x]) {
				q.push(x);
				vis[x] = true;
				ans = max(ans, mx[v] - a[x]);
				mx[x] = max(a[x], mx[v]);
			}
		}
	}

	cout << ans;

	return 0;
}