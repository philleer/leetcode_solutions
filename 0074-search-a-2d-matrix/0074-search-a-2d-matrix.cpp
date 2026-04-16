class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || target > matrix.back().back() || target < matrix[0][0]) return false;

        int rows = matrix.size();
        int cols = matrix.back().size();
        int low = 0;
        int high = rows - 1;
        int range_row = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] == target) return true;

            if (matrix[mid][0] > target) {
                if (mid > 0 && matrix[mid - 1][0] <= target) {
                    range_row = mid - 1;
                    break;
                }
                high = mid - 1;
            } else {
                if (mid < rows - 1 && matrix[mid + 1][0] > target) {
                    range_row = mid;
                    break;
                }
                low = mid + 1;
            }
        }
        if (range_row == -1) range_row = rows - 1;

        low = 0;
        high = cols - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[range_row][mid] == target) return true;

            if (matrix[range_row][mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};