class Solution {
public:
    void reverseString(vector<char>& s) {
        int vecSize = s.size() - 1;

        for (int i = 0; i <= vecSize / 2; i++) {
            char tmp = s[i];
            s[i] = s[vecSize - i];
            s[vecSize - i] = tmp;
        }
    }
};
