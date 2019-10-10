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

void seive(int n, int num) {
    int temp = 0, ans = 0;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int p = 2; p*p <= n; p++) {
        if(prime[p] == true) {
            for(int i = p*p; i <= n; i+=p) {
                prime[i] = false;
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        if(prime[i]) {
            // cout << i << " ";
            temp++;
            if(temp == num) {
                ans = i;
            }
        }
    }
    cout << "\n" << temp << " " << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 200000, num = 10001;
    seive(n, num);

    return 0;
}