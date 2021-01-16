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

	vector<int> a(200000);
	int n, left = 0, right = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string q; int id;
		cin >> q >> id;
		if(i == 0) {
			a[id] = 0;
			left--;
			right++;
		} else {
			if(q == "L") {
				a[id] = left;
				left--;
			} else if(q == "R") {
				a[id] = right;
				right++;
			} else {
				cout << min(abs(a[id] - left) - 1, abs(a[id] - right) - 1) << "\n";
			}
		}
	}

	#ifndef ONLINE_JUDGE
		cout << "\nTime: " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << "ms";
	#endif
	return 0;
}