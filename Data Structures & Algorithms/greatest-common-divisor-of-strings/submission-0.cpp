class Solution {
private: 
    int euclidian(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a; // 'a' holds the last non-zero remainder (the GCD)
    }

public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        int length = euclidian(str1.size(), str2.size()); 
        return str1.substr(0, length);
    }
};