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
    vll prince(n);
    vll princess[n];
    int rem = -1;
    f (i, 0, n) {
      int nn; cin >> nn;
      f (j, 0, nn) {
        int temp; cin >> temp;
        princess[i].push_back(temp);
      }
      sort(all(princess[i]));
      int flag = 0;
      f (j, 0, nn) {
        if (prince[princess[i][j]-1] == 0) {
          prince[princess[i][j]-1] = 1;
          flag = 1;
          break;
        }
      }
      if (!flag and rem == -1) {
        rem = i;
      }
    }
    // debug(prince);
    if (rem == -1) {
      cout << "OPTIMAL\n";
    } else {
      cout << "IMPROVE\n";
      f (i, 0, n) {
        if (prince[i] == 0) {
          cout << rem+1 << " " << i+1 << endl;
          break;
        }
      }
    }

  }


  return 0;
}