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

// vll offs(61);
// vll ons(61);
// int ans = 0;

// int calcans(vll toffs, vll tons) {
//     int tot = 0;
//     for (int i = 0; i < 61; i++) {
//         if (toffs[i] <= 2 and tons[i]) {
//             tot += pow(2, i);
//         }
//     }

//     return tot;
// }

// string decToBinary(int n)
// {
//     string res;
//     for (int i = 60; i >= 0; i--)
//     {
//         int k = n >> i;
//         if (k & 1)
//             res += '1';
//         else
//             res += '0';
//     }
//     reverse(all(res));

//     return res;
// }

// void calc(int n) {
//     vll toffs = offs;
//     vll tons = ons;

//     string bin = decToBinary(n);

//     for (int i = 0; i < 61; i++) {
//         if (bin[i] != '1') {
//             toffs[i]++;
//         } else {
//             tons[i]++;
//         }
//     }

//     int tans = calcans(toffs, tons);
//     debug(tans, n);

//     if (tans > ans) {
//         ans = tans;
//         offs = toffs;
//         ons = tons;
//     }
// }

int32_t main() {
    fast_io();

    int n; cin >> n;
    vll a(n); f (i, 0, n) cin >> a[i];

    // sort(rall(a));

    // for (int i = 0; i < n; i++) {
    //     calc(a[i]);
    // }

    // cout << ans << endl;

    /*
        FATGI FATGI.....
    */

    if (n == 1) cout << a[0] << endl;
    else if (n == 2) cout << (a[0] | a[1]) << endl;
    else {
        int ans = 0;
        f (i, 0, n) {
            f (j, i+1, n) {
                f (k, j+1, n) {
                    int tans = (a[i] | a[j]) | a[k];
                    ans = max(ans, tans);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
