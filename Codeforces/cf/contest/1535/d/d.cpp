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

vector<int> t;

void build(string s) {
    int n = s.size();
    for (int i = n; i >= 1; i--) {
        debug(s[n-i]);
        if (i > n / 2) {
            if (s[n-i] == '?') t[i] = 2;
            else t[i] = 1;
        } else {
            if (s[n-i] == '?') t[i] = t[i*2] + t[i*2+1];
            else if (s[n-i] == '0') t[i] = t[i*2+1];
            else t[i] = t[i*2];
        }
    }
}

void update(string &s, int id, char ch) {
    int n = s.size();
    s[id-1] = ch;
    id = n - id + 1;
    debug(id);

    while (id >= 1) {
        if (id > n / 2) {
            if (s[n-id] == '?') t[id] = 2;
            else t[id] = 1;
        } else {
            if (s[n-id] == '?') t[id] = t[id*2] + t[id*2+1];
            else if (s[n-id] == '0') t[id] = t[id*2+1];
            else t[id] = t[id*2];
        }
        id /= 2;
    }
}

int32_t main() {
    fast_io();

    int k; cin >> k;
    string s; cin >> s;
    int n = s.size();
    t.resize(n+1);
    build(s);
    debug(t);
    int q; cin >> q;
    while (q--) {
        int p; cin >> p;
        char c; cin >> c;
        update(s, p, c);
        debug(t);
        cout << t[1] << endl;
    }

    return 0;
}