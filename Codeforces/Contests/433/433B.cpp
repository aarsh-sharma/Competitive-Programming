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

    int n, t;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> t;
    int normal_sum[n+1], sorted_sum[n+1];
    normal_sum[0] = 0;
    normal_sum[1] = a[0];
    for (int i = 2; i < n+1; i++) {
        normal_sum[i] = normal_sum[i-1] + a[i-1];
    }
    sort(a, a+n);
    sorted_sum[0] = 0;
    sorted_sum[1] = a[0];
    for (int i = 2; i < n+1; i++) {
        sorted_sum[i] = sorted_sum[i-1] + a[i-1];
    }
    while (t--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            cout << normal_sum[r] - normal_sum[l-1] << "\n";
        } else if (type == 2) {
            cout << sorted_sum[r] - sorted_sum[l-1] << "\n";
        }
    }

    return 0;
}
