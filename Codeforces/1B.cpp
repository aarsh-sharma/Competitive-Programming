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

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int type = 0, n = sz(s);
        vll partition;
        f (i, 0, n-1) {
            if ((s[i] <= 'Z' and s[i] >= 'A') and (s[i+1] <= '9' and s[i+1] >= '0')) {
                type++;
                partition.pb(i);
            }
        }
        if (type == 1) {
            reverse(s.begin(), s.begin() + partition[0]+1);
            debug(s);
            int col = 0, times = 1;
            f (i, 0, partition[0]+1) {
                debug(times, s[i]);
                col += times * (s[i] - 'A' + 1);
                times *= 26;
            }
            cout << "R";
            f (i, partition[0]+1, n) cout << s[i];
            cout << "C" << col << endl;
            
        } else {
            string row, col;
            f (i, partition[0]+1, partition[1]) {
                row += s[i];
            }
            f (i, partition[1]+1, n) col += s[i];
            int c = stoll(col);
            col = "";
            debug(c);
            while (c) {
                int rem = c%26;
                debug(rem);
                if (rem == 0) rem = 26;
                col += 'A' + rem - 1;
                c -= rem;
                c /= 26;
            }
            reverse(all(col));
            cout << col << row << endl;
        }
    }

    return 0;
}