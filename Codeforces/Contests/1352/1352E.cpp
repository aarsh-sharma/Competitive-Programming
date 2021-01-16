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

int32_t main() {
    fast_io();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll a(n); f (i, 0, n) cin >> a[i];
        // vll pre(n+1);
        // int ss = 0;
        // unordered_map<int, pair<int, int>> m;
        // m[0] = {1, 0};
        // f (i, 0, n) {
        //     ss += a[i];
        //     m[ss] = {1, i+1};
        //     pre[i+1] = ss;
        // }
        int ans = 0;
        f (i, 0, n) {
            int l = 0, r = 0;
            int val = a[i], tt = 0;
            while (l <= n and r <= n) {
                if (tt == val and r-l > 1) {
                    // debug(l, r, val);
                    ans++;
                    break;
                }
                if (tt < val) {
                    if (r == n) break;
                    tt += a[r];
                    r++;
                } else {
                    tt -= a[l];
                    l++;
                }
            }
        }
        cout << ans << endl;
        // int ans = 0;
        // // debug(pre);
        // // debug(m);
        // f (i, 0, n) {
        //     // debug(a[i]);
        //     f (j, 0, n) {
        //         if (m.find(pre[j] + a[i]) != m.end()) {
        //             if (abs(m[pre[j]+a[i]].second - m[pre[j]].second) <= 1) continue;
        //             ans++;
        //             // debug(m[pre[j]+a[i]], m[pre[j]]);
        //             break;
        //         }
        //     }
        // }
        // cout << ans << endl;
    }

    return 0;
}