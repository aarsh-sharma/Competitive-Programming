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

vll primes;

void precompute(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.pb(p);
}

int countF(int n) {
    int res = 0;
    for (auto el : primes) {
        while (n % el == 0) {
            n /= el;
            res++;
        }
    }
    if (n > 1) res++;

    return res;
}

int32_t main() {
    fast_io();

    int t; cin >> t;
    precompute(N);
    while (t--) {
        int a, b, k; cin >> a >> b >> k;

        int pa = countF(a), pb = countF(b);
        int same = countF(__gcd(a, b)), diff = pa + pb - 2 * same;

        int diff1 = (__gcd(a, b) != a);
        int diff2 = (__gcd(a, b) != b);

        if (diff1 and diff2) {
            if (k < 2) cout << "NO";
            else {
                if (k <= diff) cout << "YES";
                else {
                    if (k - diff >= 2) k -= diff;
                    else k -= (diff - 1);
                    if (k <= same * 2) cout << "YES";
                    else cout << "NO";
                }
            }
        } else if (!diff1 and !diff2) {
            if (k <= same * 2 and k >= 2) cout << "YES";
            else cout << "NO";
        } else {
            if (k <= diff) cout << "YES";
            else {
                if (k - diff >= 2) k -= diff;
                else k -= (diff - 1);
                if (k <= same * 2) cout << "YES";
                else cout << "NO";

            }
        }

        cout << endl;
        // debug(pa, pb, same, diff);

    }

    return 0;
}