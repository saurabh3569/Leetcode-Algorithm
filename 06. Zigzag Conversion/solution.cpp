class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || s.length() <= numRows)
            return s;

        unordered_map<int, vector<char>> m;
        string ans;
        int count = 0;
        bool isInc = true;

        for (int i = 0; i < s.length(); i++)
        {
            if (isInc)
            {
                count++;
            }
            else
            {
                count--;
            }

            int idx = count - 1;
            m[idx].push_back(s[i]);

            if (count == 1)
                isInc = true;
            else if (count == numRows)
                isInc = false;
        }

        for (int i = 0; i < numRows; i++)
        {
            for (char c : m[i])
            {
                ans.push_back(c);
            }
        }

        return ans;
    }
};