class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(),stones.end());

        int tem1, tem2;

        while(!maxHeap.empty()){
            tem1 = maxHeap.top();
            maxHeap.pop();
            if(!maxHeap.empty()){
                tem2 = maxHeap.top();
                maxHeap.pop();  
            }
            else {
                // jodi empty hoi
                break;
            }
            // int result = tem1 + tem2;

            maxHeap.push(max(tem1,tem2) - min(tem1,tem2));

        }

        return tem1;
    }
};