/*aarsh01rsh@gmair.com
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
    string l, r; cin >> l >> r;
    vector<int> lv[128], rv[128];
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        lv[l[i]].push_back(i+1);
        rv[r[i]].push_back(i+1);
    }
    for (int i = 0; i < 128; i++) {
        if (i == '?') {
            continue;
        }
        while (!lv[i].empty() and !rv[i].empty()) {
            ans.push_back({*lv[i].rbegin(), *rv[i].rbegin()});
            lv[i].pop_back();
            rv[i].pop_back();
        }
    }
    for (int i = 0; i < 128; i++) {
        if (lv['?'].empty()) {
            break;
        }
        if (i == '?') continue;
        while(!rv[i].empty() and !lv['?'].empty()) {
            ans.push_back({*lv['?'].rbegin(), *rv[i].rbegin()});
            lv['?'].pop_back();
            rv[i].pop_back();
        }
    }
    for (int i = 0; i < 128; i++) {
        if (rv['?'].empty()) {
            break;
        }
        if (i == '?') continue;
        while(!lv[i].empty() and !rv['?'].empty()) {
            ans.push_back({*lv[i].rbegin(), *rv['?'].rbegin()});
            rv['?'].pop_back();
            lv[i].pop_back();
        }
    }
    while (!lv['?'].empty() and !rv['?'].empty()) {
        ans.push_back({*lv['?'].rbegin(), *rv['?'].rbegin()});
        lv['?'].pop_back();
        rv['?'].pop_back();
    }
    cout << ans.size() << "\n";
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << it->first << ' ' << it->second << "\n";
    }

        return 0;
}