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
const ll N = 2e5 + 10;

vll g[N];

int32_t main() {
  fast_io();

  int n, m; cin >> n >> m;
  f (i, 0, n-1) {
    int u, v; cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vll d(N), p(N), tin(N), tout(N);
  int T = 0;
  function<void(int, int, int)> dfs = [&](int v, int par, int dep) {
    p[v] = par;
    d[v] = dep;
    tin[v] = T++;
    for (auto to : g[v]) {
      if (to == par) continue;
      dfs(to, v, dep+1);
    }
    tout[v] = T++;
  };
  dfs(1, -1, 0);
  auto isAnc = [&](int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
  };
  f (i, 0, m) {
    int k; cin >> k;
    vll v(k); f(i, 0, k) cin >> v[i];
    int u = v[0];
    for (auto it : v) if (d[u] < d[it]) u = it;
    for (auto &it : v) {
      if (it == u) continue;
      if (p[it] != -1) it = p[it];
    }
    bool ok = true;
    for (auto it : v) ok &= isAnc(it, u);
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}