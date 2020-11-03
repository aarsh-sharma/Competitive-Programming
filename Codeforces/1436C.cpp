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
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const ll N = 1e6 + 10;

int factmod(int n, int p)
{
    if (n >= p)
        return 0;

    int result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % p;

    return result;
}

int MOD = 1e9 + 7;
inline int add(int a, int b, int mod = MOD)
{
    a += b;
    return a >= mod ? a - mod : a;
}
inline int sub(int a, int b, int mod = MOD)
{
    a -= b;
    return a < 0 ? a + mod : a;
}
inline int mul(int a, int b, int mod = MOD)
{
    return int((long long)a * b % mod);
}
inline int power(int base, long long ex, int mod = MOD)
{
    int res = 1;
    for (; ex > 0; ex >>= 1)
    {
        if (ex & 1)
            res = mul(res, base, mod);
        base = mul(base, base, mod);
    }
    return res;
}
inline int inv(int a, int mod = MOD)
{
    return power(a, mod - 2, mod);
}
inline int mdiv(int a, int b, int mod = MOD)
{
    return mul(a, power(b, mod - 2, mod));
}
inline void adds(int &a, int b, int mod = MOD)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
inline void subs(int &a, int b, int mod = MOD)
{
    a -= b;
    if (a < 0)
        a += mod;
}
inline void muls(int &a, int b, int mod = MOD)
{
    a = int((long long)a * b % mod);
}
inline void mdivs(int &a, int b, int mod = MOD)
{
    a = mdiv(a, b, mod);
}
vector<int> fact, ifact;
void prep_fact(int mx = N + 40)
{
    fact.assign(mx, 0);
    ifact.assign(mx, 0);
    fact[0] = 1;
    for (int i = 1; i < mx; ++i)
        fact[i] = mul(i, fact[i - 1]);
    ifact[mx - 1] = inv(fact[mx - 1]);
    for (int i = mx - 1; i > 0; --i)
        ifact[i - 1] = mul(i, ifact[i]);
}
inline int ncr(int n, int r)
{
    if (n < r || r < 0 || n < 0)
        return 0;
    return mul(fact[n], mul(ifact[n - r], ifact[r]));
}

pll bin_count(int n, int pos) {
    int l = 0, r = n, less = 0, more = 0;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mid == pos) {
            l = mid + 1;
            continue;
        }
        if (mid < pos) {
            less++;
            l = mid + 1;
        } else {
            more++;
            r = mid;
        }
    }
    return {less, more};
}

int32_t main() {
    fast_io();

    prep_fact();
    int n, x, pos; cin >> n >> x >> pos;
    pll lm = bin_count(n, pos);
    debug(lm, n - lm.first - lm.second - 1);

    int ans = mul(mul(mul(ncr(x-1, lm.first), fact[lm.first]), mul(ncr(n-x, lm.second), fact[lm.second])), fact[n - lm.first - lm.second - 1]);

    cout << ans << endl;

    return 0;
}

