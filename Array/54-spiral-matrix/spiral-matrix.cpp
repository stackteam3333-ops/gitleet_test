class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;

        // Initialize inclusive boundaries
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        while (left <= right && top <= bottom) {
            // 1. Traverse Right (Top Row)
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++; // Shrink top boundary down

            // 2. Traverse Down (Right Column)
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Shrink right boundary left

            // 3. Traverse Left (Bottom Row)
            if (top <= bottom) { // Check to prevent duplicate row traversal
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // Shrink bottom boundary up
            }

            // 4. Traverse Up (Left Column)
            if (left <= right) { // Check to prevent duplicate column traversal
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Shrink left boundary right
            }
        }

        return ans;
    }
};
