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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const ll N = 1e5 + 10;

set<int> s;

void primeFactors(int n)
{
	while (n % 2 == 0) {
		s.insert(2);
		n = n / 2;
	}
	for (int i = 3; i <= sqrt(n); i = i + 2) {
		while (n % i == 0) {
			s.insert(i);
			n = n / i;
		}
	}
	if (n > 2)
		s.insert(n);
}

int32_t main() {
	fast_io();

	int n; cin >> n;
	int a[n][2];
	f (i, 0, n) {
		cin >> a[i][0] >> a[i][1];
	}
	primeFactors(a[0][0]);
	primeFactors(a[0][1]);
	vector<int> deleted;
	f (i, 1, n) {
		for (auto &it : s) {
			if (a[i][0]%it != 0 and a[i][1]%it != 0) {
				// s.erase(s.find(it));
				deleted.push_back(it);
			}
		}
		while (!deleted.empty()) {
			s.erase(s.find(deleted.back())), deleted.pop_back();
		}
	}
	if (s.size() == 0) {
		cout << "-1";
	} else {
		// auto it = s.begin(); it++;
		cout << *s.begin();
	}

	return 0;
}