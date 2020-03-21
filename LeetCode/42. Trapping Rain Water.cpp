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
  vll a(n);
  f (i, 0, n) cin >> a[i];
  vll pos;
  int i = 0, ans = 0;
  while (i < n-1) {
    if (a[i] > 0) {
      auto next = max_element(a.begin()+i+1, a.end());
      if (*next > a[i]) {
        f (j, i+1, n) {
          if (a[j] > a[i]) {
            f (k, i+1, j) {
              ans += a[i] - a[k];
            }
            debug(i, j, ans);
            i = j;
            break;
          }
        }
      } else {
        int mini = min(*next, a[i]);
        for (auto it = a.begin()+i+1; it < next; it++) {
          ans += mini - *it;
        }
        debug(i, next-a.begin(), ans);
        i = next - a.begin();
      }
      continue;
    }
    i++;
  }
  cout << ans;

  // other answer
  /*
    int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vll a(n); f (i, 0, n) cin >> a[i];
    int ans = 0, idx = 0, flag = 1;
    while (flag) {
      f (i, idx+1, n) {
        if (a[i] >= a[idx]) {
          f (j, idx+1, i) {
            ans += min(a[idx], a[i]) - a[j];
          }
          idx = i;
        }
        if (i == n-1) flag = 0;
      }
      if (idx == n-1) break;
    }
    vll temp;
    f (i, idx, n) temp.pb(a[i]);
    reverse(all(temp));
    idx = 0, flag = 1, n = temp.size();
    while (flag) {
      f (i, idx+1, n) {
        if (temp[i] >= temp[idx]) {
          f (j, idx+1, i) {
            ans += min(temp[idx], temp[i]) - temp[j];
          }
          idx = i;
        }
        if (i >= n-1) flag = 0;
      }
      if (idx == n-1) break;
    }
    cout << ans << endl;
  }
  */

  return 0;
}