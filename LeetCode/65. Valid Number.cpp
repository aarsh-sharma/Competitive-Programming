class Solution {
public:
    bool checkSign(string s) { // checks weather the string has sign
        int sign = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '-' or ch == '+') {
                sign += i;
            }
        }
        if (sign) return false;
        return true;
    }
    
    string removeSign(string s) { // returns string with removed sign if present
        if (s[0] == '-' or s[0] == '+') {
            s = s.substr(1);
        }
        return s;
    }

    bool checkInteger(string s) { // checks whether given string is integer
        for (auto ch : s) {
            if (ch < '0' or ch > '9') return false;
        }
        return true;
    }

    pair<int, int> findDecimal(string s) { // return position of decimal and number of decimals
        pair<int, int> res;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '.') {
                res.second++;
                res.first = i;
            }
        }
        return res;
    }

    string strip(string s)  { // removes extra spaces from front and end of string
        int n = s.size();
        int st = 0, en = n-1;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                st = i+1;
            } else break;
        }
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == ' ') {
                en = i-1;
            } else break;
        }
        s = s.substr(st, en-st+1);
        return s;
    }

    bool isNumber(string s) {
        s = strip(s);
        int exp = 0, n = s.size();
        
        // return false if any non valid character
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if ((ch < '0' or ch > '9') and (ch != '.' and ch != 'e' and ch != '-' and ch != '+')) {
                return false;
            }
            if (ch == 'e') {
                if (exp or i == 0) return false;
                exp = i;
            }
        }

        if (exp) { // if exponential form
            
            if (exp == s.size()-1) return false;
            string num = s.substr(0, exp);
            string power = s.substr(exp+1);
            
            // check num
            if (!checkSign(num)) return false;
            num = removeSign(num);
            if (num.size() == 0) return false;
            pair<int, int> dec = findDecimal(num);
            if (dec.second > 1) return false;
            if (dec.second == 1) {
                string integer = num.substr(0, dec.first);
                string fraction = num.substr(dec.first+1);
                if (fraction.size() == 0 and integer.size() == 0 or !checkInteger(integer) or !checkInteger(fraction)) return false;
            } else {
                if (!checkInteger(num)) return false;
            }
            
            // check power
            if (!checkSign(power)) return false;
            power = removeSign(power);
            dec = findDecimal(power);
            if (dec.second or !checkInteger(power) or power.size() == 0) return false;
            
        } else { // if non exponential form
            
            if (!checkSign(s)) return false;
            s = removeSign(s);
            pair<int, int> dec = findDecimal(s);
            
            if (dec.second > 1) return false;
            
            if (dec.second == 1) {
                string integer = s.substr(0, dec.first);
                string fraction = s.substr(dec.first+1);
                if (!checkInteger(integer) or !checkInteger(fraction) or fraction.size() == 0 and integer.size() == 0) return false;
            } else {
                if (!checkInteger(s) or s.size() == 0) return false;
            }
        }
        return true;
    }
};