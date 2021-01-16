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
	set <int> a;
	for (int i = 1; i*i <= n; i++) {
		if(n%i == 0) {
			int temp = n/i;
			a.insert((temp * (2 + (temp - 1) * i))/2);
			a.insert((i * (2 + (i - 1) * temp))/2);
		}
	}
	for(auto x : a) {
		cout << x << ' ';
	}

	return 0;
}