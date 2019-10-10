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

vll primeFactors(int n) {
  vll ret;
  while (n % 2 == 0) {
    // cout << 2 << " ";
    if (find(all(ret), 2) == ret.end()) {
      ret.pb(2);
    }
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      // cout << i << " ";
      if (find(all(ret), i) == ret.end()) {
        ret.pb(i);
      }
      n = n / i;
    }
  }
  if (n > 2) {
    // cout << n << " ";
    if (find(all(ret), n) == ret.end()) {
      ret.pb(n);
    }
  }
  return ret;
}

int32_t main() {
  // fast_io();

  int t; cin >> t;
  debug(primeFactors(10000000000), primeFactors(10003800361));
  while (t--) {
    cout << "1 100000\n";
    fflush(stdout);
    int rem; cin >> rem;
    if (rem == 0) {
      cout << "1 2" << endl;
      fflush(stdout);
      int tt; cin >> tt;
      if (tt == 0) {
        cout << "2 2" << endl;
        fflush(stdout);
      } else {
        cout << "2 5" << endl;
        fflush(stdout);
      }
      string ss; cin >> ss;
      if (ss == "N0") {
        return 0;
      }
      continue;
    }
    int n = 10000000000 - rem;
    vll v = primeFactors(n);
    debug(v);
    cout << "1 100019\n";
    fflush(stdout);
    int rem2; cin >> rem2;
    int n2 = 10003800361 - rem2;
    vll v2 = primeFactors(n2);
    debug(v2);
    vll final;
    for (auto &it : v) {
      if (find(all(v2), it) != v2.end()) {
        final.pb(it);
      }
    }
    for (auto &it : final) {
      if ((10000000000%it == rem) and (10003800361%it == rem2)) {
        cout << "2 " << it << endl;
        fflush(stdout);
        // int tt; cin >> tt;
        // if (tt == 0) {
        //   cout << "2 " << it << endl;
        //   break;
        // }
        // break;
      }
    }
    string s; cin >> s;
    if (s == "No") {
      return 0;
    }
  }

  return 0;
}