class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);

        auto backtrack = [&](auto& self) -> void {
            if (curr.size() == nums.size()) {
                res.push_back(curr);
                return;
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (visited[i]) continue;

                visited[i] = true;
                curr.push_back(nums[i]);

                self(self);

                curr.pop_back();
                visited[i] = false; 
            }
        };

        backtrack(backtrack);
        return res;
    }
};