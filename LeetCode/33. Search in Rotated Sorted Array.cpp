class Solution {
public:
    int findMax(vector<int> a) {
        int l(0), r(a.size()-1);
        int maxm = a[0];
        while (l<r) {
            int mid = (l+r)/2;
            if (l == r-1) {
                if (a[l] > a[r]) return l;
                else return r;
            }
            if (a[mid] < maxm) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }
    
    int search(vector<int>& a, int target) {
        if (a.size() == 0) return -1;
        int pivot = findMax(a);
        if (target > a[pivot]) {
            return -1;
        } else if (target >= a[0]) {
            auto it = lower_bound(a.begin(), a.begin()+pivot, target);
            if (*it != target) return -1;
            return (it - a.begin());
        } else {
            auto it = lower_bound(a.begin()+pivot+1, a.end(), target);
            if (it == a.end() or *it != target) return -1;
            return (it - a.begin());
        }
        return -1;
    }
};