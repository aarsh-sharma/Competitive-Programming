// { Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

vector<string> genIp(string &s);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;

        /*generating naively*/
        vector<string> str = genIp(s);
        sort(str.begin(), str.end());
        for (auto &u : str)
        {
            cout << u << "\n";
        }
    }
} // } Driver Code Ends
/*You are required to complete this method*/

bool isValid(string s) {
    vector<string> ii;
    string ts = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '.') {
            ts += s[i];
        } else {
            ii.push_back(ts);
            ts = "";
        }
    }
    ii.push_back(ts);
    for (auto it : ii) {
        if (stoi(it, nullptr, 10) < 0 or stoi(it, nullptr, 10) > 255 or (it[0] == '0' and it.size() > 1)) {
            return false;
        }
    }
    return true;
}

vector<string> genIp(string &s)
{
    int n = s.size();
    vector<string> ans;
    if (n > 12 or n < 4) return ans;
    for (int i = 1; i <= n-3; i++) {
        for (int j = i+1; j <= n-2; j++) {
            for (int k = j+1; k <= n-1; k++) {
                string ts = s.substr(0, i) + '.' + s.substr(i, j-i) + '.' + s.substr(j, k-j) + '.' + s.substr(k, n-k);
                if (isValid(ts)) {
                    ans.push_back(ts);
                }
            }
        }
    }
    return ans;
}
