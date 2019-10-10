class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector <char> row[numRows];
        int move = 1, idx = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            row[idx].push_back(s[i]);
            idx += move;
            if (idx == numRows - 1) {
                move = -1;
            } else if (idx == 0) {
                move = 1;
            }
        }
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            for (auto &it : row[i]) {
                // cout << it;
                ans += it;
                // ans.push_back(it);
                // ans.append(1, it);
            }
        }
        return ans;
    }
};