class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       
       std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());

        std::vector<int> notIn1ButIn2;
        std::vector<int> notIn2ButIn1;

        for (int num : nums2) {
            if (set1.find(num) == set1.end()) {
                if(find(notIn1ButIn2.begin(), notIn1ButIn2.end(), num) != notIn1ButIn2.end()) {
                    continue; 
                }
                notIn1ButIn2.push_back(num);
            }
        }

        for (int num : nums1) {
            if (set2.find(num) == set2.end()) {
                if(find(notIn2ButIn1.begin(), notIn2ButIn1.end(), num) != notIn2ButIn1.end()) {
                    continue; 
                }
                notIn2ButIn1.push_back(num);
            }
        }

        return {notIn2ButIn1, notIn1ButIn2};

    }
};