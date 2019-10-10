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
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int p, s;
	cin>>p>>s;
	vector<pair<int, int>> v1(s);
	vector<pair<int, int>> v2(p);
	for(int k = 0; k< p; k++)
	{
		int n = 0;
		for(int i = 0; i< s; i++) cin>>v1[i].first;
		for(int i = 0; i< s; i++) cin>>v1[i].second;
		sort(v1.begin(), v1.end());
		for(int i = 0; i< s-1; i++)
		{
			if(v1[i].second > v1[i+1].second) n++;
		}
		v2[k] = make_pair(n, k);
	}
	sort(v2.begin(), v2.end());
	for(int i=0; i< p; i++)
	{
		cout<<v2[i].second+1<<endl;
	}

	return 0;
}
