/*
aarsh01rsh@gmail.com
Aarsh Sharma
*/
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, ans = 0; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	for (int i = 0; i < n; i++) {
		ans += abs(a[i] - (i+1));
	}
	cout << ans;

	return 0;
}