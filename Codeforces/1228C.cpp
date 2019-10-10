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

int spf[N];

void sieve()
{
  spf[1] = 1;
  for (int i = 2; i < N; i++)

    // marking smallest prime factor for every
    // number to be itself.
    spf[i] = i;

  // separately marking spf for every even
  // number as 2
  for (int i = 4; i < N; i += 2)
    spf[i] = 2;

  for (int i = 3; i * i < N; i++)
  {
    // checking if i is prime
    if (spf[i] == i)
    {
      // marking SPF for all numbers divisible by i
      for (int j = i * i; j < N; j += i)

        // marking spf[j] if it is not
        // previously marked
        if (spf[j] == j)
          spf[j] = i;
    }
  }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
  vector<int> ret;
  while (x != 1)
  {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}

int power(int x, int y, int p)
{
  int res = 1; // Initialize result

  x = x % p; // Update x if it is more than or
             // equal to p

  while (y > 0)
  {
    // If y is odd, multiply x with result
    if (y & 1)
      res = (res * x) % p;

    // y must be even now
    y = y >> 1; // y = y/2
    x = (x * x) % p;
  }
  return res;
}

int power1(int x, int y)
{
  int res = 1; // Initialize result

  while (y > 0)
  {
    // If y is odd, multiply x with result
    if (y & 1)
      res = res * x;

    // y must be even now
    y = y >> 1; // y = y/2
    x = x * x;  // Change x to x^2
  }
  return res;
}

int32_t main() {
  fast_io();

  int n, x; cin >> x >> n;
  set<int> factors;
  for (int i = 2; i * i <= x; ++i) //no sqrt, please
  {
    while (x % i == 0) //while, not if
    {
      factors.insert(i);
      x /= i;
    }
  }
  if (x != 1)
  {
    factors.insert(x);
  }
  int ans = 1;
  for (auto it : factors) {
    int nn = n;
    while (nn > 0)
    {
      nn /= it;
      ans = (ans%mod * power(it, nn, mod))%mod;
    }
  }
  cout << ans;

  return 0;
}