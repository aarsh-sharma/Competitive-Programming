/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << "\n"
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

    int n;
    cin >> n;
    // multiset < int, int > mul;
    // set < int, int > mul;
    int a[n];
    vector < int > b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int i = 0;
    while(i < n-1){
        if(a[i] != a[i+1]){
            b.push_back(i);
            i++;
        }
        else{
            while(a[i] == a[i+1] && i < n-1){
                i++;
            } i++;
        }
    }
    if(a[n-2] != a[n-1]){
        b.push_back(n-1);
    }
    for(int i = 0; i < b.size(); i++) cout << b[i] << " "; cout << endl;
    if(b.size()%2 == 1){
        cout << "NO";
    }
    else{
        vector < char > ans(n, 'A');
        int flag = 0;
        cout << "YES" << "\n";
        for(int i = 0; i < b.size(); i++){
            if(flag == 0){
                ans[b[i]] = 'A';
                flag = 1;
            }
            else{
                ans[b[i]] = 'B';
                flag = 0;
            }
        }
        for(int i = 0; i < n; i++) cout << ans[i];
    }

    return 0;
}