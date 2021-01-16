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
const ll inf = LLONG_MAX;
const ll N = 2e5 + 10;

vll g[N];
int n;

vector<bool> visited;

set<pair<int, pll>> det; // depth, children, node
vector<int> d(N), p(N);
queue<int> q;
vector<bool> used(N);
vector<int> hap(N);

vll count1(N+1);

void numberOfNodes(int s, int e)
{
    vector<int>::iterator u;
    count1[s] = 1;
    for (u = g[s].begin(); u != g[s].end(); u++)
    {

        // condition to omit reverse path
        // path from children to parent
        if (*u == e)
            continue;

        // recursive call for DFS
        numberOfNodes(*u, s);

        // update count[] value of parent using
        // its children
        count1[s] += count1[*u];
    }
}

void bfs(int s = 1) {

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
}

int32_t main() {
    fast_io();

    int k; cin >> n >> k;
    f (i, 0, n-1) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    numberOfNodes(1, 0);
    bfs(1);
    int ans = 0;
    // f (i, 0, n+1) cout << count1[i] << " "; cout << endl;
    vll times;
    f (i, 1, n+1) {
        times.pb(d[i] - (count1[i] - 1));
    }
    sort(rall(times));
    debug(times);
    f (i, 0, k) {
        ans += times[i];
    }
    cout << ans;



    return 0;
}