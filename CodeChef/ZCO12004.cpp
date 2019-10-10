/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef long long int ll;
typedef pair < ll, ll > pll;
typedef vector < vector < ll >> matrix;
typedef vector < ll > vll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int a[n], dp1[n], dp2[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	dp1[0] = a[0];
	dp1[1] = a[0] + a[1];
	for(int i = 2; i < n; i++){
		dp1[i] = a[i] + min(dp1[i-1], dp1[i-2]);
	}
	dp2[n-1] = a[n-1];
	dp2[n-2] = a[n-1] + a[n-2];
	for(int i = n-3; i >= 0; i--){
		dp2[i] = a[i] + min(dp2[i+1], dp2[i+2]);
	}
	// for(int i = 0; i < n; i++) cout << dp1[i] << ' '; cout << endl;
	cout << min(min(dp1[n-1], dp1[n-2]), min(dp2[0], dp2[1]));


	return 0;
}