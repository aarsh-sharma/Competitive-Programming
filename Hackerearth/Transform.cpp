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

    int sh, sk, th, tk;
    cin >> sh >> sk >> th >> tk;
    if (sh > th or sk > tk or th == tk) {
        cout << "false\n";
        return 0;
    }
    while (true) {
        if (sh > th or sk > tk) {
            cout << "false\n";
            return 0;
        }
        if (sh == th and sk == tk) {
            cout << "true\n";
            return 0;
        }
        if (th > tk) {
            th -= tk;
        } else {
            tk -= th;
        }
    }

    return 0;
}