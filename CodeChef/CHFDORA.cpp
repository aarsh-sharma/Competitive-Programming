#include<bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

int32_t main() {
  fast_io();

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    memset(arr, 0, sizeof(arr));
    int tot = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int chota = min(min(i, n-1-i), min(j, m-1-j));
        map<int, int> m;
        for (int k = 0; k <= chota; k++) {
          if (arr[i][j+k] == arr[i][j-k]) {
            m[k]++;
          } else {
            break;
          }
        }
        for (int k = 0; k <= chota; k++) {
          if (arr[i+k][j] == arr[i-k][j] and m[k] != 0) {
            tot++;
          } else {
            break;
          }
        }
      }
    }
    cout << tot << endl;
  }

  return 0;
}