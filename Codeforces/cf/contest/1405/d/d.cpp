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
const ll N = 2e5 + 10;

int bfs(int s, int dest, int n, vector<vector<int>> &g) {
    queue<int> q;
    vector<bool> used(n+1);
    vector<int> d(n+1), p(n+1);

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : g[v])
        {
            if (!used[u])
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    // int maxm, one = d[dest];
    // sort(all(d));

    // if (g[s].size() == 1) maxm = d[n];
    // else maxm = d[n] + d[n-1];

    // return {one, maxm};
    return d[dest];
}

pair<int, int> longbfs(int u, int V, vector<vector<int>> &g)
{
    //  mark all distance with -1
    int dis[V];
    memset(dis, -1, sizeof(dis));

    queue<int> q;
    q.push(u);

    //  distance of u from u will be 0
    dis[u] = 0;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        //  loop for all adjacent nodes of node-t
        for (auto it = g[t].begin(); it != g[t].end(); it++)
        {
            int v = *it;

            // push node into queue only if
            // it is not visited already
            if (dis[v] == -1)
            {
                q.push(v);

                // make distance of v, one more
                // than distance of t
                dis[v] = dis[t] + 1;
            }
        }
    }

    int maxDis = 0;
    int nodeIdx;

    //  get farthest node distance and its index
    for (int i = 0; i < V; i++)
    {
        if (dis[i] > maxDis)
        {
            maxDis = dis[i];
            nodeIdx = i;
        }
    }
    return make_pair(nodeIdx, maxDis);
}

int longestPathLength(int n, vector<vector<int>> &g)
{
    pair<int, int> t1, t2;

    t1 = longbfs(1, n, g);

    t2 = longbfs(t1.first, n, g);

    // cout << "Longest path is from " << t1.first << " to " << t2.first << " of length " << t2.second;
    return t2.second;

}

int32_t main() {
    fast_io();

    int t; cin >> t;
    while (t--) {
        int n, a, b, da, db; cin >> n >> a >> b >> da >> db;
        vector<vector<int>> g(n + 1, vector<int> ());
        f (i, 0, n-1) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (db <= 2*da or da >= n/2) {
            cout << "Alice\n";
            continue;
        }

        int dist = bfs(a, b, n, g);
        int maxdist = longestPathLength(n+1, g);
        debug(dist, maxdist);
        if (dist <= da or maxdist <= 2*da) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }

    return 0;
}
