class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m > n) return -1;

        // Check every possible starting index where needle can fit
        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            // Match characters of needle starting from haystack[i]
            while (j < m && haystack[i + j] == needle[j]) {
                ++j;
            }
            // If all m characters matched, we found the first occurrence
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};