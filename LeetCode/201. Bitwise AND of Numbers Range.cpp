class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        bitset<33> b(m);
        string s = b.to_string();
        reverse(s.begin(), s.end());
        long long ans = 0;
        long long diff = n-m;
        cout << s << endl;
        for (int i = 0; i < 33; i++) {
            long long num = pow(2, i);
            if (s[i] == '1') {
                long long rem = num - m % num;
                cout << rem << endl;
                if (diff < rem) {
                    ans += num;
                }
            }
        }
        return ans;
    }
};