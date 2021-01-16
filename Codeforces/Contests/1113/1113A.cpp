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

    int n, v;
    cin >> n >> v;
    n--;
    if (n <= v) {
        cout << n;
        return 0;
    }
    int temp = n - v;  temp++;
    int ans = v; ans += (temp*(temp+1))/2 - 1;
    cout << ans;

    return 0;
}