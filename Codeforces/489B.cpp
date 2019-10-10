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

int32_t main()
{
	fast_io();

	int n; cin >> n;
	int a[n]; f(i, 0, n) cin >> a[i];
	int m; cin >> m;
	int b[m]; f(i, 0, m) cin >> b[i];
	sort(a, a+n);
	sort(b, b+m);
	int i = 0, j = 0, ans = 0;
	while (i < n and j < m) {
		if (abs(a[i] - b[j]) <= 1) {
			i++;
			j++;
			ans++;
		} else {
			if (b[j] > a[i]) {
				i++;
			} else {
				j++;
			}
		}
	}
	cout << ans;

	return 0;
}