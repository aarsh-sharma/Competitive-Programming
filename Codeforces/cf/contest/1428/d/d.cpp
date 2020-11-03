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

    int n; cin >> n;
    vll a(n); f (i, 0, n) cin >> a[i];
    vector<pair<int, vll>> coldata(n, pair<int, vll> ({0, {0, 0}}));
    vector<vll> rowval(n);
    vll rowcount(n);
    int twos = n-1, threes = n-1, row = n-1;
    bool possible = true;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            rowcount[row] = 1;
            rowval[i].push_back(row);
            coldata[i].first = 1;
            coldata[i].second[0] = 1;
            row--;
        } else if (a[i] == 2) {
            int flag = 0;
            while (twos > i) {
                if (coldata[twos].first == 1 and rowcount[rowval[twos][0]] == 1) {
                    rowcount[rowval[twos][0]] = 2;
                    coldata[twos].second[0] = 2;
                    rowval[i].push_back(rowval[twos][0]);
                    coldata[i].first = 1;
                    coldata[i].second[0] = 1;
                    flag = 1;
                    break;
                }
                twos--;
            }
            if (!flag) possible = false;
        } else {
            int flag = 0;
            while (threes > i) {
                if (coldata[threes].first == 1 and coldata[threes].second[0] == 1) {
                    rowcount[row] = 2;
                    coldata[threes].first = 2;
                    coldata[threes].second[1] = 2;
                    coldata[i].first = 1;
                    coldata[i].second[0] = 1;
                    rowval[threes].push_back(row);
                    rowval[i].push_back(row);
                    row--;
                    flag = 1;
                    break;
                }
                threes--;
            }
            if (!flag) possible = false;
        }
        if (!possible) break;
    }
    for (auto it : coldata) {
        debug(it.first, it.second);
    }

    if (!possible) cout << -1 << endl;
    else {
        vector<pll> ans;
        for (int i = n-1; i >= 0; i--) {
            for (auto row : rowval[i]) {
                ans.push_back({row+1, i+1});
            }
        }
        cout << ans.size() << endl;
        for (auto it : ans) {
            cout << it.first << ' ' << it.second << endl;
        }
    }

    return 0;
}
