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

bool isInside(const std::string &str, char c)
{
    return str.find(c) != std::string::npos;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<double, string>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        a[i].first /= a[i].second.size();
    }
    sort(a.begin(), a.end());
    double A = 0, B = 0, C = 0; int flag = 0;
    for(int i = 0; i < n; i++){
        if(a[i].second.size() == 1){
            if(isInside(a[i].second, 'A')){
                A = a[i].first
                flag++;
            }
            if(isInside(a[i].second, 'B')){
                B = a[i].first
                flag++;
            }
            if(isInside(a[i].second, 'C')){
                C = a[i].first
                flag++;
            }
        } else{

        }
    }
    return 0;
}