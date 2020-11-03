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
        int n, len; cin >> n >> len;
        vll a(n+2); f (i, 1, n+1) cin >> a[i];
        a[0] = 0, a[n+1] = len;
        int l = 0, r = n+1;
        double ta = 0, tb = 0;
        double ans = 0;
        int sa = 1, sb = 1;

        while (r - l > 1) {
            int fa = 0, fb = 0;
            if (ta == 0) {
                ta = ((a[l+1] - a[l]) * 1.0) / (sa * 1.0);
                fa = 1;
            }
            // debug(l, r, ta, tb, ans);
            if (tb == 0) {
                tb = ((a[r] - a[r-1]) * 1.0) / (sb * 1.0);
                fb = 1;
            }
            if (ta == tb) {
                l++; r--;
                sa++; sb++;
                ans += ta;
                ta = 0; tb = 0;
            } else if (ta < tb) {
                l++; sa++;
                tb = (((a[r] - a[r-1]) * 1.0) / (sb * 1.0)) - ta - (fb ? 0.0 : ((a[r] - a[r-1]) * 1.0) / (sb * 1.0) - tb);
                ans += ta;
                ta = 0;
            } else {
                r--; sb++;
                // ta = (((a[l+1] - a[l]) * 1.0) / (sa * 1.0)) - tb - (fa ? 0.0 : ta);
                ta = (((a[l+1] - a[l]) * 1.0) / (sa * 1.0)) - tb - (fa ? 0.0 : ((a[l+1] - a[l]) * 1.0) / (sa * 1.0) - ta);
                ans += tb;
                tb = 0;
            }
        }

        // debug(l, r, ta, tb, ans);

        if (ta != 0) {
            double dist = a[r] - a[l] - (sa * (((a[l+1] - a[l] * 1.0) / (sa * 1.0)) - ta));
            ans += dist / ((sa + sb) * 1.0);
        } else if (tb != 0) {
            double dist = a[r] - a[l] - (sb * (((a[r] - a[r-1] * 1.0) / (sb * 1.0)) - tb));
            ans += dist / ((sa + sb) * 1.0);
        } else {
            ans += ((a[r] - a[l]) * 1.0) / ((sa + sb) * 1.0);
        }

        cout << fixed << setprecision(6) << ans << endl;
    }

    return 0;
}