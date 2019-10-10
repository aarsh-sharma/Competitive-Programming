// aarsh01rsh@gmail.com
// Aarsh Sharma
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif
#define f(i, x, n) for (int i = x; i < n; i++)
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

int32_t main()
{
	fast_io();

	int n; cin >> n;
	set<int> s; f(i, 0, n) {
		int temp; cin >> temp;
		s.insert(temp);
	}
	if (s.size() > 3) {
		cout << -1;
		return 0;
	}
	if (s.size() == 1) {
		cout << 0;
		return 0;
	} else if (s.size() == 2) {
		if ((*s.begin() + *s.rbegin()) % 2 == 0) {
			cout << (*s.begin() + *s.rbegin()) / 2 - *s.begin();
			return 0;
		} else {
			cout << *s.rbegin() - *s.begin();
			return 0;
		}
	}
	int sum = 0;
	for (auto &it : s) {
		sum += it;
	}
	auto it = s.begin(); it++;
	if (sum % s.size() == 0) {
		if (*it == sum/s.size())
			cout << sum / s.size() - *s.begin();
		else
			cout << -1;
	} else {
		cout << -1;
	}

	return 0;
}