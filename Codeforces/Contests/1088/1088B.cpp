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

	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	if(a[0] > 0) {
		cout << a[0] << "\n"; k--;
	}
	for (int i = 1; i < n; i++) {
		if(k <= 0) {
			break;
		}
		if(a[i] > 0 && a[i] - a[i-1] > 0) {
			cout << a[i] - a[i-1] << "\n";
			k--;
		}
	}
	while(k--) {
		cout << 0 << "\n";
	}

	return 0;
}