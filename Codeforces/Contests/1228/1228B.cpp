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

int power(int x, int y, int p)
{
  int res = 1; // Initialize result

  x = x % p; // Update x if it is more than or
             // equal to p

  while (y > 0)
  {
    // If y is odd, multiply x with result
    if (y & 1)
      res = (res * x) % p;

    // y must be even now
    y = y >> 1; // y = y/2
    x = (x * x) % p;
  }
  return res;
}

int32_t main() {
  fast_io();

  int h, w; cin >> h >> w;
  vll a(h); f (i, 0, h) cin >> a[i];
  vll b(w); f (i, 0, w) cin >> b[i];
  // int g[h][w];
  vector<vll> g(h, vll(w));
  int filled = 0;
  f (i, 0, h) {
    f (j, 0, a[i]) {
      g[i][j] = 1;
    }
    if (a[i] < w) {
      g[i][a[i]] = 2;
    }
  }
  debug("good");
  f (i, 0, w) {
    f (j, 0, b[i]) {
      if (g[j][i] == 2) {
        cout << 0;
        return 0;
      }
      g[j][i] = 1;
    }
    if (b[i] < h) {
      if (g[b[i]][i] == 1) {
        cout << 0;
        return 0;
      }
      g[b[i]][i] = 2;
    }
  }
  debug("good");
  f (i, 0, h) {
    f (j, 0, w) {
      if (g[i][j]) {
        filled++;
      }
    }
  }
  int rem = (h*w) - filled;
  // if (rem == 0) cout << 0;
  cout << power(2, rem, mod);

  return 0;
}