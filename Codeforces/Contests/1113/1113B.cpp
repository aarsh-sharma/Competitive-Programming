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

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = sum;
    sort(a, a+n);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= a[i]; j++) {
            if (a[i] % j == 0) {
                ans = min(sum - a[i] + a[i]/j + a[0]*j - a[0], ans);
            }
        }
    }
    cout << ans;

    return 0;
}