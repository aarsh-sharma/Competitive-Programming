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
const ll inf = 1e9;
const ll N = 2e5 + 10;

vector<vector<int>> g;

// void bfs (int s, vll &d) {
//     queue<int> q;
//     vector<bool> used(N);
//     vector<int> p(N);

//     q.push(s);
//     used[s] = true;
//     p[s] = -1;
//     while (!q.empty())
//     {
//         int v = q.front();
//         q.pop();
//         for (int u : g[v])
//         {
//             if (!used[u])
//             {
//                 used[u] = true;
//                 q.push(u);
//                 d[u] = d[v] + 1;
//                 p[u] = v;
//             }
//         }
//     }
// }

void bfs(int s, vector<int> &d)
{
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto to : g[v])
        {
            if (d[to] == inf)
            {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
}

int32_t main() {
    fast_io();

    int t; cin >> t;
    while (t--) {
        int n, m, a, b, c; cin >> n >> m >> a >> b >> c;
        vll p(m); f(i, 0, m) cin >> p[i];
        sort(all(p));
        vll pref(m+1);
        f (i, 0, m) {
            pref[i+1] = pref[i] + p[i];
        }
		g = vector<vector<int>>(n+1);
        f (i, 0, m) {
            int u, v; cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        vll da(n+1, inf), db(n+1, inf), dc(n+1, inf);
        bfs(a, da);
        bfs(b, db);
        bfs(c, dc);
        int ans = 1e18;
        for (int i = 1; i <= n; ++i) {
            if (da[i] + db[i] + dc[i] > m) continue;
            ans = min(ans, pref[db[i]] + pref[da[i] + db[i] + dc[i]]);
        }
        cout << ans << endl;
    }

    return 0;
}