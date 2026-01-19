class Solution {
public:
    string recurs(string ans, int n) {
        if (n == 1) {
            return ans;
        }

        string newStr = "";
        int cnt = 1;

        for (int i = 0; i + 1 < ans.length(); i++) {
            if (ans[i] == ans[i + 1]) {
                cnt++;
            } else {
                newStr += to_string(cnt) + ans[i];
                cnt = 1;
            }
        }

        // last group
        newStr += to_string(cnt) + ans.back();

        return recurs(newStr, n - 1);
    }

    string countAndSay(int n) { return recurs("1", n); }
};
