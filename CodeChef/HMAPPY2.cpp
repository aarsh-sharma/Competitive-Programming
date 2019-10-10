/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
// #include <boost/math/common_factor.hpp>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl

typedef long long int ll;
#define int ll
typedef pair < ll, ll > pll;
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;

// Function to return LCM of two numbers
int lcm(int a, int b) {
	return (a * b) / __gcd(a, b);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, a, b, k;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b >> k;
		int lm = lcm(a, b);
		int count = n/a + n/b - 2*(n/lm);
		if (count >= k) {
			cout << "Win\n";
		} else {
			cout << "Lose\n";
		}
	}

	return 0;
}