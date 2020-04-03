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

int countBits(int n)
{
    int count = 0;
    while (n) {
        count++;
        n >>= 1;
    }
    return count;
}

int32_t main() {
    fast_io();

    int t; cin >> t;
    while (t--) {
        int d, m; cin >> d >> m;
        if (d == 1) {
            cout << 1%m << endl;
            continue;
        }
        int bits = countBits(d) - 1;
        vector<vll> a(bits, vll(2));
        f (i, 0, bits) {
            a[i][1] = pow(2, i);
        }
        int ss = 1;
        a[0][0] = d-a[0][1];
        f (i, 1, bits) {
            ss += a[i][1];
            a[i][0] = (a[i-1][0]*(d-ss))%m;
        }
        int ans = 0, ans1 = 0;
        f (i, 0, bits) {
            ans1 = (ans1+a[i][0])%m;
            ans = (ans%m + (a[i][0]*a[i][1])%m)%m;
        }
        // debug(a);
        cout << (ans1+d)%m << endl;
    }

    return 0;
}