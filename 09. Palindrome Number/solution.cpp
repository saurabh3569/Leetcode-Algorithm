class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        int length = s.length();
        int i = 0;
        while (i < length)
        {
            if (s[i] != s[length - 1])
            {
                return false;
            }
            i++;
            length--;
        }
        return true;
    }
};