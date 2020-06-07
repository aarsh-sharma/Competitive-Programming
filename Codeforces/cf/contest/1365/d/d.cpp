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

bool change(vector<string> &a, int i, int j, int n, int m) {
    debug(i, j);
    if (i < 0 or j < 0 or i >= n or j >= m) return true;

    if (a[i][j] == 'G') return false;

    if (a[i][j] == '.') a[i][j] = '#';
    return true;
}

int isGood(vector<string> &a, queue<pair<int, int>> &q, vector<vector<int>> &vis, int i, int j, int n, int m) {
    if (i < 0 or j < 0 or i >= n or j >= m) return 0;

    if (!vis[i][j]) {
        vis[i][j] = 1;
        if (a[i][j] != '#') q.push({i, j});
        if (a[i][j] == 'G') return 1;
        if (a[i][j] == 'B') {
            return -1;
        }
    }

    return 0;
}

int32_t main() {
    fast_io();

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> a(n); f (i, 0, n) cin >> a[i];

        int good = 0, bad = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'G') good++;
                else if (a[i][j] == 'B') bad++;
            }
        }

        if (!good) {
            cout << "Yes\n";
            continue;
        }

        bool possible = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'B') {
                    bool flag = change(a, i-1, j, n, m);
                    bool flag1 = change(a, i+1, j, n, m);
                    bool flag2 = change(a, i, j-1, n, m);
                    bool flag3 = change(a, i, j+1, n, m);
                    if (!(flag and flag1 and flag2 and flag3)) {
                        possible = false;
                        break;
                    }
                }
            }
            if (!possible) break;
        }
        debug(possible);

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vll(m));
        q.push({n-1, m-1});
        int visgood = 0;
        vis[n-1][m-1] = 1;
        while (!q.empty()) {
            pll curr = q.front();
            q.pop();
            int one = isGood(a, q, vis, curr.first+1, curr.second, n, m);
            int two = isGood(a, q, vis, curr.first-1, curr.second, n, m);
            int three =  isGood(a, q, vis, curr.first, curr.second+1, n, m);
            int four = isGood(a, q, vis, curr.first, curr.second-1, n, m);

            if (one == -1 or two == -1 or three == -1 or four == -1) {
                possible = false;
                break;
            }

            visgood += one + two + three + four;
        }
        debug(possible, visgood, good);

        if (!possible or visgood != good) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}
