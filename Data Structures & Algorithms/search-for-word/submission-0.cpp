#include <vector>
#include <string>

class Solution {
private: 
    bool dfs(std::vector<std::vector<char>>& board, int i, int j, int index, const std::string& word) {
      
        if (index == word.size()) { 
            return true; 
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false; 
        }

        char temp = board[i][j];
        board[i][j] = '#'; 

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (auto& dir : dirs) {
            if (dfs(board, i + dir[0], j + dir[1], index + 1, word)) {
                return true;
            }
        }
        
        board[i][j] = temp; 

        return false;
    }

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int rows = board.size();
        int cols = board[0].size(); 

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }

        return false; 
    }
};