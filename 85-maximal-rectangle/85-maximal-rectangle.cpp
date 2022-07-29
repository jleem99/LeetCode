#pragma GCC optimize('Os')
/**
 *
 */

class Solution {
     int largestHistogram(vector<int>& heights) {
        const int n = heights.size();
        stack<int> stk;
        vector<int> left_index(n);
        vector<int> right_index(n);
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            if (stk.empty())
                left_index[i] = -1;
            else
                left_index[i] = stk.top();
            stk.push(i);
        }
        for (; !stk.empty(); stk.pop());
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            if (stk.empty())
                right_index[i] = n;
            else
                right_index[i] = stk.top();
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            const int size = heights[i] * (right_index[i] - left_index[i] - 1);
            if (size > res)
                res = size;
        }

        return res;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m = matrix[0].size();
        const int n = matrix.size();        
        
        vector<vector<int>> heights_matrix(n, vector<int>(m));
        for (int y = n - 1; y >= 0; y--) {
            for (int x = 0; x < m; x++) {
                if (y == n - 1 || matrix[y][x] == '0')
                    heights_matrix[y][x] = matrix[y][x] == '0' ? 0 : 1;
                else
                    heights_matrix[y][x] = heights_matrix[y + 1][x] + 1;
            }
        }
    
        int res = 0;
        for (int y = 0; y < n; y++) {
            const int size = largestHistogram(heights_matrix[y]);
            if (size > res)
                res = size;
        }

        return res;
    }
    
    
};
