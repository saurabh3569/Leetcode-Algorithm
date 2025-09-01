class Solution
{
public:
    int expand(int left, int right, int n, string s)
    {
        int cnt = 0;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }

    int countSubstrings(string s)
    {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += expand(i, i, n, s);
            count += expand(i, i + 1, n, s);
        }

        return count;
    }
};
