#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0)
            return 0;

        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            if (charIndex.find(s[end]) != charIndex.end() && charIndex[s[end]] >= start) {
                start = charIndex[s[end]] + 1;
            }
            charIndex[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};