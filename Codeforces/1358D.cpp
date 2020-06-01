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
const ll N = 1e5 + 10;

int ss(int n) {
    return (n*(n+1)) / 2;
}

int32_t main() {
    fast_io();

    int n, x; cin >> n >> x;
    vector<pll> a(2*n);
    f (i, 0, n) cin >> a[i].second;
    f (i, n, 2*n) a[i] = a[i-n];
    int l = 0, r = 0;
    int ans = 0, ta = 0, tx = 0;
    debug(a);
    while (l < 2*n and r < 2*n) {
        tx += a[r].second;
        ta += ss(a[r].second);
        while (tx > x) {
            if (a[l].second - a[l].first < tx - x) {
                ta -= ss(a[l].second) - ss(a[l].first);
                tx -= a[l].second - a[l].first;
                l++;
            } else {
                ta -= ss(a[l].second) - ss(a[l].first);
                a[l].first += tx - x;
                ta += ss(a[l].second) - ss(a[l].first);
                tx = x;
            }
        }
        // debug(l, r, a[l], a[r], ta, tx);
        r++;
        ans = max(ans, ta);
    }
    cout << ans << endl;

    return 0;
}