class Solution {
public:
    int myAtoi(string str) {
        long long int ans = 0;
        int sign = 1, n = str.size(), flag = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] <= '9' and str[i] >= '0') {
                if (i != 0 and str[i-1] == '-') {
                    ans *= -1;
                }
                ans *= 10;
                ans += str[i] - '0';
                flag = 1;
                if (ans*sign > INT_MAX) {
                    ans = INT_MAX;
                    break;
                } else if (ans*sign < INT_MIN) {
                    ans = INT_MIN;
                    break;
                }
            } else if (str[i] == '-' and flag == 0) {
                if (i != 0 and (str[i-1] == '-' or str[i-1] == '+')) break;
                sign = -1;
                flag = 1;
            } else if (str[i] == '+' and flag == 0) {
                if (i != 0 and (str[i-1] == '-' or str[i-1] == '+')) break;
                sign = 1;
                flag = 1;
            }  else if (str[i] == ' ' and flag == 0) {
                continue;
            } else {
                break;
            }
        }
        ans = ans * sign;
        return ans;
    }
};