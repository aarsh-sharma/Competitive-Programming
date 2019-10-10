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
	fast_io();

	int flag = 0;
	int n; cin >> n;
	vector<char> v;
	int a[n]; f(i, 0, n) cin >> a[i];
	int front = 0, end = n-1, minm = 0;
	while (front < end) {
		// trace(a[front], a[end]);
		if (a[front] < a[end]) {
			if (a[front] > minm) {
				// cout << 'L';
				v.push_back('L');
				minm = a[front];
				front++;
			} else if (a[end] > minm) {
				// cout << 'R';
				v.push_back('R');
				minm = a[end];
				end--;
			} else {
				break;
			}
		} else if (a[end] < a[front]) {
			if (a[end] > minm) {
				// cout << 'R';
				v.push_back('R');
				minm = a[end];
				end--;
			} else if (a[front] > minm) {
				// cout << 'L';
				v.push_back('L');
				minm = a[front];
				front++;
			}
			else {
				flag = 1;
				break;
			}
		} else {
			break;
		}
	}
	int templ = 0, tempr = 0, temp = minm;
	for (int i = front; i < end; i++) {
		if (a[i] > temp) {
			templ++;
			temp = a[i];
		} else {
			break;
		}
	}
	temp = minm;
	for (int i = end; i >= front; i--) {
		if (a[i] > temp) {
			tempr++;
			temp = a[i];
		} else {
			break;
		}
	}
	cout << v.size() + max(templ, tempr) << "\n";
	for (auto &it : v) {
		cout << it;
	}
	if (templ > tempr) {
		f(i, 0, templ) cout << 'L';
	} else {
		f(i, 0, tempr) cout << 'R';
	}

	return 0;
}