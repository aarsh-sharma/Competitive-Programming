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

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (a[i]%2==0 or a[i]%3==0) {
            if (a[i] % 2 == 0) {
                a[i] /= 2;
            } else {
                a[i] /= 3;
            }
        }
        if (i != 0) {
            if (a[i] != a[i-1]) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";

    return 0;
}