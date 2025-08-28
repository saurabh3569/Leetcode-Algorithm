class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        int len = 0;

        unordered_map<char, int> m;
        int j = 0;

        for (int i = 0; i < s.length(); i++)
        {
            len++;
            m[s[i]]++;

            if (m[s[i]] > 1)
            {
                ans = max(ans, len - 1);
                while (m[s[i]] > 1)
                {
                    m[s[j]]--;
                    if (m[s[j]] == 0)
                    {
                        m.erase(s[j]);
                    }
                    j++;
                    len--;
                }
            }
        }

        return max(ans, len);
    }
};