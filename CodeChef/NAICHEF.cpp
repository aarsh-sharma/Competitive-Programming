#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ARRAY_SIZE( array ) ( sizeof( array ) / sizeof( array[0] ) )

const double pi=acos(-1.0);

typedef long long int ll;
typedef unsigned long long int  ull;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin>>tc;

    while(tc--){
        int n, a, b;
        cin>>n>>a>>b;
        int arr[n];
        REP(i,n)
        cin>>arr[i];
        float aans = 0, bans = 0;
        REP(i,n) {
            if(arr[i] == a)
                aans++;
            if(arr[i] == b)
                bans++;
        }
        aans = aans / n;
        bans = bans / n;
        printf("%f\n", aans*bans);
    }
    return 0;
}
