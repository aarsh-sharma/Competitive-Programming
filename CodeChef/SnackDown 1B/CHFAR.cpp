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
    int t,n,k,temp,c=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        c=0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(temp==1)
            {
                c++;
            }
        }
        if(k>=n-c)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }

    return 0;
}