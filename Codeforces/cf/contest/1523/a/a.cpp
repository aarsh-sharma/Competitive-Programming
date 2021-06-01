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

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;

        if (*max_element(all(s)) == '0') {
            cout << s << endl;
            continue;
        }

        vll l(n), r(n);
        int zl = 0, zr = 0;
        f (i, 0, n) {
            if (s[i] == '1') {
                l[i] = zl;
                zl = 0;
            } else zl++;

            if (s[n-1-i] == '1') {
                r[n-1-i] = zr;
                zr = 0;
            } else zr++;
        }

        debug(zl, l);
        debug(zr, r);

        debug(s);

        int cl = 0, cr = 0;
        f (i, 0, n) {
            if (r[i]) cr = min(r[i] / 2, m);
            if (s[i] == '0' and cr) {
                s[i] = '1';
                cr--;
            }

            if (l[n-1-i]) cl = min(l[n-1-i] / 2, m);
            if (s[n-1-i] == '0' and cl) {
                s[n-1-i] = '1';
                cl--;
            }
        }

        for (int i = zr-1; i >= max(0ll, zr-m); --i) s[i] = '1';
        for (int i = n-zl; i <= min(n-1, n-zl+m-1); i++) s[i] = '1';

        cout << s << endl;
    }


    return 0;
}