class Solution {
public:
    int addDigits(int num) {
        if (num / 10 == 0) {
            return num;
        }

        string numStr = to_string(num);
        num = 0;

        for (int i = 0; i < numStr.length(); i++) {
            num += numStr[i] - '0';
        }

        return addDigits(num);
    }
};