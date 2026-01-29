class Solution {
public:
    void backtrack(string s, vector<string>& ans, string curr, int i) {

        int dots = 0;

        for (int i = 0; i + 1 < curr.size(); i++) {
            if (curr[i] == '.')
                dots++;
        }

        if (dots > 3)
            return;

        if (i == s.length()) {
            if (dots != 3)
                return;

            string newStr = curr.substr(0, curr.length() - 1);
            ans.push_back(newStr);
            return;
        }

        int sum = (s[i] - '0');

        if (sum > 255) {
            return;
        }

        string newCurr = curr + s[i] + ".";

        backtrack(s, ans, newCurr, i + 1);

        if (s[i] == '0') {
            return;
        }

        if (i + 1 < s.length()) {
            int sum = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if (sum > 255) {
                return;
            }

            string newCurr = curr + s[i] + s[i + 1] + ".";
            backtrack(s, ans, newCurr, i + 2);
        }

        if (i + 2 < s.length()) {
            int sum =
                (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0');

            if (sum > 255) {
                return;
            }

            string newCurr = curr + s[i] + s[i + 1] + s[i + 2] + ".";
            backtrack(s, ans, newCurr, i + 3);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        backtrack(s, ans, "", 0);
        return ans;
    }
};