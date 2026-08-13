class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() < 2) {
            return 0; 
        }
        
        int l = 0; 
        int r = 1; 
        int mp = 0; 

        while (r < prices.size()) {
            if (prices[r] < prices[l]) {
                l = r; 
            } else {
                int sum = prices[r] - prices[l]; 
                mp = max(mp, sum); 
            }
            r++; 
        }
        
        return mp; 
    }
};