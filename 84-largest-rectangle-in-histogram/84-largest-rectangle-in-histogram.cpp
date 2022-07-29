class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};