// aarsh01rsh@gmail.com
// Aarsh Sharma
#include<bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
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

int k;
map<pair<int, string>, int> ans;
vector<string> ss;

void find_all(string s) {
  ss.pb(s);
  auto it = ss.begin();
  // debug(ss);
  f (m, 0, ss.size()) {
    set<string> sss;
    int l = (ss[m]).size();
    f (i, 0, l) {
      string ts = "";
      f (j, 0, l) {
        if (j == i) {
          continue;
        }
        ts += (ss[m])[j];
      }
      ans[{ts.size(), ts}]++;
      if (ans.size() > k) {
        return;
      }
      // ss.pb(ts);
      sss.insert(ts);
      // debug(ts);
    }
    for (auto &it : sss) {
      ss.pb(it);
    }
    // it++;
    // if (it == ss.end()) {
    //   debug(1);
    //   break;
    // }
    debug(ss[m]);
  }
}

int32_t main() {
  fast_io();

  int n; cin >> n >> k;
  string s; cin >> s;
  find_all(s);
  if (ans.size()+1 < k) {
    cout << -1;
    return 0;
  }
  auto it = ans.rbegin();
  int sm = 0;
  int l = s.size();
  f (i, 0, k-1) {
    // debug(*it);
    sm += l - it->F.F;
    it++;
  }
  debug(ans);
  // if (ans.size()+1 == k) {
  //   sm += s.size();
  // }
  cout << sm;

  return 0;
}