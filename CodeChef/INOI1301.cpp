#include<bits/stdc++.h>

using namespace std;

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
    
    ll n, k, ans;
    cin>>n>>k;
    ll a[n+1], dp1[n+1], dp2[n+1];
    for(ll i = 1; i < n+1; i++) {
    	cin>>a[i];
    }
    dp1[1] = a[1];
    dp1[2] = a[1] + a[2];
    for(ll i = 3; i < n+1; i++) {
    	dp1[i] = a[i] + max(dp1[i-1],dp1[i-2]); 
    }
    dp2[k] = 0;
    dp2[k-1] = 0;
    for(ll i = k+1; i < n+1; i++) {
    	dp2[i] = a[i] + max(dp2[i-1], dp2[i-2]);
    }
    ans = dp1[k] + dp2[k] - a[k];
    for(ll i = k+1; i < n+1; i++) {
    	ans = max(ans, (dp1[i] + dp2[i] - a[i]));
    }
    cout<<ans;
	return 0;
}