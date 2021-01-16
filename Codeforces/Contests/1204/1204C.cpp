// aarsh01rsh@gmail.com
// Aarsh Sharma
#include<bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}
string to_string(char ch) {
  string s(1, ch);
  return '\'' + s + '\'';
}
string to_string(const char *s) {
  return to_string((string)s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define f(i, x, n) for (int i = x; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());
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

  int n; cin >> n;
  // string s[n]; f (i, 0, n) cin >> s[i];
  int adj[101][101];
  for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < n; ++j) {
			adj[i+1][j+1] = (s[j] - '0');
		}
	}
	for (int i = 0; i < n; ++i) {
		adj[i+1][i+1] = 1;
	}
  int m; cin >> m;
  vll a(m+1); f (i, 0, m) cin >> a[i];
  if (m == 2) {
    cout << 2 << endl;
    cout << a[0] << " " << a[1];
    return 0;
  }
  int d[101][101];
  for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d[i][j] = adj[i][j];
			if(d[i][j] == 0){
				d[i][j] = 100000;
			}
		}
	}
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        // cout << d[i][j];
      }
    }
  }
  vll ans;
  int first = a[0];
  int prev = a[0];
  int v = a[0];
  int len = 0;
  f (i, 0, m) {
    debug(a[i-1], a[i+1]);
    prev = v;
    v = a[i];
    if (d[first][v] < len) {
      // debug(d[first-1][a[i+1]-1]);
      ans.pb(prev);
      first = prev;
      len = 1;
    } 
    len++;
  }
  cout << ans.size()+2 << endl;
  cout << a[0] << " ";
  for (auto &it : ans) {
    cout << it << " ";
  }
  cout << a[m-1];

  return 0;
}