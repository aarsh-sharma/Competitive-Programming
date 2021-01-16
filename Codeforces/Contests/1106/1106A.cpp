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

    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    int crosses = 0;
    for (int i = 0; i < n-2; ++i) {
        for (int j = 0; j < n-2; ++j) {
            if (s[i][j] == 'X' and s[i][j+2] == 'X' and s[i+1][j+1] == 'X' and s[i+2][j] == 'X' and s[i+2][j+2] == 'X') {
                crosses++;
            }
        }
    }
    cout << crosses << "\n";

    return 0;
}