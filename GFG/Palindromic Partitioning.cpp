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

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        vll dp(n);
        vector<vll> palin(n, vll(n));
        f (i, 0, n) {
            palin[i][i] = true;
        }
        f (gap, 2, n+1) {
            f (i, 0, n-gap+1) {
                int j = i + gap - 1;
                if (gap == 2) palin[i][j] = (s[i] == s[j]);
                else palin[i][j] = (s[i] == s[j]) and palin[i+1][j-1];
            }
        }
        f (i, 0, n) {
            if (palin[0][i] == true) {
                dp[i] = 0;
            } else {
                dp[i] = inf;
                f (j, 0, i) {
                    if (palin[j+1][i] == true and 1 + dp[j] < dp[i]) {
                        dp[i] = 1 + dp[j];
                    }
                }
            }
        }
        // debug(dp);
        cout << dp[n-1] << endl;
    }

    return 0;
}