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

    int n, m; cin >> n >> m;
    if (m % n != 0) {
        cout << -1;
        return 0;
    }
    int q = m / n, ans = 0;
    while (q % 3 == 0 or q % 2 == 0) {
        if (q % 3 == 0) {
            q /= 3;
            ans++;
        } else if (q % 2 == 0) {
            q /= 2;
            ans++;
        }
    }
    // debug(q);
    if (q != 1) {
        cout << -1;
        return 0;
    }
    cout << ans;

    return 0;
}