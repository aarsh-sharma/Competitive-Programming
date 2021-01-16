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
    for (int i = 0; i < n; i++) cin >> a[i];
    int i = 0, j = 0, ans = 1;
    sort(a, a+n);
    while (j < n) {
        if (j - i + 1 > ans and a[j] - a[i] <= 5)
        {
            ans = j - i + 1;
        }
        if (a[j] - a[i] <= 5) {
            j++;
        } else {
            i++;
        }
    }
    cout << ans;

    return 0;
}