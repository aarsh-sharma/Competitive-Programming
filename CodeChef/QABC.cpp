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

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n], b[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		int flag = 0;
		for(int i = 0; i < n-2; i++) {
			int temp = b[i] - a[i];
			if(temp < 0) {
				cout << "NIE\n";
				flag = 1;
				break;
			} else if(temp == 0) {
				continue;
			} else {
				if(b[i+1] - temp*2 >= 0) {
					b[i+1] -= temp*2;
				} else {
					cout << "NIE\n";
					flag = 1;
					break;
				}
				if(b[i+2] - temp*3 >= 0) {
					b[i+2] -= temp*3;
				} else {
					cout << "NIE\n";
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0 and (a[n-1] != b[n-1] or a[n-2] != b[n-2])){
			cout << "NIE\n";
			flag = 1;
		}
		if(flag == 0){
			cout << "TAK\n";
		}
	}

	return 0;
}