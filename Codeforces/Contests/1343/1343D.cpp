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
#define sz(a) int((a).size())
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

bool inRange(pll range, int n) {
    return (n >= range.F and n <= range.S);
}

int32_t main() {
    fast_io();

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vll a(n); f (i, 0, n) cin >> a[i];
        vector<pll> ranges;
        map<int, int> m;
        f (i, 0, n/2) {
            int one = a[i], two = a[n-1-i];
            ranges.pb({min(one, two) + 1, max(one, two) + k});
            m[one+two]++;
        }
        pll mainRange = {0, inf};
        for (auto it : ranges) {
            mainRange.F = max(mainRange.F, it.F);
            mainRange.S = min(mainRange.S, it.S);
        }
        debug(ranges.size(), mainRange);
        debug(ranges);
        int ans = n/2;
        vector<pll> mm;
        for (auto it : m) {
            mm.pb({it.S, it.F});
        }
        sort(rall(mm));
        for (auto it : mm) {
            if (inRange(mainRange, it.S)) {
                ans = min(ans, n/2 - it.F);
            } else {
                if (it.F < n/2 - ans + 2) continue;
                debug(n/2-ans+1);
                int tt = 0;
                for (auto range : ranges) {
                    if (!inRange(range, it.S)) {
                        tt++;
                    }
                    tt++;
                }
                ans = min(ans, tt-it.F);
            }
        }
        cout << min(ans, n/2) << endl;
    }

    return 0;
}