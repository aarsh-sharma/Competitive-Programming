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

	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0, idx = -1;
	vll muls;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			if (idx != -1) {
				if(i - idx) {
					muls.push_back(i - idx);
				}
				idx = i;
			} else {
				idx = i;
			}
		}
	}
	if (idx != -1 and ans == 0) {
		ans++;
	}
	for (auto &it : muls) {
		ans *= it;
	}
	cout << ans;

	return 0;
}