class Solution {
public:
    int own_lower_bound(vector<int> a, int x) {
        int l = 0, h = a.size();
        while (l < h) {
            int mid = (l+h)/2;
            if (a[mid] < x) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return l;
    }

    vector<int> searchRange(vector<int>& a, int target) {
        if (a.size() == 0) return {-1, -1};
        int st = own_lower_bound(a, target);
        if (st == a.size() or a[st] != target) return {-1, -1};
        else {
            int en = own_lower_bound(a, target+1);
            en--;
            return {st, en};
        }
        return {-1, -1};
    }
};