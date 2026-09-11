class Solution {

private:
    void dfs(vector<vector<int>>& result, vector<int>& subset, vector<int>& nums, int index) {
        if(index == nums.size()) {
            result.push_back(subset); 
            return; 
        }

        subset.push_back(nums[index]); 
        dfs(result, subset, nums, (index + 1)); 

        subset.pop_back(); 
        dfs(result, subset, nums, (index + 1)); 
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; 
        vector<int> subset; 
        int index = 0; 
        dfs(result, subset, nums, index); 

        return result; 
    }
};
