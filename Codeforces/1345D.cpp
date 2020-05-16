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

// https://leetcode.com/problems/number-of-islands/

int numIslands(vector<vector<char>>& a) {
    if (a.size() == 0) return 0;
    int n = a.size(), m = a[0].size();
    vector<vector<int>> vis(n, vector<int>(m));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') vis[i][j] = 1;
            if (vis[i][j]) continue;
            ans++;
            set<pair<int, int>> s;
            s.insert({i, j});
            while (s.size()) {
                pair<int, int> curr = *s.begin();
                s.erase(s.begin());
                if (curr.first > 0) {
                    if (a[curr.first-1][curr.second] == '#' and vis[curr.first-1][curr.second] == 0) {
                        vis[curr.first-1][curr.second] = 1;
                        s.insert({curr.first-1, curr.second});
                    }
                }
                if (curr.second > 0) {
                    if (a[curr.first][curr.second-1] == '#' and vis[curr.first][curr.second-1] == 0) {
                        vis[curr.first][curr.second-1] = 1;
                        s.insert({curr.first, curr.second-1});
                    }
                }
                if (curr.first < n-1) {
                    if (a[curr.first+1][curr.second] == '#' and vis[curr.first+1][curr.second] == 0) {
                        vis[curr.first+1][curr.second] = 1;
                        s.insert({curr.first+1, curr.second});
                    }
                }
                if (curr.second < m-1) {
                    if (a[curr.first][curr.second+1] == '#' and vis[curr.first][curr.second+1] == 0) {
                        vis[curr.first][curr.second+1] = 1;
                        s.insert({curr.first, curr.second+1});
                    }
                }
            }
        }
    }
    return ans;
}

bool check(vector<vector<char>> a, int n, int m) {
    // debug(a);
    set<int> s;
    int rem = 0;
    f (i, 0, n) {
        int ex = 0;
        vector<int> temp;
        f (j, 0, m) {
            if (a[i][j] == '#') {
                ex = 1;
                temp.pb(j);
                s.insert(j);
            }
        }
        // debug(temp);
        if (!ex) rem++;
        int nn = temp.size();
        for (int i = 1; i < nn; i++) {
            if (temp[i] - temp[i-1] > 1) return false;
        }
    }
    if (rem > 0 and (m - s.size() == 0)) return false;
    return true;
}

int32_t main() {
    fast_io();

    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    f (i, 0, n) f (j, 0, m) cin >> a[i][j];
    vector<vector<char>> b(m, vector<char>(n));
    f (i, 0, m) f (j, 0, n) b[i][j] = a[j][i];
    if (check(a, n, m) and check(b, m, n)) {
        cout << numIslands(a) << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}