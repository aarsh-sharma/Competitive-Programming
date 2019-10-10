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

int32_t main() {
	// fast_io();

	int a[] = {4, 8, 15, 16, 23, 42};
	int a12, a23, a34, a45;
	cout << "? 1 2\n";
	fflush(stdout);
	cin >> a12;
	cout << "? 2 3\n";
	fflush(stdout);
	cin >> a23;
	cout << "? 3 4\n";
	fflush(stdout);
	cin >> a34;
	cout << "? 4 5\n";
	fflush(stdout);
	cin >> a45;
	do {
		if (a[0]*a[1] == a12 and a[1]*a[2] == a23 and a[2]*a[3] == a34 and a[3]*a[4] == a45) {
			cout << "! ";
			f (i, 0, 6) {
				cout << a[i] << " ";
			} cout << "\n";
			fflush(stdout);
			return 0;
		}
	}while (next_permutation(a, a + 6));

	return 0;
}