#include <bits/stdc++.h>
using namespace std;
typedef long long num;
typedef vector<num> poly;
const num p = 663224321;

num pm(num a, num n = p - 2, num m = p)
{
    num r = 1;
    for (; n; n >>= 1, a = a * a % m)
        if (n & 1)
            r = r * a % m;
    return r;
}

struct NTT
{
    static const int g = 3;
    void go(num *a, size_t n)
    {
        size_t l, b, i, s;
        num d = pm(g, (p - 1) / n, p), w, t;
        for (b = n >> 1, l = n; b; b >>= 1, l >>= 1, d = d * d % p)
            for (w = 1, s = 0; s < b; ++s, w = w * d % p)
                for (i = s; i < n; i += l)
                {
                    a[i | b] = (a[i] - (t = a[i | b])) * w % p;
                    a[i] = (a[i] + t) % p;
                }
    }
    void back(num *a, size_t n)
    {
        size_t l, b, i, s;
        num d = pm(n, p - 2, p), w, t;
        for (i = 0; i < n; ++i)
            a[i] = a[i] * d % p;
        for (b = 1, l = 2; b < n; b <<= 1, l <<= 1)
            for (d = pm(g, p - 1 - (p - 1) / l, p), w = 1, s = 0; s < b; ++s, w = w * d % p)
                for (i = s; i < n; i += l)
                {
                    t = a[i | b] * w;
                    a[i | b] = (a[i] - t) % p;
                    a[i] = (a[i] + t) % p;
                }
    }
} ntt;

void sqr(poly &a)
{
    int n = 1, m = a.size();
    for (; n < a.size() * 2 - 1; n <<= 1)
        ;
    a.resize(n, 0);
    ntt.go(&a[0], n);
    for (int i = 0; i < n; ++i)
        a[i] = a[i] * a[i] % p;
    ntt.back(&a[0], n);
    a.resize(m * 2 - 1);
}
poly mul(poly a, poly b)
{
    int n = 1, l = a.size() + b.size() - 1;
    for (; n < l; n <<= 1)
        ;
    a.resize(n, 0);
    b.resize(n, 0);
    ntt.go(&a[0], n);
    ntt.go(&b[0], n);
    for (int i = 0; i < n; ++i)
        a[i] = a[i] * b[i] % p;
    ntt.back(&a[0], n);
    a.resize(l);
    return a;
}

poly invM(poly f, int m)
{
    poly g;
    int n = 1;
    g.push_back(pm(f[0]));
    for (; n < m;)
    {
        n <<= 1;
        poly t = g;
        sqr(t);
        for (auto &x : g)
            x = (x << 1) % p;
        t = mul(poly(f.begin(), min(f.begin() + n, f.end())), t);
        g.resize(n, 0);
        for (int i = 0; i < n && i < t.size(); ++i)
            g[i] = (g[i] - t[i]) % p;
    }
    return poly(g.begin(), g.begin() + m);
}

poly h, g, invG, f;

// comb
#define MAX 300005
#define MOD 663224321
#define ll long long
ll fact[MAX], inverse[MAX], fact_inverse[MAX];

void precalc()
{
    fact[0] = 1;

    inverse[0] = 1;
    inverse[1] = 1;

    fact_inverse[0] = 1;
    fact_inverse[1] = 1;

    for (ll i = 1; i < MAX; i++)
        fact[i] = (i * fact[i - 1]) % MOD;

    for (ll i = 2; i < MAX; i++)
    {
        inverse[i] = (MOD - ((MOD / i) * inverse[MOD % i]) % MOD) % MOD;
        fact_inverse[i] = (inverse[i] * fact_inverse[i - 1]) % MOD;
    }
}
// ENDS

int main()
{
    precalc();

    int lim = 5 + (1e5);
    h.resize(lim);
    g.resize(lim);
    for (int i = 0; i < lim; i++)
    {
        h[i] = pm(2, (i * 1LL * (i - 1)) / 2);
        h[i] *= fact_inverse[i];
        h[i] %= p;

        g[i] = h[i];
        h[i] = i * h[i] % p;
    }

    invG = invM(g, lim);
    f = mul(h, invG);

    for (int i = 1; i < f.size(); i++)
    {
        f[i] *= fact[i - 1];
        f[i] %= p;
        if (f[i] < 0)
            f[i] += p;
    }

#define sd(x) scanf("%d", &x)
    int q;
    sd(q);
    while (q--)
    {
        int n;
        sd(n);
        printf("%lld\n", f[n]);
    }
}
