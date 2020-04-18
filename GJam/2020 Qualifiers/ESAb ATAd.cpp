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
// #define endl "\n"
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

    // fflush(stdout);
    int t, b; cin >> t >> b;
    while (t--) {
        vll a(b+1);
        int same = -1, diff = -1;
        f (i, 1, 6) {
            cout << i << endl;
            cin >> a[i];
            cout << b-i+1 << endl;
            cin >> a[b-i+1];
            if (a[i] == a[b-i+1] and same == -1) same = i;
            else if (a[i] != a[b-i+1] and diff == -1) diff = i;
        }
        int l = 6;
        while (true) {
            int moves = 0;
            if (same != -1) {
                cout << same << endl;
                moves++;
                int samebit; cin >> samebit;
                if (samebit != a[same]) {
                    f (i, 1, b+1) {
                        a[i] = !a[i];
                    } 
                }
            }
            if (diff != -1) {
                cout << diff << endl;
                moves++;
                int diffbit; cin >> diffbit;
                if (diffbit != a[diff]) {
                    f (i, 1, b/2+1) {
                        swap(a[i], a[b-i+1]);
                    }
                }
            }
            if (moves == 1) {
                cout << 1 << endl;
                int temp; cin >> temp;
                moves++;
            }
            int tl = l;
            f (i, tl, min(b/2+1, tl+4)) {
                cout << i << endl;
                cin >> a[i];
                cout << b-i+1 << endl;
                cin >> a[b-i+1];
                if (a[i] == a[b-i+1] and same == -1) same = i;
                else if (a[i] != a[b-i+1] and diff == -1) diff = i;
                l++;
                moves += 2;
            }
            if (l == b/2+1 and moves != 10) {
                break;
            }
        }

        f (i, 1, b+1) {
            cout << a[i];
        }
        cout << endl;
        char result; cin >> result;
        if (result == 'N') break;
    }

    return 0;
}