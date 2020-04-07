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
const ll N = 1e5 + 10;

int32_t main() {
    fast_io();

    int scorea = 0, scoreb = 0;
    vll wa, wb;
    int n; cin >> n;
    int last = 0;
    f (i, 0, n) {
        int score; cin >> score;
        if (score > 0) {
            scorea += score;
            wa.pb(score);
        } else {
            scoreb -= score;
            wb.pb(-1*score);
        }
        if (i == n-1) {
            if (score > 0) last = 1;
            else last = 2;
        }
    }
    debug(scorea, scoreb);
    debug(wa);
    debug(wb);
    if (scorea > scoreb) {
        cout << "first" << endl;
    } else if (scoreb > scorea) {
        cout << "second" << endl;
    } else {
        int winner = 0;
        f (i, 0, min(wa.size(), wb.size())) {
            if (wa[i] < wb[i]) {
                winner = 2;
                break;
            } else if (wa[i] > wb[i]) {
                winner = 1;
                break;
            }
        }
        if (winner == 1) cout << "first" << endl;
        else if (winner == 2) cout << "second" << endl;
        else if (last == 1) cout << "first" << endl;
        else cout << "second" << endl;
    }

    return 0;
}