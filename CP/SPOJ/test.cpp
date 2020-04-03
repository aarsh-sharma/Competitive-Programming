#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        string s;
        cin >> s;
        vector<string> ss;
        int n = s.size();
        char *ptr = &s[0];
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
            {
                reverse(ptr, &s[0] + i);
                ptr = &s[0]+i+1;
            }
            if (i == (n - 1))
            {
                reverse(ptr, &s[0] + i+1);
            }
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}