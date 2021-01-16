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
const ll N = 1e6 + 10;

vector<pair<int, pll>> tree(4*N); // pair<ans<open, close>>
string s;

void build(int idx, int l, int r) {
    if (r-l < 2) {
        if (s[l] == '(') {
            tree[idx].S.F = 1;
        } else {
            tree[idx].S.S = 1;
        }
        return;
    }
    int mid = (l+r)/2;
    build(2*idx, l, mid);
    build(2*idx+1, mid, r);
    int temp = min(tree[2*idx].S.F, tree[2*idx + 1].S.S);
    tree[idx].F = tree[2*idx].F + tree[2*idx + 1].F + temp;
    tree[idx].S.F = tree[2*idx].S.F + tree[2*idx + 1].S.F - temp;
    tree[idx].S.S = tree[2*idx].S.S + tree[2*idx + 1].S.S - temp;
}

pair<int, pll> query(int x, int y, int idx, int l, int r) {
    if (l >= y or x >= r) return {0, {0, 0}};
    if (x <= l and y >= r) return tree[idx];
    int mid = (l+r)/2;
    pair<int, pll> a = query(x, y, 2*idx, l, mid);
    pair<int, pll> b = query(x, y, 2*idx + 1, mid, r);
    int temp = min(a.S.F, b.S.S);
    return {a.F+b.F+temp, {a.S.F+b.S.F-temp, a.S.S+b.S.S-temp}};
}

int32_t main() {
    fast_io();

    cin >> s;
    int n = s.size();
    build(1, 0, n);
    debug("build done");
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        pair<int, pll> ans = query(l-1, r, 1, 0, n);
        cout << 2*ans.F << endl;
    }

    return 0;
}