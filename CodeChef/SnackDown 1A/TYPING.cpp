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
        int n;
        cin >> n;
        float tot = 0;
        float temptime[n] = {0};
        string words[n];
        for(int i = 0; i < n; i++) {
            char hand = 'i';
            int flag = 0;
            cin >> words[i];
            for(int j = 0; j < i; j++) {
                if(words[i] == words[j]) {
                    temptime[i] = temptime[j]/2;
                    words[i] = words[j];
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                for(int j = 0; j < words[i].size(); j++) {
                    char temphand;
                    char c = words[i][j];
                    if(c == 'd' || c == 'f'){
                        temphand = 'l';
                    } else {
                        temphand = 'r';
                    }
                    if(temphand == hand) {
                        temptime[i] += 4;
                        // hand = temphand;
                    } else {
                        temptime[i] += 2;
                        hand = temphand;
                    }
                }
            }
            // debug(temptime[i]);
            tot += temptime[i];
        }
        cout << tot << "\n";
    }

    // #ifndef ONLINE_JUDGE
    //     cout << "\nTime: " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << "ms";
    // #endif
    return 0;
}