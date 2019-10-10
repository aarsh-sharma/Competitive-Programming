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
const ll N = 1e6 + 10;

// Generating the look-up table while pre-processing
#define P2(n) n, n ^ 1, n ^ 1, n
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n)
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n)
#define LOOK_UP P6(0), P6(1), P6(1), P6(0)

// LOOK_UP is the macro expansion to generate the table
int table[256] = {LOOK_UP};

// Function to find the parity
int Parity(int num) {
  // Number is considered to be of 32 bits
  int max = 16;
  // Dividing the number into 8-bit
  // chunks while performing X-OR
  while (max >= 8) {
    num = num ^ (num >> max);
    max = max / 2;
  }
  // Masking the number with 0xff (11111111)
  // to produce valid 8-bit result
  return table[num & 0xff];
}

int32_t main() {
  // fast_io();

  int t; cin >> t;
  while (t--) {
    int q; cin >> q;
    int odd = 0, even = 0;
    vector<int> s;
    vll vv;
    vector<int> occ(N, 0);
    while (q--) {
      int x; cin >> x;


      debug(Parity(x));
      if (occ[x]) {
        cout << even << " " << odd << endl;
        continue;
      }
      vll tv;
      for (auto &it : vv) {
        if (it != x) {
          int num = it^x;
          tv.push_back(num);
        }
      }
      tv.push_back(x);
      for (auto &it : tv) {
        if (!occ[it]) {
          occ[it] = 1;
          vv.pb(it);
          if (Parity(it)) {
            odd++;
          } else {
            even++;
          }
        }
      }
      debug(vv);



      // if (find(all(s), x) != s.end()) {
      //   cout << even << " " << odd << endl;
      //   continue;
      // }
      // auto ss = s.end();
      // vll tv;
      // for (auto &it : s) {
      //   if (it != x) {
      //     tv.push_back(it^x);
      //   }
      // }
      // tv.push_back(x);
      // for (auto &it : tv) {
      //   if (find(all(s), it) == s.end()) {
      //     s.pb(it);
      //     if (Parity(it)) {
      //       odd++;
      //     } else {
      //       even++;
      //     }
      //   }
      // }



      cout << even << " " << odd << endl;

    }
  }

  return 0;
}