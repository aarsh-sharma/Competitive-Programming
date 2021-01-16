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
// #define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const ll N = 1e5 + 10;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int32_t main() {
    fast_io();

    /*
        Machod TLE kyu aara hai

        Don't fucking use long long ever......................
    */

    int n, q; cin >> n >> q;
    FenwickTree BIT(n+1);
    for (int i = 0; i < n; i++) {
        int tt; cin >> tt;
        BIT.add(tt, 1);
    }

    while (q--) {
        int k; cin >> k;
        if (k > 0) {
            BIT.add(k, 1);
        } else {
            k *= -1;
            int l = 1, r = n, ta = INT_MAX;
            while (r-l > 2) { // khufia binary search
                int mid = (l+r)/2;
                if (BIT.sum(mid) >= k) {
                    ta = min(ta, mid);
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            for (int i = l; i <= r; i++) {
                if (BIT.sum(i) >= k) {
                    ta = min(ta, i);
                }
            }
            BIT.add(ta, -1);
        }

    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (BIT.bit[i]) { // khas khayal
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}