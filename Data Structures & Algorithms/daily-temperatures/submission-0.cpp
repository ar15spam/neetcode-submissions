class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size(); 
        vector<int> v(len, 0);
        stack<int> s; 
        
        for(int i = 0; i < len; i++) {
            while(!s.empty() && temperatures[s.top()] < temperatures[i]) {
                int prevDay = s.top();
                v[prevDay] = i - prevDay; 
                s.pop(); 
            }
            s.push(i); 
        }
        return v; 
    }
};