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

	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	if(n < m) {
		for(int i = 0; i < n; i++) {
			cout << "GB";
		}
		for(int i = 0; i < m-n; i++) {
			cout << "G";
		}
	} else {
		for(int i = 0; i < m; i++) {
			cout << "BG";
		}
		for(int i = 0; i < n-m; i++) {
			cout << "B";
		}		
	}

	#ifndef ONLINE_JUDGE
		cout << "\nTime: " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << "ms";
	#endif
	return 0;
}