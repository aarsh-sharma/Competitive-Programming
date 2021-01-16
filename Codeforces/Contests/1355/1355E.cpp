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

int n, a, r, m;
vll hh(N);

int check(int h) {
    int more = 0, less = 0, res = 0;
    f (i, 0, n) {
        if (hh[i] > h) more += hh[i] - h;
        else less += h - hh[i];
    }
    if (more > less) {
        res += (more - less) * r;
        res += less * m;
    } else {
        res += (less - more) * a;
        res += more * m;
    }
    // debug(h, less, more, res, a, r, m);
    return res;
}

int32_t main() {
    fast_io();

    cin >> n >> a >> r >> m;
    m = min(a+r, m);
    f (i, 0, n) cin >> hh[i];
    int mini = *min_element(all(hh));
    f (i, 0, n) hh[i] -= mini;

    int l = 0, r = 1e9;
    while (l < r - 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = check(m1);
        int f2 = check(m2);
        if (f1 <= f2)
            r = m2;
        else
            l = m1;
    }
    int ans = inf;
    f (i, l, r+1) ans = min(ans, check(i));

    cout << ans << "\n";

    return 0;
}