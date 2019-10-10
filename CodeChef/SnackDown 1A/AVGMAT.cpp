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
    int t,n,m;
    char x;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int> > checkMe;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>x;
                if(x == '1')
                {
                    checkMe.pb(make_pair(i,j));
                }                    
            }
        }
        for(int i = 1; i <= (n+m)-2; i++)
        {
            int d=0;
            for(int j=0; j<checkMe.size(); j++)
            {
                for(int k=0; k<checkMe.size(); k++)
                {
                    if( (abs(checkMe[j].first - checkMe[k].first)+abs(checkMe[j].second - checkMe[k].second)) == i){
                        d++;
                    }
                }
            }
            cout<<d/2<<" ";
        }
        cout<<endl;

    }
    return 0;
}