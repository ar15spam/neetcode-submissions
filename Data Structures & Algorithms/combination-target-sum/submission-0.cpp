class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& subset, int sum, vector<int>& nums, int index, int target) {
        if(sum == target) {
            res.push_back(subset); 
            return; 
        }

        if(index == nums.size() || sum > target) {
            return; 
        }

        sum += nums[index]; 
        subset.push_back(nums[index]); 
        dfs(res, subset, sum, nums, index, target); 
        subset.pop_back(); 
        sum -= nums[index]; 
        dfs(res, subset, sum, nums, index + 1, target); 

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res; 
        vector<int> subset; 
        int sum = 0; 
        int index = 0;

        dfs(res, subset, sum, nums, index, target); 
        
        return res; 
    }
};
