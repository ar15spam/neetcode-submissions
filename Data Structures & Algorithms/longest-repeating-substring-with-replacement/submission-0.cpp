class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count; 
        int len = s.size(); 
        int l = 0;
        int max = 0; 
        int wmax = 0; 
        for(int r = 0; r < len; r++) {
            count[s[r]]++; 
            max = std::max(max, count[s[r]]); 
            int w = r - l + 1; 
            if(w - max <= k) {
                wmax = std::max(wmax, w);
            } else {
                count[s[l]]--; 
                l++; 
            }
        }
        return wmax; 
    }
};