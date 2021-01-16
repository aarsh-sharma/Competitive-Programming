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

	int n; string s;
	cin >> n >> s;
	int length = 0;
	for(int i = 0; i <= n; i++) {
		if(i*(i+1) == 2*n) {
			length = i;
			break;
		}
	}
	string ans;
	int idx = 0, temp = 0, i, j;
	for(i=0, j=0; i < n, j < length; j++, i+=j) {
		ans[j] = s[i];
	}
	for(int i = 0; i < length; i++){
		cout << ans[i];
	}

	return 0;
}