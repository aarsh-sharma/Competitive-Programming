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

int is_palindrome(string);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> palins;
    for(int i = 100; i < 999; i++) {
        for(int j = 100; j < 999; j++) {
            int temp = i*j;
            if(is_palindrome(to_string(temp))) {
                palins.push_back(temp);
            }
        }
    }
    sort(palins.begin(), palins.end());
    cout << palins[palins.size() - 1];

    return 0;
}

int is_palindrome(string s) {
    for(int i = 0; i < s.size()/2; i++) {
        if(s[i] != s[s.size() - 1 - i]) {
            return 0;
        }
    }
    return 1;
}