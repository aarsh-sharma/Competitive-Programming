#include<bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ARRAY_SIZE( array ) ( sizeof( array ) / sizeof( array[0] ) )

const double pi=acos(-1.0);

typedef long long int ll;
typedef unsigned long long int ull;


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, k, count = 0;
	cin>>n>>k;
	int a[n];
	for(int i = 0; i<n; i++) cin>>a[i];
	sort(a, a+n);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++){
			if(a[j] - a[i] >= k){
				count += n - j;
				break;
			}
		}
	}
	cout<<count;
	
	return 0;
}
