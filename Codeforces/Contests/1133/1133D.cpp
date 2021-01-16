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
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    map<pair<int, int>, int> m; int extra = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (b[i] == 0) {
                extra++;
            }
            continue;
        }
        int num = b[i] / __gcd(a[i], b[i]);
        int den = a[i] / __gcd(a[i], b[i]);
        m[{num, den}]++;
    }
    int ans = 0;
    if (m.empty()) {
        cout << extra;
        return 0;
    }
    for (auto it : m) {
        if (it.second > ans) {
            ans = it.second;
        }
    }
    cout << ans+extra;

    return 0;
}