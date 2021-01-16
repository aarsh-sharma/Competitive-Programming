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

	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int temp = 0, min = 0, ans;
	for (int i = 0; i < k; i++) {
		temp += a[i];
	}
	min = temp; ans = 0;
	for (int i = k; i < n; i++) {
		temp -= a[i - k];
		temp += a[i];
		if (temp < min) {
			min = temp;
			ans = i - k + 1;
		}
	}
	cout << ans + 1;

	return 0;
}