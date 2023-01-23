class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        const auto r = image.size();
        const auto c = image[0].size();
        const auto cc = image[sr][sc];
        queue<pair<int, int>> q;
        if (image[sr][sc] != color) {
            q.emplace(sr, sc);
        }
        while (!q.empty()) {
            auto point = q.front(); q.pop();
            image[point.first][point.second] = color;
            if (point.first > 0 && image[point.first - 1][point.second] == cc) {
                q.emplace(point.first - 1, point.second);
            }
            if (point.second > 0 && image[point.first][point.second - 1] == cc) {
                q.emplace(point.first, point.second - 1);
            }
            if (point.first < r - 1 && image[point.first + 1][point.second] == cc) {
                q.emplace(point.first + 1, point.second);
            }
            if (point.second < c - 1 && image[point.first][point.second + 1] == cc) {
                q.emplace(point.first, point.second + 1);
            }
        }
        return image;
    }
};