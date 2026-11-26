class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first index 'i' from the right where nums[i] < nums[i + 1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        // Step 2: If a pivot exists, find the smallest element > nums[i] to its right and swap
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix to the right of 'i' to make it the smallest possible order
        reverse(nums.begin() + i + 1, nums.end());
    }
};