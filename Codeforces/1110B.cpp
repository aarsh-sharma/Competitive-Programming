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

    int n, m, k;
    cin >> n >> m >> k;
    int a[n], ans = k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int b[n-1];
    for (int i = 0; i < n-1; i++) {
        b[i] = a[i+1] - a[i];
    }
    sort(b, b+n-1);
    for (int i = 0; i < n-k; i++) {
    ans += b[i];
    }    
    cout << ans << "\n";

    return 0;
}