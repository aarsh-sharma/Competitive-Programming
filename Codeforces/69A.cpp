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
typedef vector < vector < ll >> matrix;
typedef vector < ll > vll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int a[n][3], flag = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 3; j++)
		cin >> a[i][j];
	}
	for(int i = 0; i < 3; i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			sum += a[j][i];
		}
		if(sum != 0){
			flag = 1;
			break;
		}
	}
	if(flag) cout << "NO";
	else cout << "YES";

	return 0;
}