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

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    // for (int i = 0; i < n; ++i) cout << a[i] << " "; cout << endl;
    int x = a[n-1], y = a[n-2], flag = 0;
    for (int i = n-2; i >= 0; --i) {
        if (x % a[i] != 0) {
            flag = 1;
            y = a[i];
            break;
        }
    }
    if(!flag) {
		// debug("lol");
        for(int i = n-1; i >= 0; i--) {
			if(a[i] == a[i-1]) {
				y = a[i];
				break;
			}
		}
    }
    cout << x << " " << y << "\n";

    return 0;
}