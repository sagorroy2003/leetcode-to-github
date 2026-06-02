
class Solution {
public:
    int scoreOfParentheses(std::string s) {
        int total_score = 0;
        int depth = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                // Going one level deeper
                depth++;
            } else { // s[i] must be ')'
                // Coming out of a level
                depth--;
                
                // Check if this is a base "()" pair
                if (s[i-1] == '(') {
                    // This is a "()" pair at 'depth'
                    // Its score is 2^depth (or 1 << depth)
                    total_score += (1 << depth);
                }
            }
        }
        
        return total_score;
    }
};