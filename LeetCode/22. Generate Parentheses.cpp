class Solution {
    bool balanced(string s) {
        int curr = 0;
        for (auto c : s) {
            if (c == '(') {
                curr++;
            } else {
                curr--;
            }
            if (curr < 0) return false;
        }
        return true;
    }
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        for (int i = 0; i < n; i++) s += '(';
        for (int i = 0; i < n; i++) s += ')';
        vector<string> ans;
        do {
            if (balanced(s)) {
                ans.push_back(s);
            }
        } while (next_permutation(s.begin(), s.end()));
        return ans;
    }
};