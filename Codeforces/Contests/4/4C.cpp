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
    map <string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        auto it = m.find(s);
        if(it != m.end()) {
            m[s]++;
            cout << s << m[s] << "\n";
        } else {
            m.insert({s, 0});
            cout << "OK\n";
        }
    }

    return 0;
}