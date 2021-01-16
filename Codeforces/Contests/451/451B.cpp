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
    int l = 1, r = 1;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >>  a[i];
        b[i] = a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            l = i;
            break;
        }
    }
    for (int i = n-2; i >= 0; i--) {
        if (a[i] > a[i+1]) {
            r = i+2;
            break;
        }
    }
    reverse(a+l-1, a+r);
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n" << l << " " << r;

    return 0;
}