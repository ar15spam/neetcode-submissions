class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.size(); 
        int len2 = s2.size(); 
        int l = 0;

        unordered_map<char, int> ex; 
        for(char& c : s1) {
            ex[c]++; 
        }

        unordered_map<char, int> count; 
        for(int r = 0; r < len2; r++) {

            count[s2[r]]++; 

        
            if ((r - l + 1) > len) {
                count[s2[l]]--; 
                if (count[s2[l]] == 0) {
                    count.erase(s2[l]); 
                }
                l++; 
            }
            
            if ((r - l + 1) == len) {
                if (ex == count) {
                    return true; 
                }
            }
        }
    
        return false;
    }
};