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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int len = s.size();
        int a[len] = {0};
        int flag = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] != '.') {
                int lol = s[i] - '0';
                a[i]++;
                if(a[i] > 1) {
                    cout << "unsafe\n";
                    flag = 1;
                    break;
                }
                for(int j = 1; j <= lol; j++) {
                    if(i-j >= 0){
                        a[i-j]++;
                        if(a[i-j] > 1){
                            cout << "unsafe\n";
                            flag = 1;
                            break;                            
                        }
                    }
                    if(i+j < len){
                        a[i+j]++;
                        if(a[i+j] > 1){
                            cout << "unsafe\n";
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag) {
                    break;
                }
            }
        }
        // for(int i = 0; i < len; i++) debug(a[i]);
        if(!flag) {
            cout << "safe\n";
        }
    }

    return 0;
}