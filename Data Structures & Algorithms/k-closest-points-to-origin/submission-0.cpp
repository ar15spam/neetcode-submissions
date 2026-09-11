class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](const vector<int>& p) {
            return p[0] * p[0] + p[1] * p[1];
        };
        
        auto comp = [&dist](const vector<int>& a, const vector<int>& b) {
            return dist(a) < dist(b);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> maxHeap(comp);

        for (const auto& point : points) {
            maxHeap.push(point);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return res;
    }
};