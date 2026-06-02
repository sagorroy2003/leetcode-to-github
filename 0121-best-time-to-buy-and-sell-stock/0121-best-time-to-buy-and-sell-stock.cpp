class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.empty()){
            return 0;
        }

        int min_price_seen = prices[0];
        int mx_profit = 0; 

        // for(int today_price = 1; today_price < prices.size(); today_price++){
        //     min_price_seen = min(min_price_seen, prices[today_price]);
        //     mx_profit = max(mx_profit , (prices[today_price] - min_price_seen));
        // }           

        for(auto today_price : prices){
            min_price_seen = min(min_price_seen, today_price);
             mx_profit = max(mx_profit , (today_price - min_price_seen));
        }

        return mx_profit;
    }
};