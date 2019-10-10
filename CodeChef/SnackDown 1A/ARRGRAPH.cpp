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

bool coprime(int a, int b)
{

    if (__gcd(a, b) == 1)
        return true;
    else
        return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, flag = 0, tot = 0;
        cin >> n;
        int a[n];
        bool cop[n] = {false};
        queue<int> q;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        q.push(a[0]);
        cop[0] = true;
        tot++;

        while(!q.empty()) {
            int num = q.front();
            q.pop();
            for(int i = 0; i < n; i++) {
                if(!cop[i]) {
                    if(coprime(num, a[i])) {
                        q.push(a[i]);
                        cop[i] = true;
                        tot++;
                    }
                }
            }
        }

        if(tot != n) {
            if(a[0] == 47){
                a[0] = 43;
            } else {
            a[0] = 47;
            }
            cout << "1\n";
        } else{
            cout << "0\n";
        }

        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        } cout << "\n";
    }

    return 0;
}