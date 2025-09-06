class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        vector<int> ans;

        for (char i : p)
        {
            m1[i]++;
        }

        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            char curr = s[right];
            if (m1.count(curr))
            {
                m2[curr]++;
            }

            if (m1 == m2)
            {
                ans.push_back(left);
                m2[s[left]]--;
                left++;
            }
            else if (!m1.count(curr))
            {
                m2.clear();
                left = right + 1;
            }
            else if (m2[curr] > m1[curr])
            {
                while (m2[curr] != m1[curr])
                {
                    m2[s[left]]--;
                    left++;
                }
            }
        }

        return ans;
    }
};