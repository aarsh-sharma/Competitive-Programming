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

	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << n+1 << "\n";
	int temp = 0;
	for(int i = n-1; i >= 0; --i) {
		cout << "1 " << i+1 << " " << (i+1) - ((a[i] + temp) % n) + n << "\n";
		temp += (i+1) - ((a[i] + temp) % n);
	}
	if(n == 1) {
		n++;
	}
	cout << "2 " << n-1 << " " << n << "\n";

	return 0;
}