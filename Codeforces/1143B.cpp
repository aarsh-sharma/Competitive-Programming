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

	string s; cin >> s;
	int n = s.size();
	int ans = 1, tempans = 1;
	for (int i = 0; i < n; i++) {
		tempans *= s[i] - '0';
	}
	if (tempans > ans) {
		ans = tempans;
	}
	for (int i = 0; i < n; i++) {
		tempans = 1;
		for (int j = 0; j < n; j++) {
			if (j < i) {
				tempans *= s[j] - '0';
				// cout << s[j] - '0' << " ";
			} else if (i == j) {
				if (i == 0) {
					if (s[j] - '1' == 0) {
						continue;
					}
				}
				tempans *= s[j] - '1';
				// cout << s[j] - '1' << " ";
			} else {
				tempans *= 9;
				// cout << 9 << " ";
			}
		}
		// cout << endl;
		if (tempans > ans) {
			ans = tempans;
		}
	}
	cout << ans;

	return 0;
}