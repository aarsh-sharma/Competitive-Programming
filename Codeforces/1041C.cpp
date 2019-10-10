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

	int n, m, d;
	cin >> n >> m >> d;
	int a[n];
	set < pair < int, int > > s;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s.insert(make_pair(a[i], i));
	}
	int ans[n];
	int day = 0;
	while(!s.empty()){
		day++;
		int pos = s.begin()->second;
		ans[pos] = day;
		s.erase(s.begin());
		while(true){
			auto it = s.lower_bound({a[pos] + 1 + d, 0});
			if(it == s.end()) break;
			pos = it->second;
			s.erase(it);
			ans[pos] = day;
		}
	}
	cout << day << "\n";
	for(int i = 0; i < n; i++) cout << ans[i] << " ";


	return 0;
}