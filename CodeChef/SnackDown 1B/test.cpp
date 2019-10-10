/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

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

    int t;
    cin >> t;
    while(t--) {
        int n, m, k, l, ans = INT_MAX;
        cin >> n >> m >> k >> l;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);
        for(int i = 0; i < n; i++) {
            int temp_m = m;
            temp_m -= a[i]/l;
            temp_m += i;
            if(temp_m < 0) {
                temp_m = 0;
            }
            int t = (temp_m+1)*l - (a[i]%l);
            ans = min(t, ans);
        }
        int temp_m = m;
        temp_m -= k/l;
        temp_m += n;
        if(temp_m < 0) {
            temp_m = 0;
        }
        int t = (temp_m+1)*l - (k%l);
        ans = min(t, ans);
        cout << ans << "\n";
    }

    return 0;
}