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

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int32_t main() {
    fast_io();

    int t = 1;
    cin >> t;
    while (t--) {
        int a, b, q; cin >> a >> b >> q;
        vll sames;
        int lc = lcm(a, b);
        f (i, 1, lc+1) {
            if ((i%a)%b == (i%b)%a) {
                sames.pb(i);
            }
        }
        // int same = sames.size();
        debug(sames, lc);
        while (q--) {
            int l, r; cin >> l >> r;
            int ool = l, oor = r;
            if (a == b) {
                cout << 0 << " ";
                continue;
            }
            int tl = l%lc;
            l -= tl;
            int tr = r%lc;
            r += lc - tr;
            int same = (r-l)/lc; same *= sames.size();
            debug(l, r, same);
            debug(same, tl, tr);
            auto it = lower_bound(all(sames), tl);
            same -= (it - sames.begin());
            // if (*it != tl) same++;
            same -= (sames.end() - upper_bound(all(sames), tr));
            debug(same);
            if (tl == 0) same++;
            cout << (oor - ool + 1) - same << " ";
        }
        cout << endl;
    }

    return 0;
}