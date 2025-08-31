class Solution
{
public:
    bool isBalanced(string num)
    {
        int l1 = 0;
        int l2 = 0;

        for (int i = 0; i < num.length(); i += 2)
        {
            l1 += num[i] - '0';
        }

        for (int i = 1; i < num.length(); i += 2)
        {
            l2 += num[i] - '0';
        }

        return l1 == l2;
    }
};
