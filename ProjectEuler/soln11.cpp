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

int a[20][20];

int up_down() {
    int ans = 0;
    for(int j = 0; j < 20; ++j) {
        for(int i = 0; i < 16; ++i) {
            int temp = a[i][j] * a[i + 1][j] * a[i + 2][j] * a[i + 3][j];
            if(temp > ans) {
                ans = temp;
            }
        }
    }
    cout << "UP DOWN - " << ans << "\n";
    return ans;
}

int left_right() {
    int ans = 0;
    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 16; ++j) {
            int temp = a[i][j] * a[i][j + 1] * a[i][j + 2] * a[i][j + 3];
            if(temp > ans) {
                ans = temp;
            }
        }
    }
    cout << "LEFT RIGHT - " << ans << "\n";
    return ans;
}

int diagonal1() {
    int ans = 0;
    for(int i = 0; i < 16; ++i) {
        for(int j = 0; j < 16; j++) {
            int temp = a[i][j] * a[i + 1][j + 1] * a[i + 2][j + 2] * a[i + 3][j + 3];
            if(temp > ans) {
                ans = temp;
            }
        }
    }
    cout << "DIAGONAL1 - " << ans << "\n";
    return ans;
}

int diagonal2() {
    int ans = 0;
    for(int i = 0; i < 16; ++i) {
        for(int j = 3; j < 20; j++) {
            int temp = a[i][j] * a[i + 1][j - 1] * a[i + 2][j - 2] * a[i + 3][j - 3];
            if(temp > ans) {
                ans = temp;
            }
        }
    }
    cout << "DIAGONAL2 - " << ans << "\n";
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 20; ++j) {
            cin >> a[i][j];
        }
    }
    int one, two, three, four;
    one = up_down();
    two = left_right();
    three = diagonal1();
    four = diagonal2();
    cout << max(max(one, two), max(three, four));

    return 0;
}