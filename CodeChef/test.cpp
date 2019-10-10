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
const ll N = 1e6 + 10;

int32_t main() {
  fast_io();

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vll g[n+1];
    f (i, 0, m) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    if (m%2) {
      int idx = -1, flag = 0;
      f (i, 1, n+1) {
        if (g[i].size()%2) {
          idx = i;
          flag = 1;
          break;
        }
      }
      if (flag) {
        cout << "2\n";
        f (i, 1, n+1) {
          if (idx == i) cout << "2 ";
          else cout << "1 ";
        }
      } else {
        cout << "3\n";
        int num = 0;
        f (i, 1, n+1) {
          if (num < 2 and g[i].size()) {
            num++;
            cout << num << " ";
          } else {
            cout << "3 ";
          }
        }
      }
    } else {
      cout << "1\n";
      f (i, 0, n) {
        cout << "1 ";
      }
    }
    cout << endl;
  }

  return 0;
}