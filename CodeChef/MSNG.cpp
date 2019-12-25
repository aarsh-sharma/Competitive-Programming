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

int val(char c) {
  if (c >= '0' && c <= '9')
    return (int)c - '0';
  else
    return (int)c - 'A' + 10;
}

int decimal(string str, int base)
{
  int len = str.size();
  int power = 1; // Initialize power of base
  int num = 0;   // Initialize result
  int i;

  for (i = len - 1; i >= 0; i--) {
    if (power > 1e12 or val(str[i]) >= base) {
      return -1;
    }

    num += val(str[i]) * power;
    power = power * base;
  }
  if (num <= 1e12) {
    return num;
  } else {
    return -1;
  }
}

int32_t main() {
  fast_io();

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int, int> x;
    f (_, 0, n) {
      int b; cin >> b;
      string y; cin >> y;
      if (b != -1) {
        int temp = decimal(y, b);
        // debug(temp);
        x[temp]++;
      } else {
        if (y.size() == 1) {
          x[decimal(y, 36)]++;
        } else {
          f (i, 2, 37) {
            int temp = decimal(y, i);
            // debug(temp, i);
            if (temp == -1) continue;
            x[temp]++;
          }
        }
      }
    }
    int flag = 0;
    // debug(x);
    for (auto &it : x) {
      if (it.F > 1e12) break;
      if (it.S == n) {
        cout << it.F << endl;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      cout << -1 << endl;
    }
  }

  return 0;
}