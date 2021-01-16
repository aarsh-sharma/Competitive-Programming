/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl

typedef long long int ll;
#define int ll
typedef pair < ll, ll > pll;
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> score(n+1);
    score[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        score[i].first = a;
        score[i].second = b;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans += max(min(score[i].first, score[i].second) - max(score[i-1].first, score[i-1].second) + 1, 0ll);
        if (score[i-1].first == score[i-1].second) {
            ans--;
        }
    }
    cout << ans;

    return 0;
}