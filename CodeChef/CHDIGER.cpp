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

	int t;
	cin >> t;
	while (t--) {
		vector<char> v; char d; string s;
		cin >> s >> d;
		int len = s.size();
		int a[len], num = 0;
		memset(a, 0, sizeof(a));
		char min = d;
		for (int i = len-1; i >= 0; i--) {
			if (s[i] > min) {
				a[i] = -1;
				num++;
			} else {
				min = s[i];
			}
		}
		for (int i = 0; i < len; i++) {
			if (a[i] == 0) {
				cout << s[i];
			}
		}
		while (num--) {
			cout << d;
		} cout << endl;
	}

	return 0;
}