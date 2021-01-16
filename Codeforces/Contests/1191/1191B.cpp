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

  string s1, s2, s3; cin >> s1 >> s2 >> s3;
  map<string, int> mp;
  mp[s1]++;
  mp[s2]++;
  mp[s3]++;
  int ans = inf;
  for (auto &it : mp) {
    ans = min(ans, 3 - it.S);
  }
  vll s(10), p(10), m(10);
  if (s1[1] == 's') {
    s[s1[0] - '0'] = 1;
  } else if (s1[1] == 'p') {
    p[s1[0] - '0'] = 1;
  } else {
    m[s1[0] - '0'] = 1;
  }
  if (s2[1] == 's') {
    s[s2[0] - '0'] = 1;
  } else if (s2[1] == 'p') {
    p[s2[0] - '0'] = 1;
  } else {
    m[s2[0] - '0'] = 1;
  }
  if (s3[1] == 's') {
    s[s3[0] - '0'] = 1;
  } else if (s3[1] == 'p') {
    p[s3[0] - '0'] = 1;
  } else {
    m[s3[0] - '0'] = 1;
  }
  debug(ans, s, p, m);
  f (i, 1, 8) {
    // debug(s[i]+s[i+1]+s[i+2]);
    ans = min(ans, 3 - (s[i]+s[i+1]+s[i+2]));
    ans = min(ans, 3 - (p[i]+p[i+1]+p[i+2]));
    ans = min(ans, 3 - (m[i]+m[i+1]+m[i+2]));
  }
  cout << ans;

  return 0;
}