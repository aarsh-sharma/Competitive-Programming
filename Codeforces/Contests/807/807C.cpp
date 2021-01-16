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
// #define endl "\n"
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
        vll maxi, mini;
        for (int i = 1; i <= n; i += 2) {
            if (i == n) {
                maxi.push_back(i);
                mini.push_back(i);
            } else {
                cout << "? " << i << " " << i+1 << endl;
                char what; cin >> what;
                if (what == '>') {
                    maxi.pb(i);
                    mini.pb(i+1);
                } else if (what == '<') {
                    maxi.pb(i+1);
                    mini.pb(i);
                } else {
                    maxi.pb(i);
                    mini.pb(i);
                }
            }
        }
        while (maxi.size() > 1 and mini.size() > 1) {
            vll tmaxi, tmini;
            // debug(maxi, mini);
            int nx = maxi.size(), nm = mini.size();
            for (int i = 0; i < nx; i += 2) {
                if (i == nx-1) tmaxi.pb(maxi[i]);
                else {
                    cout << "? " << maxi[i] << " " << maxi[i+1] << endl;
                    // debug("one");
                    char what; cin >> what;
                    if (what == '>') {
                        tmaxi.pb(maxi[i]);
                    } else {
                        tmaxi.pb(maxi[i+1]);
                    }
                }
            }
            for (int i = 0; i < nm; i += 2) {
                if (i == nm-1) tmini.pb(mini[i]);
                else {
                    cout << "? " << mini[i] << " " << mini[i+1] << endl;
                    // debug("two");
                    char what; cin >> what;
                    if (what == '>') {
                        tmini.pb(mini[i+1]);
                    } else {
                        tmini.pb(mini[i]);
                    }
                }
            }
            maxi = tmaxi;
            mini = tmini;
        }
        cout << "! " << mini.back() << ' ' << maxi.back() << endl;
    }

    return 0;
}