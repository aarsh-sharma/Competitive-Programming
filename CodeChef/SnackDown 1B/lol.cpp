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
        int n, m, k, l, minIdx = 0, ans = INT_MAX;
        int flag = 0;
        cin >> n >> m >> k >> l;
        int a[n], minNum = m;
        int aIdx = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);
        for(int t = 1; t <= k; t++) {
            if(t%l == 0) {
                if(m != 0) {
                    m--;
                }
            }
            if(m <= minNum) {
                int tempans = (m+1)*l - (t%l);
                if(tempans <= ans) {
                    ans = tempans;
                }
                minNum = m;
            }
            if(aIdx < n && a[aIdx] == t) {
                m++;
                aIdx++;
                if(aIdx == n) {
                    flag = 1;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}