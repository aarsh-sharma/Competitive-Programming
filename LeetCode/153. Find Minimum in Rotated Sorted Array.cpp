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
    int findMin(vector<int>& a) {
        int pivot = findMax(a);
        if (pivot == a.size() - 1) return a[0];
        return a[pivot+1];
    }
};