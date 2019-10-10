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

    int n, k; cin >> n >> k;
    string s; cin >> s;
    int a[26] = {0};
    int temp = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j] != 'a' + i) {
                temp = 0;
            } else {
                temp++;
                if (temp == k) {
                    a[i]++;
                    temp = 0;
                }
            }
        }
    }
    sort(a, a+26);
    cout << a[25];


    return 0;
}