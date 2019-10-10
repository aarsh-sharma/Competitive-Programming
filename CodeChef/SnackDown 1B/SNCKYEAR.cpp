// theOne23 -- FazeRamLal

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < ll, ll > pll;
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;

#define pb push_back
#define debug(x) cout << (#x) << " is " << (x) << endl
#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const ll N = 1e5 + 10;

int main(){
    fast_io();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==2010 || n==2015 || n==2016 || n==2017 || n==2019)
        {
            cout<<"HOSTED\n";
        }
        else
        {
            cout<<"NOT HOSTED\n";
        }
    }
    return 0;
}