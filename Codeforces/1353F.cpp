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
const ll inf = 1e18;
const ll N = 1e5 + 10;

int32_t main() {
    fast_io();

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vll> a(n, vll(m));
        f (i, 0, n) f (j, 0, m) cin >> a[i][j];

        int a00 = a[0][0], ans = inf;

        f (x, 0, n) f (y, 0, m) {
            int need = a[x][y] - x - y;
            if (need > a00) continue;
            a[0][0] = need;
            vector<vll> dp(n, vll(m, inf));
            dp[0][0] = a00 - need;

            f (i, 0, n) f (j, 0, m) {
                int need = a[0][0] + i + j;
                if (need > a[i][j]) continue;
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i][j] - need);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + a[i][j] - need);
            }
            ans = min(ans, dp[n-1][m-1]);
        }

        cout << ans << endl;
    }

    return 0;
}