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

vll divs(int n)
{
    vll res;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                // printf("%d ", i);
                res.pb(i);

            else // Otherwise print both
            {
                res.pb(i);
                res.pb(n/i);
            }
        }
    }
    return res;
}

int32_t main() {
    fast_io();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<int, vll> m;
        vll a(n+1);
        f (i, 1, n+1) {
            // int sz; cin >> sz;
            cin >> a[i];
            m[a[i]].pb(i);
        }
        vll dp(n+1);
        // dp[1] = 1;
        int maxm = 0;
        // for (auto ii : m) {
        //     debug(ii.first, ii.second);
        // }
        for (auto ii : m) {
            vector<pll> temp;
            for (auto el : ii.second) {
                vll div = divs(el);
                int ss = 0;
                for (auto ee : div) {
                    // if (dp[ee] and ) ss++;
                    ss = max(dp[ee], ss);
                }
                ss++;
                maxm = max(ss, maxm);
                temp.pb({el, ss});
                // debug(el, ss);
            }
            for (auto ii : temp) {
                dp[ii.first] = ii.second;
            }
        }

        // debug(dp, maxm);

        cout << maxm << endl;

    }

    return 0;
}