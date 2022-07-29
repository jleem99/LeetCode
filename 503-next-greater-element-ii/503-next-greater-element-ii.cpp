int stk[10000];

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res(n);
        int stk_size = 0;
        
        for (int i = 2*n - 1; i >= 0; i--) {
            while (stk_size != 0 && stk[stk_size - 1] <= nums[i%n])
                stk[stk_size-- - 1] = 0;

            if (i < n) {
                if (stk_size != 0)
                    res[i] = stk[stk_size - 1];
                else
                    res[i] = -1;
            }
            stk[stk_size++] = nums[i%n];
        }

        return res;
    }
};