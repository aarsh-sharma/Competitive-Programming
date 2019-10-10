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

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, f;
	cin >> n >> f;
	int k, l, ans = 0;
	vector < int > v;
	for(int i = 0; i < n; i++) {
		cin >> k >> l;
		if(k != 0) {
			if(k >= l) {
				ans += l;
			} else {
				ans += k;
				if(l > 2*k) {
					v.push_back(k);
				} else {
					v.push_back(l - k);
				}
			}
		}
	}
	sort(v.rbegin(), v.rend());
	if(f >= v.size()) {
		ans = accumulate(v.begin(), v.end(), ans);
	} else {
		for(int i = 0; i < f; i++) {
			ans += v[i];
		}
	}
	cout << ans;


	return 0;
}