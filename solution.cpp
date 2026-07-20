#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int maxLen = 0;
        std::vector<int> stack = {-1};

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else {
                stack.pop_back();
                if (stack.empty()) {
                    stack.push_back(i);
                } else {
                    maxLen = std::max(maxLen, i - stack.back());
                }
            }
        }

        return maxLen;
    }
};

int main() {
    Solution solution;
    std::cout << solution.longestValidParentheses("(()") << std::endl;
    std::cout << solution.longestValidParentheses(")()())") << std::endl;
    std::cout << solution.longestValidParentheses("") << std::endl;
    return 0;
}