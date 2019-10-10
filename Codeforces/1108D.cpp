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

    int n, ans = 0; string s;
    cin >> n >> s;
    char pattern[3] = {'R', 'G', 'B'};
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            ans++;
            for (int j = 0; j < 3; j++) {
                if (i == 0) {
                    if (s[i+1] != pattern[j]) {
                        s[i] = pattern[j];
                        break;
                    }
                } else if (i == n-1) {
                    if (s[i-1] != pattern[j]) {
                        s[i] = pattern[j];
                        break;
                    }
                } else {
                    if (s[i-1] != pattern[j] and s[i+1] != pattern[j]) {
                        s[i] = pattern[j];
                        break;
                    }
                }
            }
        }
    }
    cout << ans << "\n" << s;
    cout << "\n";

    return 0;
}