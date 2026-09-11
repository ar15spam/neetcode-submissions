class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int c : cost) {
            int current = std::min(prev1 + c, prev2 + c); 
            int next = std::min(prev1, prev2) + c; 
        }
        
        
        int first = 0, second = 0;
        for (int i = 0; i < cost.size(); ++i) {
            int current = cost[i] + min(first, second);
            first = second;
            second = current;
        }
        return min(first, second);
    }
};