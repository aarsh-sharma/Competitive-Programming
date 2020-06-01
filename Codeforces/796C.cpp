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
// #define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const ll N = 3e5 + 10;

int n;
vector<int> adj[N];


int32_t main() {
    fast_io();

    cin >> n;
    multiset<int> mm;
    vector<int> a(n+1); f (i, 1, n+1) { cin >> a[i]; mm.emplace(a[i]); }
    f (i, 0, n-1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = INT_MAX;
    f (i, 1, n+1) {
        int cur = a[i], ne = INT_MIN, sene = INT_MIN;
        for (auto ii : adj[i]) {
            mm.erase(mm.find(a[ii]));
            ne = max(ne, a[ii] + 1);
        }
        mm.erase(mm.find(a[i]));
        if (mm.size()) sene = *mm.rbegin() + 2;
        for (auto ii : adj[i]) {
            mm.emplace(a[ii]);
        }
        mm.emplace(a[i]);
        cur = max({cur, ne, sene});
        ans = min(ans, cur);
    }

    cout << ans << endl;

    return 0;
}