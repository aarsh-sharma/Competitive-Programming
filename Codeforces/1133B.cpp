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

    int n, k;
    cin >> n >> k;
    int a[n], rem[101], ans = 0;
    memset(rem, 0, sizeof(rem));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        rem[a[i]%k]++;
    }
    ans += rem[0]/2;
    if (k%2 == 0) {
        ans += rem[k/2]/2;
    } else {
        ans += min(rem[k/2], rem[k/2 + 1]);
    }
    for (int i = 1; i < k/2; i++) {
        ans += min(rem[i], rem[k-i]);
    }
    cout << ans*2;

    return 0;
}