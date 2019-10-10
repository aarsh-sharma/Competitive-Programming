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

  int t; cin >> t;
  while (t--) {
    int r, c; cin >> r >> c;
    int a[r][c];
    queue<pll> rotten;
    f (i, 0, r) {
      f (j, 0, c) {
        cin >> a[i][j];
        if (a[i][j] == 2) {
          rotten.push({i, j});
        }
      }
    }
    while (!rotten.empty()) {
      pll pos = rotten.front();
      rotten.pop();
      if (pos.first - 1 >= 0) {
        if (a[pos.first - 1][pos.second] == 1) {
          a[pos.first - 1][pos.second] = a[pos.first][pos.second] + 1;
          rotten.push({pos.first - 1, pos.second});
        }
      }
      if (pos.first + 1 < r) {
        if (a[pos.first + 1][pos.second] == 1) {
          a[pos.first + 1][pos.second] = a[pos.first][pos.second] + 1;
          rotten.push({pos.first + 1, pos.second});
        }
      }
      if (pos.second - 1 >= 0) {
        if (a[pos.first][pos.second - 1] == 1) {
          a[pos.first][pos.second - 1] = a[pos.first][pos.second] + 1;
          rotten.push({pos.first, pos.second - 1});
        }
      }
      if (pos.second + 1 < c) {
        if (a[pos.first][pos.second + 1] == 1) {
          a[pos.first][pos.second + 1] = a[pos.first][pos.second] + 1;
          rotten.push({pos.first, pos.second + 1});
        }
      }
    }
    bool ans = true; int days = 0;
    f (i, 0, r) {
      f (j, 0, c) {
        if (a[i][j] == 1) {
          ans = false;
          break;
        }
        if (a[i][j] > days) {
          days = a[i][j];
        }
      }
      if (!ans) {
        break;
      }
    }
    if (ans and days >= 2) {
      cout << days - 2 << "\n";
    } else {
      cout << "-1\n";
    }

  }

  return 0;
}