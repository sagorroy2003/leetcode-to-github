class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.size() - 1; // Explicit index pointer starting at the very end

        // Phase 1: Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Phase 2: Count characters until we hit the next space (or start of string)
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }

        return len;
    }
};