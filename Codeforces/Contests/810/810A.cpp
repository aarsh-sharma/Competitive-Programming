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

	float n, k;
	cin >> n >> k;
	float tot = 0, temp;
	for(float i = 0; i < n; i++) {
		cin >> temp; tot += temp;
	}
	float i;
	if(tot/n >= k-0.5) {
		cout << "0";
		return 0;
	}
	for (i = n+1;; i++) {
		tot += k;
		float temp1 = tot/i;
		// debug(temp1);
		if(temp1 >= k-0.5){
			break;
		}
	}
	cout << i - n;

	return 0;
}