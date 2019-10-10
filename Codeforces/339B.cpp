/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef long long int ll;
typedef pair < ll, ll > pll;
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, m;
	cin >> n >> m;
	ll a[m];
	for(int i = 0; i < m; i++) cin >> a[i];
	ll ans = a[0];
	for(int i = 1; i < m; i++){
		if(a[i] >= a[i-1]){
			ans += a[i] - a[i-1];
		} else {
			ans += n - a[i-1] + a[i];
		}
		// cout << ans << "\n";
	}
	cout << ans-1;

	return 0;
}