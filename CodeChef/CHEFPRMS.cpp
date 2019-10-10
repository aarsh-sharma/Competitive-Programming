/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef long long int ll;
#define int ll
typedef pair < ll, ll > pll;
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int n = 54;
vector<int> primes;

void Sieve()
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}

	for (int p = 2; p <= n; p++)
		if (prime[p]) {
			primes.push_back(p);
		}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Sieve();
	int l = primes.size(), idx = 0;
	int len = l*(l-1)/2;
	int a[len];
	for(int i = 0; i < l; i++) {
		for(int j = i+1; j < l; j++) {
			a[idx] = primes[i]*primes[j];
			idx++;
		}
	}
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k;
		int flag = 0;
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < len; j++) {
				if(k-a[i] == a[j]){
					// cout << a[i] << " " << a[j] << endl;
					cout << "YES\n";
					flag = 1;
					break;
				}
			}
			if(flag == 1) break;
		}
		if(flag == 0) cout << "NO\n";
	}

	return 0;
}