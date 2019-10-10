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

int collatz(int n) {
    int num = 0;
    while(n != 1) {
        num++;
        if(n % 2 == 0) {
            n /= 2;
        } else {
            n = 3*n + 1;
        }
    }
    return num;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int longest = 0, ans;
    for(int i = 1; i <= 1000000; i++) {
        int temp = collatz(i);
        if(temp > longest) {
            longest = temp;
            ans = i;
        }
    }
    cout << ans;

    return 0;
}