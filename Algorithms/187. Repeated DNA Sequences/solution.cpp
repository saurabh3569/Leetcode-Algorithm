class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> count;
        vector<string> ans;

        for (int i = 0; i + 9 < s.length(); i++)
        {
            string sub = s.substr(i, 10);
            count[sub]++;

            if (count[sub] == 2)
            {
                ans.push_back(sub);
            }
        }

        return ans;
    }
};