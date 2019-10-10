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

	int n;
	cin >> n;
	int a[n/2], b[n];
	for(int i = 0; i < n/2; i++) {
		cin >> a[i];
	}
	b[0] = 0; b[n-1] = a[0];
	for(int i = 1; i < n/2; i++) {
		if(a[i] > a[i-1]) {
			b[i] = b[i-1] +  (a[i] - a[i-1]);
			b[n-i-1] = a[i] - b[i];
		} else {
			b[i] = b[i-1];
			b[n-i-1] = a[i] - b[i];
		}
	}
	for(int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}

	return 0;
}