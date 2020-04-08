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

    int n, m, k; cin >> n >> m >> k;
    vector<string> a(n); f (i, 0, n) cin >> a[i];
    debug(a);
    vector<vll> ans(n, vll(m));
    // map<pll, int> mm;
    vector<vll> mm(n, vll(m, 0));
    set<pll> s;
    f (i, 0, n) {
        f (j, 0, m) {
            s.insert({i, j});
        }
    }
    while (s.size()) {
    int i = (*s.begin()).F, j = (*s.begin()).S;
        queue<pll> group; group.push({i, j});
        if (a[i][j] == '*') {
            // mm[{i, j}] = 1;
            mm[i][j] = 1;
            s.erase({i, j});
        }
        // if (mm[{i, j}] == 1) continue;
        if (mm[i][j] == 1) continue;
        int count = 0;
        vector<pll> alls = {{i, j}};
        while (!group.empty()) {
            pll curr = group.front();
            debug(curr);
            // mm[curr] = 1;
            mm[curr.F][curr.S] = 1;
            group.pop();
            if (curr.F > 0) {
                if (a[curr.F-1][curr.S] == '*') {
                    count++;
                } else {
                    if (mm[curr.F-1][curr.S] == 0) {
                        group.push({curr.F-1, curr.S});
                        alls.pb({curr.F-1, curr.S});
                    }
                }
                mm[curr.F-1][curr.S] = 1;
            }
            if (curr.S > 0) {
                if (a[curr.F][curr.S-1] == '*') {
                    count++;
                } else {
                    if (mm[curr.F][curr.S-1] == 0) {
                        group.push({curr.F, curr.S-1});
                        alls.pb({curr.F, curr.S-1});
                    }
                }
                mm[curr.F][curr.S-1] = 1;
            }
            if (curr.F < n-1) {
                if (a[curr.F+1][curr.S] == '*') {
                    count++;
                } else {
                    if (mm[curr.F+1][curr.S] == 0) {
                        group.push({curr.F+1, curr.S});
                        alls.pb({curr.F+1, curr.S});
                    }
                }
                mm[curr.F+1][curr.S] = 1;
            }
            if (curr.S < m-1) {
                if (a[curr.F][curr.S+1] == '*') {
                    count++;
                } else {
                    if (mm[curr.F][curr.S+1] == 0) {
                        group.push({curr.F, curr.S+1});
                        alls.pb({curr.F, curr.S+1});
                    }
                }
                mm[curr.F][curr.S+1] = 1;
            }
        }
        debug(count);
        for (auto it : alls) {
            s.erase(it);
            ans[it.F][it.S] = count;
        }
    }
    f (i, 0, k) {
        int x, y; cin >> x >> y;
        cout << ans[x-1][y-1] << endl;
    }

    return 0;
}