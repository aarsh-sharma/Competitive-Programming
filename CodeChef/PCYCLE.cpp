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

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

vector < int > v1;
vector < vector < int > > v2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, num = 0;
	cin >> n;
	int a[n], vis[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		vis[i] = 0;
	}
	for(int i = 0; i < n; i++){
		v1.clear();
		int j = i;
		if(!vis[i]){
			num++;
			while(!vis[j]){
				vis[j] = 1;
				v1.push_back(j+1);
				j = a[j] - 1;
			}
			v1.push_back(j+1);
			v2.push_back(v1);
		}
	}
	cout << num << "\n";
	for(int i = 0; i < v2.size(); i++){
		for(int j = 0; j < v2[i].size(); j++){
			cout << v2[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}