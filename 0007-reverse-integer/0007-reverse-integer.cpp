class Solution {
public:
    int reverse(int x) {
        int res = 0;
        
        while (x != 0) {
            int pop = x % 10; // Grab the last digit
            x /= 10;          // Remove the last digit from x
            
            // SECURITY CHECK: Guard against overflow BEFORE multiplying by 10
            // If res is already bigger than INT_MAX/10, multiplying by 10 will crash.
            // If it's exactly INT_MAX/10, we can only add up to 7 (since INT_MAX ends in 7).
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            
            // It is safe. Build the reversed number.
            res = (res * 10) + pop;
        }
        
        return res;
    }
};