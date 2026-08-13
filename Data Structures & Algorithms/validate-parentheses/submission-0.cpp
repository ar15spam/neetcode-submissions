class Solution {
public:
    bool isValid(string s) {

        std::unordered_map<char, char> m = {
            {'(', ')'}, 
            {'[', ']'},
            {'{', '}'}, 
        }; 
        std::stack<char> st; 

        int len = s.size();

        for(int i = 0; i < len; i++) {

            if(st.empty()) {
                st.push(s[i]); 
                continue; 
            }

            char c = st.top();

            if(m[c] == s[i]) {
                st.pop(); 
            } else {
                if(m.count(s[i]) > 0) {
                    st.push(s[i]); 
                } else { 
                    return false; 
                }
            }
        }

        return st.empty(); 
    }
};
