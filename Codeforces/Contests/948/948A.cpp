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

	int r, c;
	cin >> r >> c;
	char a[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if(a[i][j] == '.') {
				a[i][j] = 'D';
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c-1; j++) {
			if ((a[i][j] == 'S' && a[i][j + 1] == 'W') || (a[i][j] == 'W' && a[i][j + 1] == 'S')) {
				cout << "NO";
				return 0;
			}
		}
	}
	for (int j = 0; j < c; j++) {
		for (int i = 0; i < r-1; i++) {
			if ((a[i][j] == 'S' && a[i+1][j] == 'W') || (a[i][j] == 'W' && a[i+1][j] == 'S')) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cout << a[i][j];
		} cout << "\n";
	}
	return 0;
}