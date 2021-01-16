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

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	for (int i = 0; i <= n-2 ; i++) {
		int tempSum = 0;
		for(int j = 0; j <= i; j++) {
			tempSum += a[j];
		}
		int j = i+1;
		int sum2 = 0;
		int flag = 0;
		int segs = 0;
		while (j < n) {
			sum2 += a[j];
			if(sum2 == tempSum) {
				segs++;
				if(j != n-1)
					sum2 = 0;
			} else if(sum2 > tempSum) {
				flag = 1;
				sum2 = 0;
				break;
			}
			j++;
		}
		if(sum2 < tempSum and sum2 != 0) {
			flag = 1;
		}
		if(flag == 0 and segs != 0){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

	return 0;
}