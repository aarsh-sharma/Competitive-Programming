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
        int n, k, flag = 0, ans = 1;
        cin >> n >> k;
        int d = n / k;
        int rem = n % k;
        vector<int> a(k, d);
        if(k % 2 == 0) {
            for(int i = 1; i <= k/2; i++) {
                a[k/2 - i] -= i;
                a[k/2 + i - 1] += i;
            }
            int idx = k/2 - 1;
            while(rem) {
                a[idx]++;
                if(idx == 0) {
                    idx = k;
                }
                rem--;
                idx--;
            }
            if(a[0] < 1) {
                cout << "-1\n";
                flag = 1;
            }
            // for(int i = 0; i < k; i++) cout << a[i] << ' '; cout << endl;
            if(flag == 0) {
                for(int i = 0; i < k; i++) {
                    ans = (ans%MOD * a[i]%MOD) % MOD;
                    ans = (ans%MOD * (a[i]-1)%MOD) % MOD;
                }
                cout << ans << "\n";
            }
        } else {
            for(int i = 1; i <= k/2; i++) {
                a[k/2 - i] -= i;
                a[k/2 + i] += i;
            }
            int idx = k - 1;
            while(rem) {
                a[idx]++;
                idx--;
                rem--;
            }
            if(a[0] < 1) {
                cout << "-1\n";
                flag = 1;
            }
            // for(int i = 0; i < k; i++) cout << a[i] << ' '; cout << endl;
            if(flag == 0) {
                for(int i = 0; i < k; i++) {
                    ans = (ans%MOD * a[i]%MOD) % MOD;
                    ans = (ans%MOD * (a[i]-1)%MOD) % MOD;
                }
                cout << ans << "\n";
            }
        }
    }

    return 0;
}