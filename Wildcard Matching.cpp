#include <iostream>
#include <vector>
#include <string>

bool isMatch(const std::string& s, const std::string& p) {
    int sLen = s.size(), pLen = p.size();
    std::vector<std::vector<bool>> dp(sLen + 1, std::vector<bool>(pLen + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= pLen; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i <= sLen; ++i) {
        for (int j = 1; j <= pLen; ++j) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
    }

    return dp[sLen][pLen];
}

int main() {
    std::string s = "aa";
    std::string p = "a";
    std::cout << std::boolalpha << isMatch(s, p) << std::endl; // Output: false
    return 0;
}
