/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef long long int ll;
typedef pair < ll, ll > pll;
typedef vector < vector < ll >> matrix;
typedef vector < ll > vll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int  n, m;
    cin >> n >> m;
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int maxm = *max_element(a, a+n);
    int max1 = maxm + m;
    double l = (double)(sum+m)/n;
    // cout << l;
    int x = ceil(l);
    int mini = max(x, maxm);
    cout << mini << " " << max1;

    return 0;
}