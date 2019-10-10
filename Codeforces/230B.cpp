/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef long long int ll;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

bool checkPrimeNumber(int n) {
    if (n == 1) {
        return false;
    }
    int i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	ll temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		double root = sqrt(temp);
		// debug(root);
		if(!(root == (int)root) || temp < 4){
			cout << "NO\n";
			continue;
		}
		if(checkPrimeNumber(root)){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}