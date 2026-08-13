class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        
        std::unordered_map<string, std::function<int(int, int)>> operations = {
            {"+", [](int b, int a) { return b + a; }},
            {"-", [](int b, int a) { return b - a; }},
            {"*", [](int b, int a) { return b * a; }},
            {"/", [](int b, int a) { return b / a; }}
        };

        for (auto& piece : tokens) {
            if (operations.count(piece) > 0) {
                int a = st.top(); 
                st.pop(); 
                int b = st.top(); 
                st.pop(); 
                int result = operations[piece](b, a); 
                st.push(result); 
            } else {
                st.push(std::stoi(piece));
            }
        }


        return st.top();
    }
};