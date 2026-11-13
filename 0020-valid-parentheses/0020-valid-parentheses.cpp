#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (char c : s) {
            if (map.count(c)) {
                char topElement = st.empty() ? '#' : st.top();
                if (!st.empty()) st.pop();
                
                if (topElement != map[c]) {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        
        return st.empty();
    }
};