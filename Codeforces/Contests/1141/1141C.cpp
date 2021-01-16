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
    int a[n-1]; for (int i = 0; i < n-1; i++) cin >> a[i];
    int ans[n], test[n];
    ans[0] = n, test[0] = n;
    for (int i = 0; i < n-1; i++) {
        ans[i+1] = ans[i] + a[i];
        test[i+1] = test[i] + a[i];
    }
    sort(test, test+n);
    for (int i = 1; i < n; i++) {
        if (test[i] - test[i-1] != 1) {
            cout << -1;
            return 0;
        }
    }
    int temp = test[0] - 1;
    for (int i = 0; i < n; i++) cout << ans[i] - temp << ' ';


    return 0;
}