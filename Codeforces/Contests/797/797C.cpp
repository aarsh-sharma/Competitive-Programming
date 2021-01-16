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
const ll N = 1e5 + 10;

int32_t main() {
    fast_io();

    vector<vector<int>> pos(26);
    string s; cin >> s;
    int n = sz(s), i = 0;
    f (i, 0, n) {
        pos[s[i]-'a'].pb(i);
    }
    char ch = 'a';
    string t, u;
    int ni;
    while (i < n and ch <= 'z') {
        auto it = lower_bound(pos[ch-'a'].begin(), pos[ch-'a'].end(), i);
        int ti = sz(t);
        for (int j = sz(t)-1; j >= 0; j--) {
            if (t[j] <= ch) {
                u += t[j];
                ti = j;
            } else break;
        }
        string tt;
        f (j, 0, ti) {
            tt += t[j];
        }
        t = tt;
        if (it == pos[ch-'a'].end()) {
            debug("ni mila");
            ch++;
            debug(u, t, ti, sz(t));
            continue;
        }
        int times = pos[ch-'a'].end() - it;
        f (j, 0, times) u += ch;
        int ni = *pos[ch-'a'].rbegin();
        f (j, i, ni) {
            if (s[j] > ch) {
                t += s[j];
            }
        }
        i = ni+1;
        debug(u, t, i, ch);
        ch++;
    }
    f (j, i+1, n) t += s[i];
    debug(t);
    reverse(all(t));
    u += t;
    cout << u;

    return 0;
}