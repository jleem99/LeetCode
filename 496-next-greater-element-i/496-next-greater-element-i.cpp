int stk[10000];
int nge[10000];

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> idx_map;
        int stk_size = 0;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (stk_size != 0 && stk[stk_size - 1] <= nums2[i])
                stk[stk_size-- - 1] = 0;

            if (stk_size != 0)
                nge[i] = stk[stk_size - 1];
            else
                nge[i] = -1;
            stk[stk_size++] = nums2[i];
            idx_map[nums2[i]] = nge[i];
        }

        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
            res[i] = idx_map[nums1[i]];
        return res;
    }
};