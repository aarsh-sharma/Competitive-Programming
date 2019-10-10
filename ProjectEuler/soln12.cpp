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

int num_of_divisors(int n) {
    int ans = 1, num = 0;
    while(n%2 == 0) {
        num++;
        n /= 2;
    }
    ans *= (1 + num);
    for(int i = 3; i*i <= n; i+=2) {
        num = 0;
        while(n%i == 0) {
            num++;
            n /= i;
        }
        ans *= (1 + num);
    }
    if(n > 2) {
        ans *= 2;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count = 14000, best = 0;
    for(int i = 1; i < count; ++i) {
        int sum = (i * (i+1)) / 2;
        int temp = num_of_divisors(sum);
        if(temp > best) {
            best = temp;
        }
        if(temp > 500) {
            cout << sum << "\n";
            break;
        }
    }
    cout << best << "\n";

    return 0;
}