class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0; 
        int r = 0;
        int min = INT_MAX; 
        int count = 0; 

        while(r < blocks.size()) {

           if(blocks[r] == 'W') {
            count++; 
           } 

           if((r - l) + 1 == k) {
            min = std::min(min, count); 
            if(blocks[l] == 'W') {
                count--;
                
            }
            l++; 
           }

           r++; 
        }

        return min; 
    }
};