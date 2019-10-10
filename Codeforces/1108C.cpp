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

    int n, ans = INT_MAX; string s;
    cin >> n >> s;
    string ans_str, pattern = "RGB";
    sort(pattern.begin(), pattern.end());
    do {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != pattern[i%3]) {
                temp++;
            }
        }
        if (temp < ans) {
            ans = temp;
            ans_str = pattern;
        }
    } while (next_permutation(pattern.begin(), pattern.end()));
    cout << ans << "\n";
    for (int i = 0; i < n/3; i++) cout << ans_str;
    for (int i = 0; i < n%3; i++) cout << ans_str[i];

    return 0;
}