//https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(); // row length
        int c = matrix[0].size(); // column length
        int low = 0;
        int high = (r*c)-1;
        int mid;
        
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(matrix[mid/c][mid%c] == target) return true;
            else if(matrix[mid/c][mid%c] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};