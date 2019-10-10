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

int sumPairs(vll arr, int n)
{
  // final result
  int sum = 0;
  for (int i = n - 1; i >= 0; i--)
    sum += i * arr[i] - (n - 1 - i) * arr[i];
  return sum;
}

int32_t main() {
  fast_io();

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vll a(n); f (i, 0, n) cin >> a[i];
    vll xo(n);
    xo[0] = a[0];
    f (i, 1, n) {
      xo[i] = xo[i-1]^a[i];
    }
    debug(xo);
    int ans = 0;
    int nn = *max_element(all(xo));
    vll num[nn+1];
    for (int i = 0; i < n; i++) {
      num[xo[i]].pb(i);
    }
    if (num[0].size() and a[0] != 0) {
      int l = num[0].size();
      f (i, 0, l) {
        ans += num[0][i];
      }
    }
    debug(ans);
    f (i, 0, nn+1) {
      int temp = 0, len = num[i].size(), tot = 0;
      ans += sumPairs(num[i], num[i].size()) - ((len*(len-1))/2);
    }
    cout << ans << endl;
  }

  return 0;
}