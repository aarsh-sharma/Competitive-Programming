/*aarsh02rsh@gmail.com
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
    vector<int> a(2*n); for (int i = 0; i < 2*n; i++) cin >> a[i];
    int ans = 0;
    int pos1[n+1], pos2[n+1];
    memset(pos1, -1, sizeof(pos1));
    memset(pos2, -1, sizeof(pos2));
    for (int i = 0; i < 2*n; i++) {
        if (pos1[a[i]] == -1) {
            pos1[a[i]] = i;
        } else {
            pos2[a[i]] = i;
        }
    }
    ans += pos1[1] + pos2[1];
    for (int i = 2; i < n+1; i++) {
        ans += abs(pos1[i] - pos1[i-1]);
        ans += abs(pos2[i] - pos2[i-1]);
    }
    cout << ans;

    return 0;
}