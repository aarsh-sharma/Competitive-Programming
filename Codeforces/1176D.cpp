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
const ll N = 2750131;

vll prm;

void SieveOfEratosthenes(int N) {
	prm.push_back(0);
	bool prime[N + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= N; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= N; i += p)
				prime[i] = false;
		}
	}

	for (int p = 2; p <= N; p++)
		if (prime[p])
			prm.push_back(p);
}

bool isPrime(int n) {
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

int divisor(int number) {
	int i;
	for (i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) {
			return number / i;
		}
	}
	return 1;
}

int32_t main() {
	fast_io();

	SieveOfEratosthenes(N);
	// trace(prm[0]);
	int n; cin >> n;
	map<int, int> m;
	vll a(2*n);
	f (i, 0, 2*n) {
		cin >> a[i];
		m[a[i]]++;
	}
	sort(rall(a));
	vll ans;
	for (auto &it : a) {
		if (!isPrime(it) and m[it] > 0) {
			trace(it, divisor(it));
			ans.push_back(it);
			m[it]--;
			m[divisor(it)]--;
		}
	}
	for (auto it : m) {
		if (it.second > 0) {
			trace(it.first, it.second, prm[it.first]);
			f (i, 0, it.second)
				ans.push_back(it.first);
			m[prm[it.first]] -= it.second;
			m[it.first] = 0;
		}
	}
	for (auto &it : ans) {
		cout << it << ' ';
	}


	return 0;
}