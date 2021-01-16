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

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	ll temp = n, count = 0, k1 = k;
	while (temp != 0) {
		count += (temp % 2);
		temp /= 2;
	}
	int power = ceil(log2(n));
	if(k > n or count > k) {
		cout << "NO\n";
		return 0;
	}

	int a[k];
	while(k--) {
		while(n - pow(2, power) < k) {
			power--;
		}
		n -= pow(2, power);
		a[k] = pow(2, power);
	}
	cout << "YES\n";
	for(int i = 0; i < k1; i++) {
		cout << a[i] << ' ';
	}

	return 0;
}
