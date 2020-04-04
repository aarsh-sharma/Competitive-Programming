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

int twoOverlap(pll one, pll two) {
    if (one.S > two.F) {
        return true;
    }
    return false;
}

int threeOverlap(pll one, pll two, pll three) {
    if (one.S > two.F and one.S > three.F and two.S > three.F) {
        return true;
    }
    return false;
}

int32_t main() {
    fast_io();

    int t; cin >> t;
    f (_, 1, t+1) {
        int n; cin >> n;
        vector<pair<pll, int>> ti(n);
        f (i, 0, n) { ti[i].S = i; cin >> ti[i].F.F >> ti[i].F.S; }
        sort(all(ti));
        string ans = "C";
        f (i, 1, n) {
            if (twoOverlap(ti[i-1].F, ti[i].F)) {
                if (ans.back() == 'C') ans += 'J';
                else ans += 'C';
            } else {
                ans += ans.back();
            }
        }
        int flag = 0;
        f (i, 0, n) {
            f (j, i+2, n) {
                if (threeOverlap(ti[i].F, ti[j-1].F, ti[j].F)) {
                    flag = 1;
                    break;
                }
            }
        }
        cout << "Case #" << _ << ": ";
        if (flag) cout << "IMPOSSIBLE" << endl;
        else {
            vector<char> aa(n);
            f (i, 0, n) {
                aa[ti[i].S] = ans[i];
            }
            for (auto it : aa) cout << it;
            cout << endl;
        }
    }

    return 0;
}