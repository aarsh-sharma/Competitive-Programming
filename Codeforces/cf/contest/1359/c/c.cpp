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

int h, c, t;
long double get(int cur)
{
    return (abs(t - (1.0 * (1ll * cur * (h + c) + h)) / (1 + cur * 2)));
}

int32_t main() {
    fast_io();

    int tt; cin >> tt;
    while (tt--) {
        cin >> h >> c >> t;
        double avg = (h+c) / 2.0;
        if (t >= h) {
            cout << 1 << endl; continue;
        }
        if (t <= avg) {
            cout << 2 << endl; continue;
        }

        /*
            TOO STRESSED TO DEBUG THIS (´༎ຶ ͜ʖ ༎ຶ `)♡
            WILL JUST GO WITH THE EDITORIAL
        */

        // int l = 0, r = 1e9;
        // pair<int, int> ans = {1e7, -1};
        // while (r - l > 3) {
        //     // int mid = (l+r) / 2;
        //     int mid = (l + r) >> 1;
        //     if (mid%2) {
        //         int avg = (h * (mid + 1) + c * (mid));
        //         // debug(mid, l, r, avg, abs(avg-t*mid));
        //         if (abs(avg - t * (2 * mid + 1)) < ans.first) {
        //             ans = {abs(avg - t * (2 * mid + 1)), mid};
        //         }
        //         if (avg < t * (2 * mid + 1)) {
        //             r = mid;
        //         } else {
        //             l = mid;
        //         }
        //     } else {
        //         r--;
        //     }
        // }
        // // debug(l, r);
        // for (int i = l; i <= r; i++) {
        //     if (i%2) {
        //         int avg = (h * (i + 1) + c * (i));
        //         // debug(i, avg, abs(avg-t*i));
        //         if (abs(avg - t * (2 * i + 1)) < ans.first) {
        //             ans = {abs(avg - t * (2 * i + 1)), i};
        //         }
        //     }
        // }

        // debug(2 * ans.second + 1);

        // cout << ((get(ans.second) > get(ans.second + 1)) ? (3 + ans.second * 2) : (1 + ans.second * 2)) << "\n";

        int a = h - t;
        int b = 2 * t - c - h;
        int k = 2 * (a / b) + 1;

        int val1 = abs(k / 2 * 1ll * c + (k + 1) / 2 * 1ll * h - t * 1ll * k);
        int val2 = abs((k + 2) / 2 * 1ll * c + (k + 3) / 2 * 1ll * h - t * 1ll * (k + 2));

        cout << (val1 * (k + 2) <= val2 * k ? k : k + 2) << endl;
    }

    return 0;
}
