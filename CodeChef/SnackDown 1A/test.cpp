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
        int a[3][3];
        for(int i = 0; i < 3; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        if(a[0][0] == a[1][0] and a[0][1] == a[1][1] and a[0][2] == a[1][2]) {
            cout << "no\n";
            continue;
        }
        if(a[0][0] == a[2][0] and a[0][1] == a[2][1] and a[0][2] == a[2][2]) {
            cout << "no\n";
            continue;
        }
        if(a[2][0] == a[1][0] and a[2][1] == a[1][1] and a[2][2] == a[1][2]) {
            cout << "no\n";
            continue;
        }
        cout << "yes\n";
    }

    return 0;
}