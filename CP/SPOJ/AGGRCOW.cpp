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

	ll t, n, c;
	cin >> t;
	while(t--)
	{
		cin >> n >> c;
		ll a[n];
		for(ll i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		ll l = 0, r = a[n-1], mid;
		while(r > l)
		{
			ll sum = 0, num = 0, pivot = 0, flag = 0;
			mid = l + (r - l + 1)/2;
			for(ll i = 0; i < n; i++)
			{
				sum = a[i] - a[pivot];
				if(sum >= mid)
				{
					num++;
					pivot = i;
					if(num >= c-1)
					{
						flag = 1; break;
					}
				}
			}
			if(flag) {
				l = mid;
			} else {
				r = mid-1;
			}
		}
		cout << l << endl;
	}

	return 0;
}
