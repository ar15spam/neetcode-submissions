class Solution {
private:
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& subset, int remain, int index) {

        if(remain == 0) {
            res.push_back(subset); 
            return; 
        }

        for(int i = index; i < candidates.size(); i++) {
            if(remain < candidates[i]) {
                break; 
            }

            if(i > index && candidates[i] == candidates[i-1]) {
                continue; 
            }

            subset.push_back(candidates[i]);

            dfs(candidates, res, subset, remain - candidates[i], i + 1);

            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res; 
        vector<int> subset; 
        
        sort(candidates.begin(), candidates.end()); 
        dfs(candidates, res, subset, target, 0); 

        return res; 
    }
};
