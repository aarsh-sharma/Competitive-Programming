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
  map<char, int> m;
  string s; cin >> s;
  f (i, 0, n) m[s[i]]++;
  debug(m);
  if (m.size() == 3) {
    cout << "BGR";
  } else if (m.size() == 1) {
    cout << m.begin()->F;
  } else {
    vll counts;
    string in, rem = "BGR";
    for (auto &it : m) {
      counts.pb(it.S);
      in.pb(it.F);
      rem.erase(rem.find(it.F), 1);
      debug(it.F, rem);
    }
    sort(all(counts));
    debug(in, rem);
    sort(all(rem));
    if (counts[0] == 1 and counts[1] == 1) {
      cout << rem;
    } else if (counts[0] == 1 and counts[1] == 2) {
      string ts = rem;
      for (auto &it : m) {
        if (it.S != 2) {
          ts += it.F;
        }
      }
      sort(all(ts));
      cout << ts;
    } else if (counts[0] == 1) {
      string ts = rem;
      for (auto &it : m) {
        if (it.S == 1) {
          ts += it.F;
        }
      }
      sort(all(ts));
      cout << ts;
    } 
    else {
      cout << "BGR";
    }
  }

  return 0;
}