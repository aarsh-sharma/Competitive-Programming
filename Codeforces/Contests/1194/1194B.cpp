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

  int q; cin >> q;
  while (q--) {
    int n, m; cin >> n >> m;
    vll row(m), col(n); string a[n];
    f (i, 0, n) cin >> a[i];
    f (i, 0, n) {
      f (j, 0, m) {
        if (i == 0) {
          if (a[i][j] == '*') {
            row[j] = 1;
          }
          continue;
        }
        if (a[i][j] == '*') {
          row[j] = row[j]+1;
        } else {
          row[j] = row[j];
        }
      }
      // debug(i, row);
    }
    f (j, 0, m) {
      f (i, 0, n) {
        if (j == 0) {
          if (a[i][j] == '*') {
            col[i] = 1;
          }
          continue;
        }
        if (a[i][j] == '*') {
          col[i] = col[i]+1;
        }
      }
      // debug(j, col);
    }
    int maxi = *max_element(all(row));
    vll on;
    f (j, 0, m) {
      if (row[j] == maxi) {
        on.pb(j);
      }
    }
    int maxi2 = *max_element(all(col));
    vll tw;
    f (j, 0, n) {
      if (col[j] == maxi2) {
        tw.pb(j);
      }
    }
    int flag = 0;
    for (auto it1 : on) {
      for (auto it2 : tw) {
        if (a[it2][it1] == '.') {
          flag = 1;
          break;
        } 
      }
      if (flag) {
        break;
      }
    }
    
    // debug(row, col);
    int ans = (n - *max_element(all(row))) + (m - *max_element(all(col))) - flag;

    cout << ans << endl;
  }

  return 0;
}