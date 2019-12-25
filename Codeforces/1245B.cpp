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

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    string s; cin >> s;
    map<char, int> m;
    for (auto c : s) {
      m[c]++;
    }
    int lim = ceil(n/2.0);
    int temp1 = min(b, m['R']);
    lim -= temp1;
    b -= temp1;
    m['R'] -= temp1;
    int temp2 = min(c, m['P']);
    lim -= temp2;
    c -= temp2;
    m['P'] -= temp2;
    int temp3 = min(a, m['S']);
    lim -= temp3;
    a -= temp3;
    m['S'] -= temp3;

    int same1 = min(a, m['R']);
    a -= same1;
    m['R'] -= same1;
    int same2 = min(b, m['P']);
    b -= same2;
    m['P'] -= same2;
    int same3 = min(c, m['S']);
    c -= same3;
    m['S'] -= same3;

    // lim += a + b + c;
    if (lim > 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES\n";
      string ans;
      int i = 0;
      for (auto c : s) {
        debug(c);
        if (c == 'R') {
          debug(temp1, same1);
          if (temp1) {
            temp1--;
            ans += 'P';
          } else if (same1) {
            same1--;
            ans += 'R';
          } else {
            ans += 'S';
          }
        } else if (c == 'P') {
          debug(temp2, same2);
          if (temp2) {
            temp2--;
            ans += 'S';
          } else if (same2) {
            same2--;
            ans += 'P';
          } else {
            ans += 'R';
          }
        } else if (c == 'S') {
          if (temp3) {
            temp3--;
            ans += 'R';
          } else if (same3) {
            same3--;
            ans += 'S';
          } else {
            ans += 'P';
          }
        }
        i++;
      }
      cout << ans << endl;
    }
  }

  return 0;
}