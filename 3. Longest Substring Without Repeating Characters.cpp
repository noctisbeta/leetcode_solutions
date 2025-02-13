// Hidden code
#include <string>
using namespace std;


// My code
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_set<char> seen = {};
        int l = 0, r = 0;
        char c;
        int current = 0;
        while (r < s.size()) {
            c = s.at(r);
            if (seen.contains(c)) {
                seen.erase(s.at(l));
                l++;
            } else {
                seen.insert(c);
                current = r - l + 1;
                if (current > longest) {
                    longest = current;
                }
                r++;
            }
        }
        return longest;
    }
};
