/*aarsh01rsh@gmail.com
aarsh01
Aarsh Sharma*/
#include <bits/stdc++.h>
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

	int n;
	cin >> n;
	int a, b, ansx = 0, ansy = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> a >> b;
		ansx += a;
		ansy += b;
	}
	ansx /= n;
	ansy /= n;
	cout << ansx << ' ' << ansy;

	return 0;
}