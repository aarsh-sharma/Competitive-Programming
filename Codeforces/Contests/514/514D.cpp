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

  int n, m, k; cin >> n >> m >> k;
  int a[n][m];
  f (i, 0, n) {
    f (j, 0, m) {
      cin >> a[i][j];
    }
  }
  vector<multiset<int>> ms(m);
  int ans[m] = {0};
  int start = 0, end = 0, flag = 1, ansLen = 0;
  while (start < n and end < n) {
    debug(start, end, flag);
    if (flag == 1) {
      f (j, 0, m) {
        (*(ms.begin()+j)).insert(a[end][j]);
      }
      flag = 0;
    }
    int tsm = 0;
    debug(ms);
    for (auto &it : ms) {
      tsm += *(--it.end());
    }
    debug(tsm);
    if (tsm > k) {
      // flag = 1;
      f(j, 0, m) {
        if ((*(ms.begin()+j)).size() > 0) {
          // flag = 0;
          auto it = (*(ms.begin()+j)).find(a[start][j]);
          (*(ms.begin()+j)).erase(it);
          // debug(*it);
        }
      }
      debug(start);
      start++;
      if (start > end) {
        flag = 1;
        end++;
      }
    } else {
      flag = 1;
      end++;
      int i = 0;
      if (end - start + 1 > ansLen) {
        ansLen = end - start + 1;
        for (auto &it : ms) {
          ans[i] = *(--it.end());
          i++;
        }
      }
    }
    debug(ms);
  }
  f (i, 0, m) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}