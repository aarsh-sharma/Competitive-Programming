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

vector<pll> ans;

void travel(int x, int y, int dirn) {
  int temp = 0;
  while (true) {
    if ((dirn == 1 and x == 8) or (dirn == -1 and x == 1)) {
      break;
    }
    x += dirn;
    if (temp%2) {
      y -= 1;
    } else {
      y += 1;
    }
    temp++;
    ans.pb({x, y});
  }
}

void print(vector<pll> a) {
  for (auto &it : a) {
    cout << it.F << " " << it.S << endl;
  }
}

int32_t main() {
  fast_io();

  int t; cin >> t;
  travel(1, 1, 1);
  travel(8, 2, -1);
  travel(1, 3, 1);
  travel(8, 4, -1);
  travel(1, 5, 1);
  travel(8, 6, -1);
  travel(1, 7, 1);
  debug(ans.size());
  while (t--) {
    int x, y; cin >> x >> y;
    vector<pll> temp = {{x, y}};
    while (x > 1 and y > 1) {
      x--; y--;
      temp.pb({x, y});
    }
    while (x > 1) {
      x--;
      if (x%2) {
        y = 1;
      } else {
        y = 2;
      }
      temp.pb({x, y});
    }
    while (y > 1) {
      y--;
      if (y%2) {
        x = 1;
      } else {
        x = 2;
      }
      temp.pb({x, y});
    }
    cout << temp.size() + ans.size() << endl;
    print(temp);
    print(ans);
  }

  return 0;
}