class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        // k tracks the write position for the next unique element
        int k = 1;

        for (int i = 1; i < nums.size(); ++i) {
            // Since the array is sorted, a new unique value differs from the last written one
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                ++k;
            }
        }

        return k;
    }
};