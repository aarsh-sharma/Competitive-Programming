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

  int n, I; cin >> n >> I;
  set<int> s;
  vll a(n);
  int num = 0, tt = 0;
  map<int, int> mp;
  f (i, 0, n) {
    cin >> a[i];
    mp[a[i]]++;
    s.insert(a[i]);
    if (a[i] == i+1) {
      num = 1;
    } else {
      tt++;
    }
  }
  int x = pow(2, (8*I)/n);
  int nn = mp.size();
  auto it = mp.begin();
  auto it2 = mp.begin();
  f (i, 0, x) it2++;
  // it2--;
  debug(x, *it, *it2);
  int maxi = 0;
  for (auto ii = it; ii != it2; ii++) {
    maxi += ii->S;
  }
  debug(maxi);
  int temp = maxi;
  for (int i = 1; i < nn-x; i++) {
    temp -= it->S;
    it++;
    temp += it2->S;
    it2++;
    if (temp > maxi) {
      maxi = temp;
    }
  }
  debug(maxi);
  cout << n - maxi;

  return 0;
}