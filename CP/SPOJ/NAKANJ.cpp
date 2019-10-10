// aarsh01rsh@gmail.com
// Aarsh Sharma
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

bool check(pair<int, int> p){
	return ((p.first >= 1 and p.first <= 8) and (p.second >= 1 and p.second <= 8));
}

int32_t main()
{
	fast_io();

	int t; cin >> t;
	while (t--) {
		string str, fin; cin >> str >> fin;
		pair<int, int> s = {str[0] - 'a' + 1, str[1] - '0'};
		pair<int, int> f = {fin[0] - 'a' + 1, fin[1] - '0'};
		queue<pair<int, int>> q;
		pair<int, int> p;
		bool vis[9][9];
		int moves[9][9];
		memset(vis, 0, sizeof vis);
		memset(moves, 0, sizeof moves);
		q.push(s);
		p = q.front();
		while(p != f) {
			pair<int, int> temp;
			if (!vis[p.first][p.second]) {
				temp = {p.first + 2, p.second + 1};
				if (check(temp)) {
					moves[temp.first][temp.second] = moves[p.first][p.second] + 1;
					q.push(temp);
				}
				temp = {p.first + 2, p.second - 1};
				if (check(temp)) {
					moves[temp.first][temp.second] = moves[p.first][p.second] + 1;
					q.push(temp);
				}
				temp = {p.first + 1, p.second + 2};
				if (check(temp)) {
					moves[temp.first][temp.second] = moves[p.first][p.second] + 1;
					q.push(temp);
				}
				temp = {p.first - 1, p.second + 2};
				if (check(temp)) {
					moves[temp.first][temp.second] = moves[p.first][p.second] + 1;
					q.push(temp);
				}
				temp = {p.first - 2, p.second + 1};
				if (check(temp)) {
					moves[temp.first][temp.second] = moves[p.first][p.second] + 1;
					q.push(temp);
				}
				temp = {p.first - 2, p.second - 1};
				if (check(temp)) {
					moves[temp.first][temp.second] = moves[p.first][p.second] + 1;
					q.push(temp);
				}
				temp = {p.first + 1, p.second - 2};
				if (check(temp)) {
					moves[temp.first][temp.second] = moves[p.first][p.second] + 1;
					q.push(temp);
				}
				temp = {p.first - 1, p.second - 2};
				if (check(temp)) {
					moves[temp.first][temp.second] = moves[p.first][p.second] + 1;
					q.push(temp);
				}
			}
			vis[p.first][p.second] = true;
			q.pop();
			p = q.front();
		}
	cout << moves[p.first][p.second] << "\n";
	}

	return 0;
}