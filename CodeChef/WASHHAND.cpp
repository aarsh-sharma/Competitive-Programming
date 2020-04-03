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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int d; cin >> d;
        vll right(n, d+1);
        vll left(n, d+1);
        vll days(d); f (i, 0, d) { cin >> days[i]; right[days[i]-2] = i+1; left[days[i]-1] = i+1; }
        vll numRight(n), numLeft(n);
        f (i, 0, n) {
            if (s[i] == '1') {
                numRight[i] = 1;
                numLeft[i] = 1;
            }
        }
        f (i, 1, n) {
            if (numRight[i] == 0 and numRight[i-1]) {
                if (numRight[i-1] < right[i-1]) {
                    numRight[i] = numRight[i-1]+1;
                }
            }
        }
        for (int i = n-2; i >= 0; i--) {
            if (numLeft[i] == 0 and numLeft[i+1]) {
                if (numLeft[i+1] < left[i+1]) {
                    numLeft[i] = numLeft[i+1]+1;
                }
            }
        }
        int ans = 0;
        f (i, 0, n) {
            if (numRight[i] or numLeft[i]) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}