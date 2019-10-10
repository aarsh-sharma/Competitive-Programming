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

	int n, x, y, time1 = 100001, temp_time;
	cin>>n>>x>>y;
	vector<pair<int, int>> a(n);
	vector<int> v(x), w(y);
	for(int i = 0; i < n; i++) cin>>a[i].first>>a[i].second;
	for(int i = 0; i < x; i++) cin>>v[i];
	for(int i = 0; i < y; i++) cin>>w[i];
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	sort(a.begin(), a.end());
	vector<int>::iterator it1, it2;

	// for(int i = 0; i<n;i++)cout<<a[i].first<<" "<<a[i].second<<endl;
	
	for(int i = 0; i < n; i++)
	{
		it1 = upper_bound(v.begin(), v.end(), a[i].first);
		it1--;
		it2 = upper_bound(w.begin(), w.end(), a[i].second-1);
		temp_time = *it2 - *it1 + 1;
		// cout<<*it1<<" "<<*it2<<endl;
		
		if (*it2 > *it1) {
			if(temp_time < time1)
			time1 = temp_time;			
		}
	}

	cout<<time1;
	
	return 0;
}
