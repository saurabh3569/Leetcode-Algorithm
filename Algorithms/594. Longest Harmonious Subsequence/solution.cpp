class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int ans = 0;

        for (int x : nums)
        {
            m[x]++;
        }

        for (auto &p : m)
        {
            int x = p.first;
            if (m.find(x + 1) != m.end())
            {
                ans = max(ans, m[x] + m[x + 1]);
            }
        }

        return ans;
    }
};