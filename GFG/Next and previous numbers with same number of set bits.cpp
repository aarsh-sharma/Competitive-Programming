// aarsh01rsh@gmail.com
// Aarsh Sharma
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
#define f(i, x, n) for (int i = x; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
  vector<int> bits(20);
  for (int i = 20; i >= 0; i--) {
    if (pow(2, i) <= n) {
      bits[i] = 1;
      n -= pow(2, i);
    }
  }
  f (i, 0, 20) cout << bits[i]; cout << endl;
  int flag = 0, next = 0, prev = 0;
  // calculating next
  for (int i = 0; i <= 20; i++) {
    if (bits[i] == 0) {
      if (flag) {
        // trace(i, flag);
        swap(bits[i], bits[i-1]);
        f (j, 0, 20) cout << bits[j]; cout << endl;
        f (j, 0, 20) {
          if (bits[j]) {
            next += pow(2, j);
          }
        }
        swap(bits[i], bits[i-1]);
        break;
      }
    } else {
      flag = 1;
    }
  }
  cout << "Next: " << next << endl;
  // calculating previous
  flag = 0;
  f (i, 0, 20) {
    if (bits[i] == 1) {
      if (flag) {
        swap(bits[i], bits[i-1]);
        int ones = 0;
        f (j, 0, i-1) {
          if (bits[j] == 1) ones++;
        }
        for (int j = i-2; j >= 0; j--) {
          if (ones) {
            bits[j] = 1;
            ones--;
          } else {
            bits[j] = 0;
          }
        }
        f (j, 0, 20) cout << bits[j]; cout << endl;
        f (j, 0, 20) {
          if (bits[j]) {
            prev += pow(2, j);
          }
        }
        break;
      }
    } else {
      flag = 1;
    }
  }
  cout << "Previous: " << prev << endl;

  return 0;
}