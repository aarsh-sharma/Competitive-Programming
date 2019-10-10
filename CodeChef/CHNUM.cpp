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

	int t, n, temp;
	cin >> t;
	while (t--) {
		int pos = 0, neg = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			if (temp > 0) {
				pos++;
			} else {
				neg++;
			}
		}
		if (pos == 0) {
			cout << neg << " " << neg;
		} else if (neg == 0) {
			cout << pos << " " << pos;
		} else {
			cout << max(pos, neg) << " " << min(pos, neg);
		}
		cout << endl;
	}

	return 0;
}