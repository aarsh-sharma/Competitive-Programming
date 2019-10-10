/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef long long int ll;
typedef pair < ll, ll > pll;
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int s, n;
	cin >> s >> n;
	vector < pll > a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	int flag = 0;
	for(int i = 0; i < n; i++){
		if(s > a[i].first){
			s += a[i].second;
		} else {
			flag = 1;
			cout << "NO";
			break;
		}
	}
	if(flag == 0) cout << "YES";

	return 0;
}