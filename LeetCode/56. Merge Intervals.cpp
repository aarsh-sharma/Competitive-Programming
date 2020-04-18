class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0], en = intervals[0][1];
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] <= en) {
                en = max(en, intervals[i][1]);
                st = min(st, intervals[i][0]);
            } else {
                res.push_back({st, en});
                st = intervals[i][0];
                en = intervals[i][1];
            }
        }
        res.push_back({st, en});
        return res;
    }
};