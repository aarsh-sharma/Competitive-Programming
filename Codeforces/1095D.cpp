/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl

typedef long long int ll;
#define int ll
typedef pair < ll, ll > pll;
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int a[n+1][2], ans[n+1];
	for(int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	ans[0] = MOD; ans[1] = 1;
	for(int i = 1; i <= n-2; i+=2) {
		int work = ans[i];
		if (a[a[work][0]][0] == a[work][1] or a[a[work][0]][1] == a[work][1]) {
			ans[i+1] = a[work][0];
			ans[i+2] = a[work][1];
		} else {
			ans[i+1] = a[work][1];
			ans[i+2] = a[work][0];
		}
	}

	for(int i = 1; i <= n-1; i++) {
		cout << ans[i] << " ";
	}
	if(n%2 != 0) {
		cout << ans[n];
	} else {
		ans[n] = MOD;
		sort(ans, ans+n+1);
		for(int i = 0; i < n; i++) {
			if(ans[i] != i+1) {
				cout << i+1;
				break;
			}
		}
	}

	return 0;
}