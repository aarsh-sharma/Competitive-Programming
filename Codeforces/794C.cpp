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

    string a, b; cin >> a >> b;
    sort(all(a));
    sort(rall(b));
    int n = a.size();
    string s(n, '#');
    debug(s);
    int asz = (n%2) ? n/2+1 : n/2;
    a = a.substr(0, asz);
    b = b.substr(0, n/2);
    int ast = 0, aen = a.size()-1;
    int bst = 0, ben = b.size()-1;
    int sst = 0, sen = n-1;
    f (i, 0, n) {
        if (i % 2) {
            if (a[ast] < b[bst]) {
                s[sst] = b[bst];
                sst++; bst++;
            } else {
                s[sen] = b[ben];
                sen--; ben--;
            }
        } else {
            if (a[ast] < b[bst]) {
                s[sst] = a[ast];
                sst++; ast++;
            } else {
                s[sen] = a[aen];
                sen--; aen--;
            }
        }
    }
    cout << s << endl;

    return 0;
}