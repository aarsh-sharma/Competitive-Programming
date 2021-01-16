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

	int food[7] = {1, 1, 2, 3, 1, 3, 2};
	int a, b, c; cin >> a >> b >> c;
	int weeks = min(min(a/3, b/2), c/2);
	int ans = weeks * 7;
	a -= weeks*3;
	b -= weeks*2;
	c -= weeks*2;
	int tempmax = 0;
	trace(a, b, c, weeks);
	f(i, 0, 7) {
		int temp = 0, tempa = a, tempb = b, tempc = c, idx = i;
		while (tempa >= 0 and tempb >= 0 and tempc >= 0) {
			if (food[idx] == 1) tempa--;
			else if (food[idx] == 2) tempb--;
			else tempc--;
			temp++;
			idx++;
			if (idx == 7) idx = 0;
		}
		trace(i, temp, idx);
		if (temp > tempmax) {
			tempmax = temp-1;
		}
	}
	cout << ans + tempmax;

	return 0;
}