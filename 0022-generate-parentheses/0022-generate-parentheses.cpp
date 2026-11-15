class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string& current, int openCount, int closeCount, int n) {
        // Base case: the string is fully formed when its length reaches 2 * n
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }
        
        // Decision 1: We can always add an opening parenthesis if we haven't reached 'n'
        if (openCount < n) {
            current.push_back('(');
            backtrack(result, current, openCount + 1, closeCount, n);
            current.pop_back(); // backtrack to try the next possibility
        }
        
        // Decision 2: We can add a closing parenthesis ONLY if there are unmatched opening ones
        if (closeCount < openCount) {
            current.push_back(')');
            backtrack(result, current, openCount, closeCount + 1, n);
            current.pop_back(); // backtrack to try the next possibility
        }
    }
};