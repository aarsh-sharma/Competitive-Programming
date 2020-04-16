class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 1) return 1;
        if (x == -1) {
            if (n%2) return -1;
            else return 1;
        }
        double ans = x;
        long long nn = 1;
        while (2*nn <= abs(n)) {
            ans *= ans;
            nn *= 2;
        }
        cout << nn << " " << ans;
        for (int i = nn; i < abs(n); i++) ans *= x;
        if (n > 0)
            return ans;
        return 1.0/ans;
    }
};