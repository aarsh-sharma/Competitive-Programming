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
const ll N = 2e5 + 10;

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

#define MAXN 200001

// stores smallest prime factor for every number
int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> divs(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int32_t main() {
    fast_io();

    sieve();
    int n; cin >> n;
    vll a(n);
    f (i, 0, n) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0];
        return 0;
    }

    if (n == 2) {
        cout << lcm(a[0], a[1]);
        return 0;
    }


    // vector<vll> m(N);
    // unordered_map<int, vll> m;
    vector<pll> pows(N);
    vll times(N);
    for (auto ii : a) {
        unordered_map<int, int> tm;
        debug(ii);
        vll div = divs(ii);
        debug(div);
        for (auto el : div) {
            tm[el]++;
        }

        for (auto el : tm) {
            times[el.first]++;
            if (pows[el.first].second == 0) {
                pows[el.first].second = el.second;
            } else {
                if (pows[el.first].first == 0) {
                    if (el.second < pows[el.first].second) {
                        pows[el.first].first = el.second;
                    } else {
                        pows[el.first].first = pows[el.first].second;
                        pows[el.first].second = el.second;
                    }
                } else if (el.second <= pows[el.first].first) {
                    pows[el.first].second = pows[el.first].first;
                    pows[el.first].first = el.second;
                } else if (el.second > pows[el.first].first and el.second < pows[el.first].second) {
                    pows[el.first].second = el.second;
                }
            }
        }
    }
    int ans = 1;
    // debug(pows);
    f (i, 1, N) {
        if (pows[i].first and times[i] >= n-1) {
            debug(pows[i], i, times[i]);
            if (times[i] == n-1) {
                ans *= pow(i, pows[i].first);
            } else {
                ans *= pow(i, pows[i].second);
            }
        }
    }
    // for (auto ii : m) {
    //     debug(ii.first, ii.second);
    //     sort(all(ii.second));
    //     int tt = 0;
    //     if (ii.second.size() == n) {
    //         tt = ii.second[1];
    //     }
    //     if (ii.second.size() == n-1) {
    //         tt = ii.second[0];
    //     }
    //     ans *= pow(ii.first, tt);
    // }
    // for (int i = 1; i < N; i++) {
    //     sort(all(m[i]));
    //     int tt = 0;
    //     if (m[i].size() == n) {
    //         tt = m[i][1];
    //     }
    //     if (m[i].size() == n-1) {
    //         tt = m[i][0];
    //     }
    //     ans *= pow(i, tt);
    // }

    cout << ans << endl;


    return 0;
}