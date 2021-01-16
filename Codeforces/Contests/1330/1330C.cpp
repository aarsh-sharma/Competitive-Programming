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

int32_t main() {
    fast_io();

    int n, m; cin >> n >> m;
    int ss = 0;
    vll a(m); f (i, 0, m) { cin >> a[i]; ss += a[i]; }
    if (m > n or ss < n) {
        cout << -1 << endl;
        return 0;
    }
    int maxm = 0, remSum = n;
    vll ans;
    reverse(all(a));
    f (i, 0, m) {
        maxm = max(maxm+1, a[i]);
        if (n - maxm > ss-a[i]) {
            int diff = ((n-maxm) - (ss-a[i]));
            debug(diff);
            maxm += diff;
            ans.pb(maxm-a[i]+1);
        } else {
            ans.pb(maxm-a[i]+1);
        }
        if ((maxm-a[i]+1 < 1) or (maxm > n)) {
            debug(maxm, a[i]);
            cout << -1 << endl;
            return 0;
        }
        debug(ans);
        ss -= a[i];
    }
    reverse(all(ans));
    debug(ans);
    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}