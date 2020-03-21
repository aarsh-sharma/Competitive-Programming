class Solution
{
public:
    string intToRoman(int num)
    {
        string ans = "";
        for (int i = 0; i < num / 1000; i++)
        {
            ans += 'M';
        }
        num %= 1000;
        if (num / 100 == 9)
            ans += "CM";
        else if (num / 100 == 4)
            ans += "CD";
        else
        {
            for (int i = 0; i < num / 500; i++)
            {
                ans += 'D';
            }
            num %= 500;
            for (int i = 0; i < num / 100; i++)
            {
                ans += 'C';
            }
        }
        num %= 100;
        if (num / 10 == 9)
            ans += "XC";
        else if (num / 10 == 4)
            ans += "XL";
        else
        {
            for (int i = 0; i < num / 50; i++)
            {
                ans += 'L';
            }
            num %= 50;
            for (int i = 0; i < num / 10; i++)
            {
                ans += 'X';
            }
        }
        num %= 10;
        if (num == 9)
            ans += "IX";
        else if (num == 4)
            ans += "IV";
        else
        {
            for (int i = 0; i < num / 5; i++)
            {
                ans += 'V';
            }
            num %= 5;
            for (int i = 0; i < num; i++)
            {
                ans += 'I';
            }
        }
        return ans;
    }
};