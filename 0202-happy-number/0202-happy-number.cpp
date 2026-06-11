class Solution {
private:

    int getNext(int n){
        int total_sum = 0;
        while( n!= 0){
            int last = n % 10;
            n = n / 10;
            total_sum += (last * last);
        }
        return total_sum;
    }
public: // The Hash Set Implementation
    bool isHappy(int n) {
        // Now using fast and slow pointer technique 
        int slow = n;
        int fast = getNext(n);

        while(fast != 1 && slow!=fast){
            slow = getNext(slow);
            fast = getNext(getNext(fast));

        }

        return fast == 1;
    }
};
