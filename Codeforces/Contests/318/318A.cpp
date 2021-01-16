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
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, idx;
	cin >> n >> idx;
	if(n % 2 == 0){
		if(idx > n/2){
			cout << 2 * (idx - (n/2));
		} else{
			cout << 2*idx - 1;
		}
	} else{
		if(idx <= n/2 + 1){
			cout << 2*idx - 1;
		} else {
			cout << 2 * (idx - n/2 - 1);
		}
	}

	return 0;
}