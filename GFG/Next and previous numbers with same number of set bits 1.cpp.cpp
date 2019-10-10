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

int getNext(int n) {
  int ones = 0, zeroes = 0, c = n;
  while (!(c&1) and c!=0) {
    zeroes++;
    c >>= 1;
  }
  while (c&1) {
    ones++;
    c >>= 1;
  }
  int p = ones + zeroes;
  n |= (1 << p);
  n &= ~((1<<p) - 1);
  n|= (1<<(ones-1)) - 1;
  return n;
}

int getPrev(int n) {
  int ones = 0, zeroes = 0, c = n;
  while (c&1) {
    ones++;
    c >>= 1;
  }
  if (c == 0) {
    return -1;
  }
  while (!(c&1) and c!=0) {
    zeroes++;
    c >>= 1;
  }
  // trace(ones, zeroes);
  int p = ones + zeroes;
  n &= ((~0) << (p+1));
  int mask = (1 << (ones + 1)) - 1;
  n |= mask << (zeroes - 1);
  return 0;
}

int32_t main() {
  fast_io();

  int n; cin >> n;
  // to print previous number
  cout << "Previous: " << getPrev(n) << "\n";
  // to print next number
  cout << "Next: " << getNext(n) << "\n";

  return 0;
}