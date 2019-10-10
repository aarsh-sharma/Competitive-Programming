#include<bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ARRAY_SIZE( array ) ( sizeof( array ) / sizeof( array[0] ) )
#define ROUND(x) ((int)(x + 0.5))

const double pi=acos(-1.0);

typedef long long int ll;
typedef unsigned long long int ull;


int main()
{
	// ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

	ll t;
	cin>>t;
	vector<ll> a, sums;
	for(int i = 0; i<35; i++)
	{
		ll temp = pow(2, i);
		a.push_back(temp);
		if(temp > 1000000000) break;
	}
	ll l = a.size();
	for(int i = 0; i< l; i++)
	{
		for(int j = i+1; j<l; j++)
		sums.push_back(a[i] + a[j]);
	}
	sort(sums.begin(), sums.end());
	l = sums.size();
	while(t--)
	{
		ll diff = 1000000000;
		ll n;
		cin>>n;
		for(int i = 0; i< l; i++)
		{
			if(abs(sums[i] - n) < diff)
			diff = abs(sums[i] - n);
			if(abs(sums[i+1] - n) > diff)
			break;
		}
		cout<<diff<<endl;
	}
	
	return 0;
}
