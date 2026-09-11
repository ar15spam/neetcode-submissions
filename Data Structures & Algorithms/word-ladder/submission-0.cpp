#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<string, vector<string>> edges;

    Graph(vector<string>& wordList) {
        for (string& word : wordList) {
            string pattern = word;

            for (int i = 0; i < pattern.size(); i++) {
                char temp = pattern[i];

                pattern[i] = '*';

                edges[pattern].push_back(word);

                pattern[i] = temp;
            }
        }
    }
};

class Solution {
public:
    int ladderLength(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        Graph g(wordList);

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({beginWord, 1});
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [curr, count] = q.front();
            q.pop();

            if (curr == endWord) {
                return count;
            }

            string pattern = curr;

            for (int i = 0; i < pattern.size(); i++) {
                char temp = pattern[i];

                pattern[i] = '*';

                for (string& neighbor : g.edges[pattern]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);

                        q.push({
                            neighbor,
                            count + 1
                        });
                    }
                }

                pattern[i] = temp;
            }
        }

        return 0;
    }
};