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

vector < int > adj[310];
int vis[310] = {false};
int ans = 0;

void dfs(int s) {
	if (vis[s])
		return;
	vis[s] = true;
	ans++;
	for (auto u : adj[s])
		dfs(u);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector < int > id[n];
	for (int i = 0; i < n; i++) {
		int l; cin >> l;
		for (int j = 0; j < l; j++) {
			int temp; cin >> temp;
			id[i].push_back(temp);
		}
		sort(id[i].begin(), id[i].end());
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int l = 0, m = 0, L = id[i].size(), M = id[j].size(), tempK = 0;
			while(l < L && m < M) {
				if(id[i][l] < id[j][m])
					l++;
				else if(id[i][l] > id[j][m])
					m++;
				else if(id[i][l] == id[j][m]){
					tempK++;
					l++;
					m++;
				}
				if(tempK >= k) {
					adj[i].push_back(j);
					adj[j].push_back(i);
					break;
				}
			}
		}
	}

	// queue < int > q;
	// q.push(0);
	// vis[0] = true;
	dfs(0);


	// This way was slower
	
	// while(!q.empty()){
	// 	int v = q.front(); q.pop();
	// 	for (int i = 0; i < adj[v].size(); i++) {
	// 		if(!vis[adj[v][i]]) {
	// 			vis[i] = true;
	// 			ans++;
	// 			q.push(adj[v][i]);
	// 		}
	// 	}
	// }

	cout << ans;

	return 0;	
}