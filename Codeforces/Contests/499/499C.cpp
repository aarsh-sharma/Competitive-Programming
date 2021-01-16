/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define sign(x) (x > 0) ? 1 : ((x < 0) ? -1 : 0)

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

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;
	int a[n][3];
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	for (int i = 0; i < n; i++) {
		int side1 = x1*a[i][0] + y1*a[i][1] + a[i][2];
		int side2 = x2*a[i][0] + y2*a[i][1] + a[i][2];
		int s1 = sign(side1);
		int s2 = sign(side2);
		if(s1 != s2) {
			ans++;
		}
	}
	cout << ans;

	return 0;
}