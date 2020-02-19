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

vll parent(N, -1), strength(N);

void make_set(int v) {
  parent[v] = v;
  strength[v] = 1;
}

int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (strength[a] < strength[b]) {
      swap(a, b);
    }
    parent[b] = a;
    strength[a] += strength[b];
  }
}

int32_t main() {
  fast_io();

  int n; cin >> n;
  vector<string> ss;
  f (i, 0, n) {
    string s; cin >> s;
    ss.pb(s);
    int nn = s.size();
    f (i, 0, nn) {
      if (parent[s[i]-'a'] == -1) {
        make_set(s[i]-'a');
      }
    }
    f (i, 1, nn) {
      union_sets(s[i]-'a', s[i-1]-'a');
    }
  }
  set<int> sss;
  f (i, 0, 26) {
    if (parent[i] != -1) {
      debug(find_set(i), parent[i]);
      sss.insert(find_set(i));
    }
  }
  cout << sss.size();

  return 0;
}