class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.size();
        int numWords = words.size();
        int wordLen = words[0].size();
        int totalLen = numWords * wordLen;

        if (n < totalLen) return result;

        // Frequency map of the target words
        unordered_map<string, int> wordCount;
        for (const string& w : words) {
            ++wordCount[w];
        }

        // Only wordLen distinct starting alignments exist (0 to wordLen - 1)
        for (int offset = 0; offset < wordLen; ++offset) {
            int left = offset;
            int matchedWords = 0;
            unordered_map<string, int> windowCount;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);

                if (wordCount.count(word)) {
                    ++windowCount[word];
                    ++matchedWords;

                    // Shrink from the left if this word appears more times than required
                    while (windowCount[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        --windowCount[leftWord];
                        --matchedWords;
                        left += wordLen;
                    }

                    // All target words matched with exact frequencies
                    if (matchedWords == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Invalid word breaks any potential concatenation; reset the window
                    windowCount.clear();
                    matchedWords = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};