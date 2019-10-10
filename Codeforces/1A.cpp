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

	ll n, m, a;
	ll ans = 0;
	cin >> n >> m >> a;
	if(n <= a){
		if(m%a == 0) cout << m/a;
		else cout << m/a + 1;
	}
	else if(m <= a){
		if(n%a == 0) cout << n/a;
		else cout << n/a + 1;
	}
	else{
		ll rem1 = m%a;
		ll rem2 = n%a;
		if(rem1 == 0 && rem2 == 0){
			cout << (m/a)*(n/a);
		} else if(rem1 == 0){
			cout << (m/a)*(n/a + 1);
		} else if(rem2 == 0){
			cout << (n/a)*(m/a + 1);
		} else{
			cout << (n/a)*(m/a) + (n/a) + (m/a) + 1;
		}
	}


	return 0;
}