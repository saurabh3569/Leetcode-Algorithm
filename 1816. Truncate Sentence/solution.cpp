class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        string ans;
        string temp;
        int i = 0;

        while (k > 0 && i < s.length())
        {
            if (s[i] != ' ')
            {
                temp += s[i];
            }
            else
            {
                k--;
                ans += temp;
                ans += ' ';
                temp = "";
            }
            i++;
        }

        if (!temp.empty())
        {
            ans += temp;
        }

        if (!ans.empty() && ans.back() == ' ')
        {
            ans.pop_back();
        }

        return ans;
    }
};
