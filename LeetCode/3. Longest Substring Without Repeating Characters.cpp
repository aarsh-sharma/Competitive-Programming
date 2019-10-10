class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int ptr1 = 0, ptr2 = 1, len = s.size(), ans = 1;
        while (ptr2 < len) {
            int temp = ptr1;
            while (temp < ptr2) {
                if (s[temp] == s[ptr2]) {
                    ptr1 = temp + 1;
                }
                temp++;
            }
            ptr2++;
            if (ptr2 - ptr1 > ans) {
                ans = ptr2 - ptr1;
            }
        }
        return ans;
    }
};