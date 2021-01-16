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
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const ll N = 1e5 + 10;

bool lambda(const pair<int,int> &a, const pair<int,int> &b) 
{
	if (a.first == b.first){
		return (a.second > b.second);
	}
		else {
			return (a.first < b.first);
		}
} 

int32_t main() {
	fast_io();

	int n; cin >> n;
	vector<pll> a, temp;
	f(i, 0, n) {
		int b, c; cin >> b >> c;
		a.push_back({b, c});
	}
	int ans = 0;
	vector<pll> ab;
	f(i, 0, n) {
		trace(a[i].first, a[i].second);
		ab.push_back({a[i].first - a[i].second, i});
		trace(ans);
	}
	sort(ab.rbegin(), ab.rend());
	f(i, 0, n) {
		ans += a[ab[i].second].first*(i);
		ans += a[ab[i].second].second*(n-i-1);
	}
	cout << ans;

	return 0;
}