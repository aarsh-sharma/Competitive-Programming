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

	int t;
	cin >> t;
	while(t--) {
		int l, r, d;
		cin >> l >> r >> d;
		if(l > d) {
			cout << d << endl;
		} else {
			int rem = r%d;
			// debug(rem);
			if (rem == 0) {
				cout << r+d << endl;
			} else {
				cout << r + (d-rem) << endl;
			}
		}
	}

	return 0;
}