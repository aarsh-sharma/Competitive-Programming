#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main() {
	string s, r;
	cin >> s >> r;
	int len = s.size(), ori = 0, reel = 0, temp = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '+') ori++;
		else ori--;
		if (r[i] == '+') reel++;
		else if (r[i] == '-') reel--;
		if (r[i] == '?') temp++;
	}
	int diff = abs(ori - reel);
	if (diff > temp) {
		cout << setprecision(11) << 0;
		return 0;
	}
	if (diff == 0) {
		if (temp % 2 != 0) {
			cout << setprecision(11) << 0;
		} else {
			cout << setprecision(11) << ((float)factorial(temp) / (float)(factorial(temp/2) * (float)factorial(temp/2))) / (float)pow(2, temp);
		}
	} else if ((diff % 2 == 0 and temp % 2 != 0) or (diff % 2 != 0 and temp % 2 == 0)) {
        cout << setprecision(11) << 0;
	} else {
            cout << setprecision(11) << ((float)factorial(temp) / (float)(factorial(diff + (temp-diff) / 2) * (float)factorial(temp - diff - (temp-diff) / 2))) / (float)pow(2, temp);
    }

    return 0;
}