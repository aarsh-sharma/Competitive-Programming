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

    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0, temp = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] == 1) {
                temp++;
                if (temp > ans) {
                    ans = temp;
                }
            } else {
                temp = 0;
            }
        }
    }
    if (ans > n) {
        ans = n;
    }
    cout << ans;

    return 0;
}