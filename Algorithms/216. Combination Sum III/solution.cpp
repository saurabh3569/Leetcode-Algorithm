class Solution {
public:
    void backtrack(vector<vector<int>>& ans, int i, int sum, vector<int>& temp,
                   int n, int k) {
        if (sum > n || temp.size() > k)
            return;

        if (temp.size() == k && sum == n) {
            ans.push_back(temp);
            return;
        }

        if (i > 9)
            return;

        temp.push_back(i);
        backtrack(ans, i + 1, sum + i, temp, n, k);
        temp.pop_back();

        backtrack(ans, i + 1, sum, temp, n, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, 1, 0, temp, n, k);
        return ans;
    }
};