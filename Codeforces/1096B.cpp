/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define MOD 998244353
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
	string s;
	cin >> s;
	int frontlength = 1, endlength = 1;
	for(int i = 1; i < n; i++) {
		if(s[i] != s[i-1]) {
			break;
		}
		frontlength++;
	}
	for(int i = n-2; i >= 0; i--) {
		if(s[i] != s[i+1]) {
			break;
		}
		endlength++;
	}
	if(s[0] != s[n-1]) {
		cout << (frontlength + endlength + 1) % MOD;
	} else {
		cout << ((frontlength+1) * (endlength+1)) % MOD;
	}
	

	return 0;
}